# OpenOCD 配置文件搜索路径修复说明

## 问题现象

烧录时 OpenOCD 报错：

```
embedded:startup.tcl:26: Error: Can't find target/as32x601_eflash.cfg
```

## 原因分析

OpenOCD 通过 `-f target/as32x601_eflash.cfg` 加载配置文件时，会在**搜索路径列表**中逐一查找。搜索路径由 `src/helper/options.c` 中的 `add_default_dirs()` 函数构建，原有逻辑如下：

1. `$OPENOCD_SCRIPTS` 环境变量（未设置）
2. `~/.openocd/` 用户目录（不存在该文件）
3. `<exe_dir>/<bin2data>/site`
4. `<exe_dir>/<bin2data>/scripts`

其中第 3、4 步的 `bin2data` 由编译时常量 `BINDIR` 和 `PKGDATADIR` 计算得出：

```c
char *bin2data = find_relative_path(BINDIR, PKGDATADIR);
// BINDIR = "/mingw64/bin"         (编译时 ./configure 决定)
// PKGDATADIR = "/mingw64/share/openocd"  (编译时 ./configure 决定)
```

**编译时的安装路径是 `/mingw64/`，但实际部署路径是 `C:\Users\liuch\.eide\tools\openocd\`。** 两者不一致，导致 `find_relative_path()` 算出的相对路径拼接后指向了一个不存在的目录，`scripts/target/as32x601_eflash.cfg` 自然无法被找到。

## 修复方案

在 `src/helper/options.c` 的 `add_default_dirs()` 函数末尾，新增一条兜底搜索路径：

```c
/* Fallback: always try <exe_dir>/../scripts as a search path,
 * in case BINDIR/PKGDATADIR don't match the actual deployment layout. */
path = alloc_printf("%s/../scripts", exepath);
if (path) {
    add_script_search_dir(path);
    free(path);
}
```

## 修复后的搜索路径

| 顺序 | 搜索路径 | 来源 |
|------|---------|------|
| 1 | `$OPENOCD_SCRIPTS` | 环境变量 |
| 2 | `~/.openocd/` | 用户目录 |
| 3 | `<exe_dir>/<bin2data>/site` | 编译时常量计算 |
| 4 | `<exe_dir>/<bin2data>/scripts` | 编译时常量计算 |
| **5** | **`<exe_dir>/../scripts`** | **新增兜底路径** |

当 `openocd.exe` 位于 `C:\Users\liuch\.eide\tools\openocd\bin\` 时，第 5 步会解析为：

```
C:\Users\liuch\.eide\tools\openocd\bin\..\scripts
= C:\Users\liuch\.eide\tools\openocd\scripts\
```

该目录下存在 `target/as32x601_eflash.cfg`，因此文件能被正确找到。

## 修改的文件

- `e:/Projects/openocd_riscv/src/helper/options.c` — `add_default_dirs()` 函数
