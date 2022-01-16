#ifndef __THREAD_MONITOR_H__
#define __THREAD_MONITOR_H__
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

/**************************** task info ******************************/
#define     THREAD_MOINITOR_PRIO 2          //�������ȼ�
#define     THREAD_MONITOR_STK_SIZE 128    //�����ջ��С
extern StackType_t ThreadMonitorStack[THREAD_MONITOR_STK_SIZE]; //�����ջ
extern StaticTask_t ThreadMonitorTCB;             //������ƿ�
extern TaskHandle_t ThreadMonitor_Handler;        //������
extern SemaphoreHandle_t monitor_binary_handle;    //��ֵ�ź���
/**************************** global varible ******************************/



/**************************** function declaration ******************************/
void thread_monitor_enery(void *pvParameters);
uint8_t CommandParse(char *str);

/**************************** macro definition ******************************/

#endif // end __THREAD_MONITOR_H__



