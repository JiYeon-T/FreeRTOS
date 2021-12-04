#include "main.h"

/************************* FreeRTOS ��ܴ���Ժ󣬽��м򵥲��� *******************/
int main(void)
{
	//����ϵͳ�ж����ȼ�����4��	
	//0-15 �ܹ�16�����ȼ���û����ռ���ȼ�	 	 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
	delay_init();	    				//��ʱ������ʼ��	  
	uart_init(115200);					//��ʼ������
	LED_Init();		  					//��ʼ��LED
    TIM3_Int_Init(10000-1,7200-1);		
	TIM5_Int_Init(10000-1,7200-1);		
    
	//������ʼ����
	xTaskCreate((TaskFunction_t )start_task,            //������ں���
				(const char*    )"start_task",          //��������
				(uint16_t       )START_STK_SIZE,        //�����ջ��С
				(void*          )NULL,                  //���ݸ��������Ĳ���
				(UBaseType_t    )START_TASK_PRIO,       //�������ȼ�
				(TaskHandle_t*  )&StartTask_Handler);   //������              
	vTaskStartScheduler();          //�����������
				
	return 0;		//������˵ִ�в�������
}


//��ʼ������ں���
void start_task(void *pvParameters)
{
    taskENTER_CRITICAL();           //�����ٽ���,�ٽ�δ��뱣��
    // //����LED0����
    // xTaskCreate((TaskFunction_t )led0_task,     	
    //             (const char*    )"led0_task",   	
    //             (uint16_t       )LED0_STK_SIZE, 
    //             (void*          )NULL,				
    //             (UBaseType_t    )LED0_TASK_PRIO,	
    //             (TaskHandle_t*  )&LED0Task_Handler);   
    // //����LED1����
    // xTaskCreate((TaskFunction_t )led1_task,     
    //             (const char*    )"led1_task",   
    //             (uint16_t       )LED1_STK_SIZE, 
    //             (void*          )NULL,
    //             (UBaseType_t    )LED1_TASK_PRIO,
    //             (TaskHandle_t*  )&LED1Task_Handler); 

    xTaskCreate((TaskFunction_t )interrupt_task,     
                (const char*    )"interrupt_task",   
                (uint16_t       )INTERRUPT_STK_SIZE, 
                (void*          )NULL,
                (UBaseType_t    )INTERRUPT_TASK_PRIO,
                (TaskHandle_t*  )&INTERRUPTTask_Handler); 
    //
    // �������˳� while(1) ʱ, һ��Ҫɾ������
    //      
    vTaskDelete(StartTask_Handler); //ɾ����ʼ����
    taskEXIT_CRITICAL();            //�˳��ٽ���
	
	return;
}




