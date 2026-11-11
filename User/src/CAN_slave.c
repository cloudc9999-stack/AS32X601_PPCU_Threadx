/*
 *      Author: cloudc
 *
 * 
 * 
*/
/* ==================== 头文件包含 ==================== */
#include "main.h"
#include "tx_api.h"
#include "CAN_slave.h"
/* ==================== 静态变量声明 ==================== */
extern uint32_t SN;
CAN_CG_typedef CG_handle = {
    .CG_slave_status = 0,
};

TX_TIMER CG_sys_status_timer;

/* ==================== 私有函数声明 ==================== */
static uint32_t AP_CAN_ConnectionManagment(uint32_t *input, uint8_t *send_data, uint32_t data_DLC);
static uint32_t AP_CAN_ControlCommand(uint32_t *input, uint8_t *send_data, uint32_t data_DLC);
static void AP_CG_SlaveStatus(uint32_t status);

/* ==================== 应用层APP初始化函数 ==================== */

/* ==================== 应用层APP任务函数 ==================== */
/*
    说明：外部CAN线程调用函数
         命令分发
         
*/
uint32_t AP_CAN_Slave(uint32_t *input, uint8_t *send_data, uint32_t data_DLC)
{
    uint32_t DLC = 0;
    uint8_t cmd_type = (uint8_t)(input[0] >> 24);
    switch (cmd_type)
    {
    // 连接管理类
    case 0x01:
            DLC = AP_CAN_ConnectionManagment(input, send_data, data_DLC);           
        break;
    // 应答类
    case 0x02:
        {
            
        }
    break;
    // 数据读写类
    case 0x03:

    break;
    // 控制命令类
    case 0x04:
    
        DLC = AP_CAN_ControlCommand(input, send_data, data_DLC);

    break;
    // 诊断维护类
    case 0x05:

    break;
    // 异常通知类
    case 0x06:

    break;
    default:
        break;
    }
    return DLC;
}

/*
    连接管理类
*/
uint32_t AP_CAN_ConnectionManagment(uint32_t *input, uint8_t *send_data, uint32_t data_DLC)
{
    uint32_t DLC = 0;
    uint8_t cmd_operation = (uint8_t)(input[0] >> 16);
    switch (cmd_operation)
    {
        // 连接请求，使用连接应答回应
    case 0x01:
    {
        send_data[0] = 0x01;
        send_data[1] = 0x02;
        send_data[2] = 0x00;
        send_data[3] = 0x00;
        send_data[4] = (uint8_t)(SN >> 24);
        send_data[5] = (uint8_t)(SN >> 16);
        send_data[6] = (uint8_t)(SN >> 8);
        send_data[7] = (uint8_t)(SN >> 0);
        DLC = 8;
        CG_handle.CG_slave_status = 1;
    }
        break;
        // 心跳
    case 0x03:
    {
        send_data[0] = 0x01;
        send_data[1] = 0x03;
        DLC = 2;
    }
    break;
    case 0x04:
    {
        CG_handle.CG_slave_status = 0;
    }
    break;
    default:
        break;
    }
    return DLC;
}
/*

*/
uint32_t AP_CAN_ControlCommand(uint32_t *input, uint8_t *send_data, uint32_t data_DLC)
{
    uint32_t DLC = 0;
    uint8_t cmd_operation = (uint8_t)(input[0] >> 16);
    uint8_t cmd_1 = (uint8_t)(input[0] >> 8);
    uint8_t cmd_2 = (uint8_t)(input[0] >> 0);
    switch (cmd_operation)
    {
        // 启动/停止
    case 0x01:
    {
        if(data_DLC == 4)
        {
            // 自锁阀1
            if(cmd_1 == 0x01)
            {
                if(cmd_2 == 0x01)
                {
                    //开启自锁阀1
                    printf("开启自锁阀\r\n");
                    
                }else if(cmd_2 == 0x00)
                {
                    //关闭自锁阀1
                    printf("关闭自锁阀\r\n");
                }
            }
            send_data[0] = 0x02;
            send_data[1] = 0x01;
            DLC = 2;
        }
    }
        break;
        // 模式切换
    case 0x02:

    break;
        // 参数下发
    case 0x03:
    {
        if(data_DLC == 8)
        {
            if(cmd_1 == 0x01)
            {
                printf("设置第一个电磁阀占空比为:%lu.%lu\r\n", input[1]/10, input[1]%10);
            }else if(cmd_1 == 0x02)
            {
                printf("设置第二个电磁阀占空比为:%lu.%lu\r\n", input[1]/10, input[1]%10);
            }else if(cmd_1 == 0x03)
            {
                printf("设置第三个电磁阀占空比为:%lu.%lu\r\n", input[1]/10, input[1]%10);
            }else if(cmd_1 == 0x04)
            {
                printf("设置第四个电磁阀占空比为:%lu.%lu\r\n", input[1]/10, input[1]%10);
            }else{
                DLC = 0;
                return DLC; 
            }
            send_data[0] = 0x02;
            send_data[1] = 0x01;
            DLC = 2;
        }
    }
    break;
    default:
        break;
    }
    return DLC;
}
/* ==================== 中断回调服务函数 ==================== */
/*
    系统连接上位机状态更新函数
*/
void AP_CG_SlaveStatus(uint32_t status)
{
    if(status != 1)
    {
        CG_handle.CG_slave_status = 0;
    }else{
        CG_handle.CG_slave_status = 1;
    }
}
/*
    储供系统自锁阀状态函数
*/
void AP_CG_SelfLockingValve(uint32_t status)
{

}


