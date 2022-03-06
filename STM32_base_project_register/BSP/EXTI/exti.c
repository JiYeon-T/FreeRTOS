/**
 * @file exti.c
 * @author your name (you@domain.com)
 * @brief external interrupt
 * @version 0.1
 * @date 2022-02-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "exti.h"
#include "board.h"
#include "led.h"
#include "key.h"
#include "sys.h"
#include "delay.h"

/**
 * @brief external interrupt intialization
 * 
 */
// void EXTI_Init(void)
// {

// }

/**
 * @brief intialize the key interrupt
 *        ����������(1)�ⲿ�ж� GPIO �ж��������, �����ж��޷�������
 */
void EXTI_Init()
{
    GPIO_NVIC_Config(KEY0_GPIO, KEY0_PORT, FTIR);   //rising trigger
    GPIO_NVIC_Config(KEY1_GPIO, KEY1_PORT, FTIR);   //falling trigger
    GPIO_NVIC_Config(WKUP_GPIO, WKUP_PORT, RTIR);
    MY_NVIC_Init(KEY0_PRIEMPTION_PRIORITY, KEY0_SUB_PRIORITY, EXTI9_5_IRQn, KEY0_NVIC_GROUP);
    MY_NVIC_Init(KEY1_PRIEMPTION_PRIORITY, KEY1_SUB_PRIORITY, EXTI15_10_IRQn, KEY1_NVIC_GROUP);
    MY_NVIC_Init(WKUP_PRIEMPTION_PRIORITY, WKUP_SUB_PRIORITY, EXTI0_IRQn, WKUP_NVIC_GROUP);

    return;
}

/**
 * @brief interrupt line 0 function
 * 
 */
void EXTI0_IRQHandler(void)
{
    delay_ms(10); //xiao dou 
    if(WK_UP == 1){ //PA0 - wake up key
        LED0 = !LED0;
        LED1 = !LED1;
    }

    EXTI->PR = (1<<0);  //��� Line0 �ϵ��жϱ�־

    return;
}

/**
 * @brief GPIO 9 - 5 �����ж���
 * 
 */
void EXTI9_5_IRQHandler(void)
{
    delay_ms(10);
    if(KEY0 == 0){
        LED0 = !LED0;   // button 0
        IWDG_Feed();    // fedd watch dog
    }

    EXTI->PR = (1 << 5);    //clear interrupt flag
}

/**
 * @brief �ж� 15 - 10 �����ж���
 * 
 */
void EXTI15_10_IRQHandler(void)
{
    delay_ms(10);
    if(KEY1 == 0){  // ����1
        LED1 = !LED1;
    }

    EXTI->PR = 1 << 15;
}

