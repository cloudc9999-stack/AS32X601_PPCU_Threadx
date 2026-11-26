1，编辑器平台选择VSCode EIDE编辑；

2，MCU芯片选择AS32x601 32位RISC-V架构MCU，MCU的时钟频率为180MHz，内存大小为512KB，Flash大小为2MB；

3，Threadx系统，启动程序以及上下文切换汇编在Startup文件夹中；

4，tick源头选择mTIME，更新CLINT计数器实现在Threadx_ports/inc/CLINT_Config.h文件中，在Startup/as32x601_trapentry_gcc.s调用；

