/**
 * @file thread_manager.c
 * @author your name (you@domain.com)
 * @brief create thread manager to manage all threads
 * @version 0.1
 * @date 2021-12-01
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "thread_manager.h"
#include "sys.h"
#include "usart.h"
/**************************** task info ******************************/
TaskHandle_t ManagerTask_Handler;   //������

// �������߳̽��й���
// �����̵߳ĸ��߳�, �����̵߳ĳ�ʼ���Լ��˳�
/**************************** global varible ******************************/
EventGroupHandle_t manager_event_group; //�¼���־��, ��������һ������/�¼���������/�¼�����ͬ��

/**************************** macro definition ******************************/

/**************************** macro definition ******************************/

/**
 * @brief hardware_init
 * 
 */
static void hardware_init()
{

    return;
}

/**
 * @brief software_init
 * 
 */
static void software_init()
{
    // //֪ͨ�����̳߳�ʼ�� -> ͨ��ʹ������֪ͨʵ��
    // //���ñ�־λ
    // xEventGroupSetBits(manager_event_group, TASK_SYNC);
}

/**
 * @brief resource_init
 * 
 */
static void resource_init()
{
    // event group
    manager_event_group = xEventGroupCreate();
}

/**
 * @brief �߳���ں���, manager �߳��ж������߳̽��г�ʼ��
 * 
 * @param pvParameters 
 */
void thread_manager_task(void *pvParameters)
{
    hardware_init();
    resource_init();
    software_init();

    while(1)
    {
        printf("manager thread running...\r\n");
        vTaskDelay(1000);
    }
}

