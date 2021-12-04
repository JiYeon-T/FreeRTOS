#include "interrupt_thread.h"

#include "delay.h"
#include "led.h"


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
    while(1)
    {
		total_num += 1;
		printf("\r\nconfigMAX_SYSCALL_INTERRUPT_PRIORITY = %d\r\n", configMAX_SYSCALL_INTERRUPT_PRIORITY);						

		if(total_num % 5 == 0) 
		{
			printf("close interrupt.............\r\n");
            //close interrupt
			//�ر��ж�֮��֮�����ȼ����� configMAX_SYSCALL_INTERRUPT_PRIORITY ���жϲ��ᱻ����
			portDISABLE_INTERRUPTS();           
			delay_xms(5000);
			// printf("\r\nconfigMAX_SYSCALL_INTERRUPT_PRIORITY = %d\r\n", configMAX_SYSCALL_INTERRUPT_PRIORITY);						
			printf("open interrupt.............\r\n");
            //open interrupt
			portENABLE_INTERRUPTS();
		}
        LED0 =~ LED0;
        vTaskDelay(1000);
    }
} 

