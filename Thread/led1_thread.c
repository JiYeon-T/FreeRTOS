#include "led1_thread.h"
#include "led.h"

/**************************** global varible ******************************/

/**************************** macro definition ******************************/

/**************************** macro definition ******************************/

//LED1������
TaskHandle_t LED1Task_Handler;

//LED1������ں���
void led1_task(void *pvParameters)
{
    while(1)
    {
        printf("%s running..\r\n", __func__);
        LED1=0;
        vTaskDelay(2000);		//��ʱ����ǰ�����������̬�������������������
        LED1=1;
        vTaskDelay(2000);

    }
	//return;					//������˵ִ�в�������
}
