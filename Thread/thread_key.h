#ifndef __THREAD_KEY_H__
#define __THREAD_KEY_H__

#include "FreeRTOS.h"
#include "task.h"
#include "key.h"
#include "queue.h"
#include "semphr.h"
#include "event_groups.h"
/**************************** task info ******************************/
#define KEY_TASK_PRIO 5         //�������ȼ�
#define KEY_STK_SIZE 128        //�����ջ��С
extern TaskHandle_t KeyTask_Handler;   //������
void key_task(void *pvParameters); //������

/**************************** global varible ******************************/
extern xQueueHandle Key_Queue;          //��Ϣ���о��
extern xSemaphoreHandle key_sema;      //�������ź���
/**************************** macro definition ******************************/
//queue size
#define KEY_Q_SIZE   20

/**************************** macro definition ******************************/

//Key Task


#endif //end __THREAD_KEY_H__

