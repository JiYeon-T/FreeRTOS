#include "interrupt_thread.h"

#include "delay.h"
#include "led.h"
#include "thread_ui.h"

//
// task Handler
//
TaskHandle_t INTERRUPTTask_Handler;

/**
 * @brief interrupt task entry function
 * 
 * @param pvParameters 
 */
void interrupt_task(void *pvParameters)
{
	static u32 total_num=0;
	//resource_init()
	//hardware_init()
	//software_init()
	//other init
	
    while(1)
    {
		total_num += 1;
		//printf("\r\nconfigMAX_SYSCALL_INTERRUPT_PRIORITY = %d\r\n", configMAX_SYSCALL_INTERRUPT_PRIORITY);						

		if(total_num % 10 == 0) 
		{
			printf("close interrupt.............\r\n");
			LED0 = 0;
            //close interrupt
			//���� configMAX_SYSCALL_INTERRUPT_PRIORITY �жϱ�����, �޷�ִ��
			//�ر��ж�֮��֮�����ȼ����� configMAX_SYSCALL_INTERRUPT_PRIORITY ���жϲ��ᱻ����
			portDISABLE_INTERRUPTS();           
			delay_xms(5000);
			// printf("\r\nconfigMAX_SYSCALL_INTERRUPT_PRIORITY = %d\r\n", configMAX_SYSCALL_INTERRUPT_PRIORITY);						
			printf("open interrupt.............\r\n");
            //open interrupt

			portENABLE_INTERRUPTS();
			//ɾ�� UI �߳�
			//vTaskDelete(Thread_UI_Handler);
			printf("delete ui thread.\r\n");
		}
        LED0 = 1;
        vTaskDelay(1000);
    }
} 

