#include "led0_thread.h"
#include "semphr.h"
#include "str_operation.h"
#include "command_parse.h"
#include "usart.h"  //��Ҫ�õ������е�ȫ�ֱ���
//#include "timer.h"
/**************************** global varible ******************************/
extern SemaphoreHandle_t BinarySemaphore;      //��ֵ�ź���

/**************************** macro definition ******************************/

/**************************** macro definition ******************************/


//LED0������
TaskHandle_t LED0Task_Handler;

//LED1������ں���
void led0_task(void *pvParameters)
{
    uint8_t len = 0;
    uint8_t CommandVal = COMMAND_ERR;
    uint8_t *pCommandStr;
    while(1)
    {
        // LED0=~LED0;
		// //������ʱ����500 ms ���Ǹ��� FreeRTOSConfig.h ��������������
		// //#define configTICK_RATE_HZ						(1000)   
		// //����500�Σ� ����500ms
        // printf("%s running..\r\n", __func__);
        // vTaskDelay(500);		//��ʱ����ǰ�����������̬�������������������

        //
        // ������ dual_comm �̵߳����ݽ��н���
        //
        // uint8_t err;
        // if(BinarySemaphore != NULL)
        // {
        //     err = xSemaphoreTake(BinarySemaphore, portMAX_DELAY);
        //     if(err == pdTRUE)
        //     {
                
        //     }
        // }
    }
	//return;					//������˵ִ�в�������
} 


