/**
 * @file thread_manager.h
 * @author your name (you@domain.com)
 * @brief �߳����йصĺ��Լ���Ҫ���Ⱪ¶�Ľӿڶ����� .h ��
 * @version 0.1
 * @date 2021-12-01
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef __THREAD_MANAGER_H__
#define __THREAD_MANAGER_H__
#include "FreeRTOS.h"
#include "event_groups.h"
/**************************** task info ******************************/
#define MANAGER_TASK_PRIO 5         //�������ȼ�
#define MANAGER_STK_SIZE 128        //�����ջ��С
extern TaskHandle_t ManagerTask_Handler;   //������
void thread_manager_task(void *pvParameters); //������

/**************************** global varible ******************************/
extern EventGroupHandle_t event_group; //�¼���־��, ��������һ������/�¼���������/�¼�����ͬ��

/**************************** macro definition ******************************/
#define LED0_EVENT      (1 << 0) //0x00000001
#define LED1_EVENT      (1 << 1)
#define KET_EVENT       (1 << 2)
#define GUI_EVENT       (1 << 3)

#define TASK_SYNC       (1 << 4)
#define TASK_EXIT       (1 << 5)
#define EVENT_BIT_ALL    LED0_EVENT | LED1_EVENT | KET_EVENT | GUI_EVENT
/**************************** macro definition ******************************/


#endif // end __THREAD_MANAGER_H__

