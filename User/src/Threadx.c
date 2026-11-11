/*
 *      Author: cloudc
 *      
 * 
 * 
*/
/* ==================== 头文件包含 ==================== */
#include "tx_api.h"
#include "main.h"    
#include "adc.h"
#include "app.h"

#define MSG_SIZE_1                  1U
#define QUEUE_SIZE_5                5U
/* ==================== 静态变量声明 ==================== */

// 任务控制块结构体
static TX_THREAD sysPrintfMessage_thread;
static TX_THREAD clear_thread;
// 任务栈数组
static ULONG sysPrintfMessage_stack[256];
static ULONG clear_thread_stack[256];
// 队列结构体
static TX_QUEUE delete_queue;
// 队列内存
static ULONG delete_queue_memory[8];
/* ==================== 私有函数声明 ==================== */

static void sysPrintfMessage(ULONG thread_input);
static void Cleaner_Thread(ULONG thread_input);
/* ==================== 应用层APP初始化函数 ==================== */
void tx_application_define(void *first_unused_memory)
{

    tx_thread_create(&app_thread, "app_thread", 
                    APP_Thread, 0,
                    app_thread_stack, sizeof(app_thread_stack),
                    0, 0, TX_NO_TIME_SLICE, TX_AUTO_START);        
    tx_thread_create(&sysPrintfMessage_thread, "sysPrintfMessage_thread",
                    sysPrintfMessage, 0,
                    sysPrintfMessage_stack, sizeof(sysPrintfMessage_stack),
                    4, 4, TX_NO_TIME_SLICE, TX_AUTO_START);
    tx_thread_create(&clear_thread, "Cleaner_Thread",
                    Cleaner_Thread, 0,
                    clear_thread_stack, sizeof(clear_thread_stack),
                    5, 5, TX_NO_TIME_SLICE, TX_AUTO_START);   
    tx_queue_create(&delete_queue, "delete_queue", 1, delete_queue_memory, sizeof(delete_queue_memory));
}
/* ==================== 任务管理器 ==================== */
void Cleaner_Thread(ULONG thread_input)
{
    TX_THREAD *thread_to_delete;
    while(1)
    {
        if(tx_queue_receive(&delete_queue, &thread_to_delete, TX_WAIT_FOREVER) == TX_SUCCESS)
        {
            tx_thread_sleep(2);
            tx_thread_delete(thread_to_delete);
            printf("清理任务！%p\r\n", thread_to_delete);
        }
    }
}
/* ==================== Thread函数 ==================== */


void sysPrintfMessage(ULONG thread_input)
{
    printf("\r\n===== PPCU V1.0 =====\r\n");
    printf("系统初始化完成\r\n");
    printf("====================\r\n"); 
    tx_thread_terminate(&sysPrintfMessage_thread);
    while(1);
}
/* ==================== Config函数 ==================== */





/* ==================== 中断回调服务函数 ==================== */





