#ifndef __THREAD_UI_H__
#define __THREAD_UI_H__

#include "sys.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

/**************************** global varible ******************************/

/**************************** macro definition ******************************/

/**************************** macro definition ******************************/

//thread ui task
#define THREAD_UI_PRIO 3 //�������ȼ�
#define THREAD_UI_STK_SIZE 128 //�����ջ��С
extern TaskHandle_t Thread_UI_Handler; //������
void thread_ui_entry(void *pvParameters); //������

#endif

