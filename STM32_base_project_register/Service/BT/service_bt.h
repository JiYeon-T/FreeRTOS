/**
 * @file service_bt.h
 * @author your name (you@domain.com)
 * @brief (1)service layer process data from lower layer, eg:BSP layer
 *        (2)and send it to upper layer, eg: GUI, APP, proto...
 *        (3)ͳһ�ϲ�ӿ�, ������ֲ
 *        (4)�������豸�Լ�����ʹ�� ��������� ��˼����й���: DEVICE_EXPORT(func_ptr1, func_ptr2)
 *        (5)���Զ� service ���д����һ����̬�⣬ֻ�ṩͷ�ļ�
 * @version 0.1
 * @date 2022-02-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef __SERVICE_BT_H__
#define __SERVICE_BT_H__
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>


void service_bt_init(void);
void service_bt_send(uint8_t *p_data,uint32_t len);
void service_bt_receive(void);

#endif //end #ifndef __SERVICE_BT_H__

