#include "led0_thread.h"
#include "str_operation.h"
#include "command_parse.h"
#include "usart.h"  //��Ҫ�õ������е�ȫ�ֱ���
#include "event_groups.h"
#include "thread_manager.h"
//#include "timer.h"
/**************************** task info ******************************/
TaskHandle_t LED0Task_Handler; //LED0������

/**************************** global varible ******************************/
extern SemaphoreHandle_t BinarySemaphore;      //��ֵ�ź��� -> �ᵼ��"���ȼ���ת", ʹ�û����ź���
extern xSemaphoreHandle key_sema;      //�������ź���
extern EventGroupHandle_t manager_event_group; //�¼���־��, ��������һ������/�¼���������/�¼�����ͬ��

/**************************** macro definition ******************************/

/**************************** macro definition ******************************/

/**
 * @brief hardware_init
 * 
 */
static void hardware_init()
{
    LED0 = 0;
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
void led0_task(void *pvParameters)
{
    uint8_t len = 0;
    uint8_t CommandVal = COMMAND_ERR;
    uint8_t *pCommandStr;
    uint8_t semaCnt;
    hardware_init();
    resource_init();
    software_init();

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

        //
        //������ȡ�������ź���
        //
        // xSemaphoreTake(key_sema, portMAX_DELAY);
        // semaCnt = uxSemaphoreGetCount(key_sema);
        // printf("led thread take semapthore, sema cnt:%d", semaCnt);

        // ��Ϣ�����߳������ȴ��¼�
        xEventGroupWaitBits(manager_event_group, TASK_SYNC, pdTRUE, pdTRUE, portMAX_DELAY);
        LED0 = ~LED0;
        printf("LED0 thread got a sync bit.\r\n");
        
    }
	//return;					//������˵ִ�в�������
} 


