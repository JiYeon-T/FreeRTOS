#ifndef __MAIN_H__
#define __MAIN_H__

#include "delay.h"
#include "sys.h"
#include "FreeRTOS.h"		//�����FreeRTOS.h ���� task.h �ļ���ǰ�����
#include "task.h"




/**************************** global varible ******************************/

/**************************** macro definition ******************************/

/**************************** function declaration ******************************/
void software_init(void);
void hardware_init(void);


//ʹ�ÿ�ʼ�����д�����������, 
//eg: B520��Ŀ�е� thread_manager �߳� -> ����ʹ��������ƿ��������й���
//���������������
#define START_TASK_PRIO		1       //�������ȼ�
#define START_STK_SIZE 		128     //�����ջ��С	
extern TaskHandle_t StartTask_Handler;     //������
void start_task(void *pvParameters);//������ں���





#endif // end __MAIN_H__

