#ifndef __LED1_THREAD_H__
#define __LED1_THREAD_H__
#include "sys.h"
#include "FreeRTOS.h"
#include "task.h"

/**************************** global varible ******************************/

/**************************** macro definition ******************************/

/**************************** macro definition ******************************/


/**************************** ����B520��Ŀ����� FreeRTOS ģ���������ع� **********************************/
/*
* B520��ʼ����������ķ���������ȫ�ֱ��������ҳ�ʼ����ÿһ��������һ��������ƿ�Ľṹ����
* �����ڹ���������ֻ��Ҫ����: led0_thread->init() ����
* ���ʵ���˴���֮��ĵ���ϣ� ���ھ�
*/
//led1���� ��صĺ궨��

#define LED1_TASK_PRIO		3 //�������ȼ�
#define LED1_STK_SIZE 		50   //�����ջ��С	
extern TaskHandle_t LED1Task_Handler; //�������� ȫ�ֱ���
void led1_task(void *pvParameters); //������


#endif // end __LED1_THREAD_H__

