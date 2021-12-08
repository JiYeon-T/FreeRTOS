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
/**************************** global varible ******************************/
//LCD ˢ��ʱʹ�õ���ɫ
static int lcd_discolor[14] = { WHITE, BLACK, BLUE, BRED, 
                        GRED, GBLUE, RED, MAGENTA, 
                        GREEN, CYAN, YELLOW, BROWN, 
                        BRRED, GRAY };
/**************************** macro definition ******************************/

/**************************** macro definition ******************************/

//thread ui task
TaskHandle_t Thread_UI_Handler; //������

static void thread_ui_hardware_init()
{
    LCD_Init();         //��ʼ�� LCD

    return;
}


static void thread_ui_software_init()
{
    POINT_COLOR = RED;
    LCD_ShowString(30, 10, 200, 16, 16, "ATK STM32F103/F407");
    LCD_ShowString(30, 30, 200, 16, 16, "FreeRTOS Examp 6-1");
    LCD_ShowString(30, 50, 200, 16, 16, "Task Creat and Del");
    LCD_ShowString(30, 70, 200, 16, 16, "ATOM@ALIENTEK");
    LCD_ShowString(30, 90, 200, 16, 16, "2016/11/25");

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
        num++; //����ִ 1 �д����� 1 ע�� num �ӵ� 255 ��ʱ������㣡��
        //LED0 =! LED0;
        printf("���� 1 �Ѿ�ִ�У�%d ��\r\n", num);
        if(num==5) 
        {
            //vTaskDelete(Task2Task_Handler);//���� 1 ִ�� 5 ��ɾ������ 2 (4)
            printf("���� 1 ɾ�������� 2!\r\n");
        }
        LCD_Fill(6, 131, 114, 313, lcd_discolor[num % 14]); //�������
        //LCD_Fill(6, 131, 114, 313, BLACK); //�������
        LCD_ShowxNum(86, 111, num, 3, 16, 0x80); //��ʾ����ִ�д���
        vTaskDelay(1000); //��ʱ 1s��Ҳ���� 1000 ��ʱ�ӽ���
    }
}

