#include "led0_thread.h"
#include "led.h"

//LED0������
TaskHandle_t LED0Task_Handler;

//LED1������ں���
void led0_task(void *pvParameters)
{
    while(1)
    {
        LED0=~LED0;
		//������ʱ����500 ms ���Ǹ��� FreeRTOSConfig.h ��������������
		//#define configTICK_RATE_HZ						(1000)   
		//����500�Σ� ����500ms
        printf("%s running..\r\n", __func__);
        vTaskDelay(500);		//��ʱ����ǰ�����������̬�������������������
    }
	return;					//������˵ִ�в�������
} 


