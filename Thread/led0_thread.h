#ifndef __LED0_THREAD_H__
#define __LED0_THREAD_H__
#include "sys.h"
#include "FreeRTOS.h"
#include "task.h"

//�������ȼ�
#define LED0_TASK_PRIO		2
//�����ջ��С	
#define LED0_STK_SIZE 		50  
//������, ����Ϊȫ�ֱ���
extern TaskHandle_t LED0Task_Handler;
//������
void led0_task(void *pvParameters);

/**
* @fun: ��������(�߳�)����ʹ��ȫ�ֱ����ķ�ʽ
* �ṹ��
void (*funPtr)(void);	//����ָ��
typedef struct TASK{
	funPtr taskEnterFun;
	char * taskName;
	int stackSize;
	int stackPrioirity;
	funPtr taskEnd;
	//����Ϣ�����йصĳ�Ա
	message_t	taskMessage;
	queue_t		takQueue;
	mail_t		taskMail;
	semaphare_t	taskSemaphere;
	//�ȵȣ�һ�������йؽṹ���п��԰��������йصĳ�Ա
} Task;
* @desc: B520��Ŀ�����ǰ��������ṹ�����ȫ�ֱ�����, .c �ļ��оͳ�ʼ��
*		 main ��ûִ�У���Щ������ƿ� init, delete �Ѿ���ʼ������
*		 �� manager_thread �������ٵ��� task1.init() ��ʼ���̣߳������߳���ں���
*/

#endif

