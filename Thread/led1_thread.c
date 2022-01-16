#include "led1_thread.h"
#include "led.h"
#include "event_groups.h"
#include "thread_manager.h"

/**************************** task info ******************************/
TaskHandle_t LED1Task_Handler; //LED0������

/**************************** global varible ******************************/
extern EventGroupHandle_t manager_event_group; //�¼���־��, ��������һ������/�¼���������/�¼�����ͬ��

/**************************** macro definition ******************************/

/**************************** macro definition ******************************/


/**
 * @brief hardware_init
 * 
 */
static void hardware_init()
{
    LED1 = 1;
}

/**
 * @brief software_init
 * 
 */
static void software_init()
{
    // //֪ͨ�����̳߳�ʼ�� -> ͨ��ʹ������֪ͨʵ��
    // //���ñ�־λ
    // xEventGroupSetBits(manager_event_group, TASK_SYNC);
}

/**
 * @brief resource_init
 * 
 */
static void resource_init()
{
    
}

//LED1������ں���
void led1_task(void *pvParameters)
{
    hardware_init();
    resource_init();
    software_init();

    while(1)
    {
        // printf("%s running..\r\n", __func__);
        // LED1=0;
        // vTaskDelay(2000);		//��ʱ����ǰ�����������̬�������������������
        // LED1=1;
        // vTaskDelay(2000);

        // ��Ϣ�����߳������ȴ��¼�
        xEventGroupWaitBits(manager_event_group, TASK_SYNC, pdTRUE, pdTRUE, portMAX_DELAY);
        LED1 = ~LED1;
        printf("LED1 thread got a sync bit.\r\n");
    }
	//return;					//������˵ִ�в�������
}
