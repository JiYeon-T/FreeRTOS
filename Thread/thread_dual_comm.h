#ifndef __THREAD_DUAL_COMM_H__
#define __THREAD_DUAL_COMM_H__
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"

/**************************** global varible ******************************/
extern xQueueHandle Dual_Comm_Queue;          //���о��
extern SemaphoreHandle_t BinarySemaphore;      //��ֵ�ź���
/**************************** macro definition ******************************/
#define DUAL_COMM_Q_SIZE            256     //���д�С

/**************************** macro definition ******************************/

//dual_comm Task
#define DUAL_COMM_TASK_PRIO 4         //�������ȼ�
#define DUAL_COMM_STK_SIZE 128        //�����ջ��С
extern TaskHandle_t DualCommTask_Handler;   //������
void dual_comm_task(void *pvParameters); //������


#endif // end __THREAD_DUAL_COMM_H__

