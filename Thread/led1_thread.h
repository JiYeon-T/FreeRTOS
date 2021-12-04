#ifndef __LED1_THREAD_H__
#define __LED1_THREAD_H__
#include "sys.h"
#include "FreeRTOS.h"
#include "task.h"

/**************************** ����B520��Ŀ����� FreeRTOS ģ���������ع� **********************************/
/*
* B520��ʼ����������ķ���������ȫ�ֱ��������ҳ�ʼ����ÿһ��������һ��������ƿ�Ľṹ����
* �����ڹ���������ֻ��Ҫ����: led0_thread->init() ����
* ���ʵ���˴���֮��ĵ���ϣ� ���ھ�
*/
//led1���� ��صĺ궨��
//�������ȼ�
#define LED1_TASK_PRIO		3
//�����ջ��С	
#define LED1_STK_SIZE 		50  
//�������� ȫ�ֱ���
extern TaskHandle_t LED1Task_Handler;
//������
void led1_task(void *pvParameters);


#endif // end __LED1_THREAD_H__

