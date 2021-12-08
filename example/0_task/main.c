#include "main.h"

/************************* FreeRTOS ��ܴ���Ժ󣬽��м򵥲��� *******************/
int main(void)
{
    hardware_init();
	software_init();

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






