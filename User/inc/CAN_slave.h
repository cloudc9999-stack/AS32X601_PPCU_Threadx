/*
 *      Author: cloudc
 *
 * 
 * 
*/
/* ==================== 头文件包含 ==================== */

/* ==================== 静态变量声明 ==================== */
typedef struct 
{
    uint8_t CG_slave_status;
    uint8_t CG_SelfLockingValve;
    // [bit16]: 1-> 开; 0-> 关
    // [15:0]: 占空比
    uint32_t CG_SolenoidValve;            
    uint32_t CG_PressureSensor;
}CAN_CG_typedef;
extern CAN_CG_typedef CG_handle;
/* ==================== 私有函数声明 ==================== */

/* ==================== 应用层APP初始化函数 ==================== */
uint32_t AP_CAN_Slave(uint32_t *input, uint8_t *send_data, uint32_t data_DLC);
/* ==================== 应用层APP任务函数 ==================== */
