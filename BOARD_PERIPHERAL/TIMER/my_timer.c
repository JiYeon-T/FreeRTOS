#include "my_timer.h"

/**
 * @brief FreeRTOS �� timer �Ļص�����
 * 
 */
void periodic_timer_cb(TimerHandle_t xTimer)
{
    printf("%d timer cb invoked.\r\n");
}

