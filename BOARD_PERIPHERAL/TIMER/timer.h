/**
 * @file timer.h
 * @author your name (you@domain.com)
 * @brief ͨ�ö�ʱ���Լ��߼���ʱ����ʹ��
 *        ��ʱ���Ĺ��ܱȽ϶�, ���벶��, ������ƣ�PWM����ȵȣ�
 * @version 0.1
 * @date 2022-03-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef __TIMER_H__
#define __TIMER_H__
#include "sys.h"
#include "board.h"

void TIM3_Int_Init(u16 arr, u16 psc);

#endif

