/**
 * @file thread_monitor.c
 * @author your name (you@domain.com)
 * @brief ���� AT ����ȵ��߳�, FI �����
 * @version 0.1
 * @date 2021-12-01
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "thread_monitor.h"
#include "sys.h"
#include "str_operation.h"
#include "string.h"
#include "usart.h"
//#include "memory.h"
#include "led.h"
#include "beep.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief ����ʹ��һ���ṹ��(��)��ÿһ���������Щ��Դ���й���
 *        ���ڿ����޸�
 */
/**************************** task info ******************************/
StackType_t ThreadMonitorStack[THREAD_MONITOR_STK_SIZE]; //�����ջ
StaticTask_t ThreadMonitorTCB;             //������ƿ�
TaskHandle_t ThreadMonitor_Handler;        //������
SemaphoreHandle_t monitor_binary_handle;    //��ֵ�ź���

/**************************** global varible ******************************/


/**************************** macro definition ******************************/
//�����������
#define LED1ON          1
#define LED1OFF         2
#define BEEPON          3
#define BEEPOFF         4
#define COMMAND_ERR     0xFF

/**************************** macro definition ******************************/
static void hardware_init()
{

}

static void software_init()
{
   
}

static void resource_init()
{
    monitor_binary_handle = xSemaphoreCreateBinary();
}

/**
 * @brief monitor thread entry
 * 
 * @param pvParameters 
 */
void thread_monitor_enery(void *pvParameters)
{
    BaseType_t ret = pdFALSE;
    uint8_t len = 0;    //���յ����ݳ���
    uint8_t cmdVal = COMMAND_ERR;
    //uint8_t *cmdStr = NULL; //ָ����յ����ݵ�ָ��
    uint8_t cmdStr[256];
    
    hardware_init();
    resource_init();
    software_init();
    while(1)
    {
        printf("thread_moonitor running...");
        vTaskDelay(1000);
        /*if(monitor_binary_handle != NULL)
        {
            //
            // �����ȴ��ź���
            //
            ret = xSemaphoreTake(monitor_binary_handle, portMAX_DELAY);
            if(ret == pdTRUE)
            {
                len = USART_RX_STA & 0x3FFF;
                //
                // һ��̬�����ڴ�ͱ�:ʲô�������Ĵ���
                //
                //cmdStr = (uint8_t*)malloc(len + 1);   //�ַ�����β '\0'
                sprintf((char*)cmdStr, "%s", USART_RX_BUF); //��ʽת��Ϊ�ַ���
                cmdStr[len] = '\0';
                LowerToCapital(cmdStr, len);
                cmdVal = CommandParse((char*)cmdStr);  //�������
                if(cmdVal != COMMAND_ERR)
                {
                    //
                    // �� GUI �̶߳�������Ϣ
                    //
                    //printf("cmd:%d", cmdVal);
                }
                else
                {

                }

                //
                // �������������Ӧ����
                //
                switch(cmdVal)
                {
                    case LED1ON:
                        LED1 = 1;
                        break;
                    case LED1OFF:
                        LED1 = 0;
                        break;
                    case BEEPON:
                        BEEP = 1;
                        break;
                    case BEEPOFF:
                        BEEP = 0;
                        break;
                    default:
                        break;
                }
                USART_RX_STA = 0;
                memset(USART_RX_BUF, 0, USART_REC_LEN); //���㻺����
                free(cmdStr);
            }
            else
            {
                vTaskDelay(10); //�ȴ� 10 ������
            }
        }*/
    }
}

/**
 * @brief �����������
 * 
 * @param str �����ַ���
 */
uint8_t CommandParse(char *str)
{
    uint8_t cmdVal = COMMAND_ERR;
    if( strcmp((char*)str, "LED1ON") == 0){
        cmdVal = LED1ON;
    }
    else if(strcmp((char*)str, "LED1OFF") == 0){
        cmdVal = LED1OFF;
    }
    else if(strcmp((char*)str, "BEEPON") == 0){
        cmdVal = BEEPON;
    }
    else if(strcmp((char*)str, "BEEPOFF") == 0){
        cmdVal = BEEPOFF;
    }
    else{
        //printf("unknow cmd:%s", str);
    }

    return cmdVal;
}

//AT ��������ǽ��ַ����ŵ�һ������, ����Ԫ�� char*, pFun
// typedef void (*pFun)(const char *para1, const char *para2);
// typedef struct 
// {
//     char *cmd;
//     pFun fun;
// };

// typedef void (*pFun)(void);
// {
//     .init = pFun;
//     .deinit = deinit;
// }
