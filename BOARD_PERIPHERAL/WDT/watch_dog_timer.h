/**
 * @file watch_dog_timer.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef __WATCH_TIMER_H__
#define __WATCH_TIMER_H__
#include "sys.h"

/**
 * @brief  ���ͨ��һ��Ӳ�����Ź�ʵ�ֶ��������Ź�???????????????????????????????????
 * 
 * @param prer 
 * @param rlr 
 */
void IWDG_Init(u8 prer, u16 rlr);
void WWDG_Init(u8 tr,u8 wr,u8 fprer);
void WWDG_Set_Counter(u8 cnt);


#endif 

