/**
 * @file thread_ui.c
 * @author your name (you@domain.com)
 * @brief start GUI thread use LCD 
 * @version 0.1
 * @date 2021-12-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "thread_ui.h"
#include <stdint.h>
#include "led.h"
#include "lcd.h"
#include <stdint.h>
#include <string.h>

/**************************** global varible ******************************/
//LCD ˢ��ʱʹ�õ���ɫ
static int lcd_discolor[14] = { WHITE, BLACK, BLUE, BRED, 
                        GRED, GBLUE, RED, MAGENTA, 
                        GREEN, CYAN, YELLOW, BROWN, 
                        BRRED, GRAY };
extern xQueueHandle Key_Queue;          //��Ϣ���о��, from thread_key.c
extern xQueueHandle Dual_Comm_Queue;    //��Ϣ���о��, from thread_dual_comm.c
/**************************** macro definition ******************************/

/**************************** macro definition ******************************/

//thread ui task
TaskHandle_t Thread_UI_Handler; //������

static void thread_ui_hardware_init()
{
    LCD_Init(); //��ʼ�� LCD

    return;
}


static void thread_ui_software_init()
{
    POINT_COLOR = RED;
    LCD_ShowString(30, 10, 200, 16, 16, "NingXia");
    LCD_ShowString(30, 30, 200, 16, 16, "YinChuan");
    LCD_ShowString(30, 50, 200, 16, 16, "Weather:sunny");
    // LCD_ShowString(30, 70, 200, 16, 16, "");
    // LCD_ShowString(30, 90, 200, 16, 16, "2016/11/25");

    return;
}

void thread_ui_entry(void *pvParameters)
{
    uint8_t num = 0;

    thread_ui_hardware_init();
    thread_ui_software_init();
    POINT_COLOR = BLACK;
    LCD_DrawRectangle(5, 110, 115, 314); //��һ������
    LCD_DrawLine(5, 130, 115, 130); //����
    POINT_COLOR = BLUE;
    LCD_ShowString(6, 111, 110, 16, 16, "Task1 Run:000");

    while(1)
    {
        
        //
        // �����������԰����̵߳���Ϣ
        //
        if(Key_Queue != NULL)
        {
            uint8_t key_val;
            //
            // Ҫͨ�� xQueueReceive �ķ���ֵ�����ж�
            // UI �߳�ÿ 2s �ſ��Դ���һ�������е�һ����Ϣ
            // key thread �Ὣ��Ϣ���ŵ�һ��������, ��������(̫��Ļ����л��ǻᱬ)
            // ����ʹ��һֱ���������еķ�ʽ, ����ʹ�� ����֪ͨ + ���еķ�ʽ, ��������������, �ͷ���֪ͨ, �� UI �߳�ȥ����
            // #define UI_THREAD_MSG_QUEUE_READY    0x00000001
            // xTaskNotify()
            //
            if(xQueueReceive(Key_Queue, &key_val, portMAX_DELAY) == pdTRUE) //portMAX_DELAY, �����ȴ�
            {
                printf("ui_thread receive key val = %d\r\n", key_val);
                vTaskDelay(2000);   // ģ�� UI �߳� 2s �ſ��Դ���һ����Ϣ
                //UI show string
                //LCD_fill();
            }
        }

        //
        // queue��������Dual comm �̵߳���Ϣ
        //
        if(Dual_Comm_Queue != NULL)
        {
            uint8_t uart_receive[200];
            
            //
            // ÿ��ֻ�ܶ�ȡһ���ֽ� ???????????????
            //
            if(xQueueReceive(Dual_Comm_Queue, uart_receive, 10))   //һ��ֻ�ܶ�ȡһ���ֽ��𣿣���
            {
                uint8_t ix = 0;
                printf("ui_thread receive from usart:\r\n");
                for(ix = 0; ix < 200; ++ix)
                    printf("%c", uart_receive[ix]);
            }
        }

        num++; //����ִ 1 �д����� 1 ע�� num �ӵ� 255 ��ʱ������㣡��
        //LED0 =! LED0;
        //printf("���� 1 �Ѿ�ִ�У�%d ��\r\n", num);
        if(num==5) 
        {
            //vTaskDelete(Task2Task_Handler);//���� 1 ִ�� 5 ��ɾ������ 2 (4)
            //printf("���� 1 ɾ�������� 2!\r\n");
        }
        LCD_Fill(6, 131, 114, 313, lcd_discolor[num % 14]); //�������
        //LCD_Fill(6, 131, 114, 313, BLACK); //�������
        LCD_ShowxNum(86, 111, num, 3, 16, 0x80); //��ʾ����ִ�д���
        vTaskDelay(1000); //��ʱ 1s��Ҳ���� 1000 ��ʱ�ӽ���
    }
}

