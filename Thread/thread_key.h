#ifndef __THREAD_KEY_H__
#define __THREAD_KEY_H__

#include "FreeRTOS.h"
#include "task.h"
#include "key.h"

/**************************** global varible ******************************/

/**************************** macro definition ******************************/

/**************************** macro definition ******************************/

//Key Task
#define KEY_TASK_PRIO 2         //�������ȼ�
#define KEY_STK_SIZE 128        //�����ջ��С
extern TaskHandle_t KeyTask_Handler;   //������
void key_task(void *pvParameters); //������

#endif //end __THREAD_KEY_H__

