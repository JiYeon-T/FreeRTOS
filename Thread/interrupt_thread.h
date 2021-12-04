#ifndef __INTERRUPT_THREAD_H__
#define __INTERRUPT_THREAD_H__
#include "FreeRTOS.h"
#include "task.h"

//��ʵ�ֹ���, �����ٿ��Ǵ��������, ����չ�Ե�����
#define INTERRUPT_TASK_PRIO		        2
#define INTERRUPT_STK_SIZE 		        256  
extern TaskHandle_t INTERRUPTTask_Handler;  //global thread handler declaration
void interrupt_task(void *p_arg);

#endif //end __INTERRUPT_THREAD_H__

