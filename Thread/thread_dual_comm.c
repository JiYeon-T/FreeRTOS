/**
 * @file thread_dual_comm.c
 * @author your name (you@domain.com)
 * @brief PC �Ӵ��ڷ�������, STM32 ���н���
 * @version 0.1
 * @date 2021-12-09
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "thread_dual_comm.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "usart.h"
#include "my_timer.h"

/**************************** global varible ******************************/
TaskHandle_t DualCommTask_Handler;      //������
xQueueHandle Dual_Comm_Queue;           //��Ϣ���о��
SemaphoreHandle_t BinarySemaphore;      //��ֵ�ź��� -> �ᵼ��"���ȼ���ת", ʹ�û����ź���
xTimerHandle g_timer_handle;            //��ʱ�����
/**************************** macro definition ******************************/
//���ڴ��ڿ��� LED ������
#define LED0_ON     1
#define LED0_OFF    2
#define LED1_ON     3
#define LED1_OFF    4
#define COMMAND_ERR 0xFF

/**************************** macro definition ******************************/

/**
 * @brief hardware_init
 * 
 */
static void hardware_init()
{
	//uart_init(115200);					//��ʼ������

    return;
}

/**
 * @brief software_init
 * 
 */
static void software_init()
{

}

/**
 * @brief resource_init
 * 
 */
static void resource_init()
{
    //
    // initialize queue
    //
    Dual_Comm_Queue = xQueueCreate(DUAL_COMM_Q_SIZE, sizeof(uint8_t));  

    //
    // ��ʼ����ֵ�ź���
    //
    BinarySemaphore = xSemaphoreCreateBinary();

    //��ʼ����ʱ��
    // g_timer_handle = xTimerCreate((const char*)"periodic_timer",
    //                               (TickType_t)1000,
    //                               (UBaseType_t)pdTRUE,
    //                               (void*)1,
    //                               (TimerCallbackFunction_t)periodic_timer_cb);
    // xTimerStart(g_timer_handle, 0);
}

/**
 * @brief key_task
 * 
 * @param pvParameters 
 */
void dual_comm_task(void *pvParameters)
{
    uint8_t t = 0;
    hardware_init();
    software_init();
    resource_init();

    while(1)
    {
        //printf("dualcomm task running...\r\n");

        //����� ��ѯ�ķ�ʽ, �����ʽ���� -> �����ж�
        if(USART_RX_STA & 0x8000)
		{
			uint16_t len = USART_RX_STA & 0x3fff;  //�õ����յ����ݳ���

			printf("received:\r\n");
			for(t = 0; t < len; ++t)
			{
				USART1->DR = USART_RX_BUF[t];
				while((USART1->SR & 0X40) == 0); //�ȴ����ݷ��ͽ���
                //printf("%c", )
			}
            //
            // �յ������ݷ��͵�������
            // һ�η��ʹ�������
            //
            xQueueSend(Dual_Comm_Queue, USART_RX_BUF, 10);

            //
            // ͨ�� semaphore ���͵� thread_led0 �߳�
            // Ӧ���Ǵ����ж����ͷ��ź���: dual_comm_thread �н��н���
            //
            if(BinarySemaphore != NULL)
            {
                xSemaphoreGive(BinarySemaphore);
            }
            

			USART_RX_STA = 0;   //��λ��־λ
            memset(USART_RX_BUF, 0, USART_REC_LEN); //���ȫ�ֱ�������
		}

        vTaskDelay(10); //��ʱ 10ms
    }
}

