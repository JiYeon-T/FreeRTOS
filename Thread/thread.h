/**
 * @file thread.h
 * @author your name (you@domain.com)
 * @brief all thread information and public macro defination
 * @version 0.1
 * @date 2022-01-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef __THREAD_H__
#define __THREAD_H__
#include "FreeRTOS.h"
#include "event_groups.h"

/**************************** global varible ******************************/
#define THREAD_MSG_BUFF_SIZE 1024

// �߳�֮��ͨ�ŵ����ݸ�ʽ
typedef struct 
{
    uint8_t msg_id; // ͨ����ͬ ID �����ֲ�ͬ������Ӧ�ò���Ϣ
    uint8_t msg_len;
} head_t;

typedef struct 
{
    head_t head;
    uint8_t data[THREAD_MSG_BUFF_SIZE];
} thrad_msg_t;

typedef enum
{
    THREAD_MSG_SYNC,
    THREAD_MSG_EXIT,
    THREAD_MSG_DATA,
    THREAD_MSG_UI,
} THREAD_MSG_E;
/**************************** macro definition ******************************/

/**************************** macro definition ******************************/




#endif

