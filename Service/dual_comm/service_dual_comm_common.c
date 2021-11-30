#include "service_dual_comm_common.h"

//����Ϊ��ʱ�������ʹ��
APP_TIMER_DEF(m_timer_id1);  
uint8_t TIME=0;
#define TIME_LEVEL_MEAS_INTERVAL1          APP_TIMER_TICKS(1000)//1s

APP_TIMER_DEF(m_timer_id2);  
uint8_t TIME2 = 0;
#define TIME_LEVEL_MEAS_INTERVAL2          APP_TIMER_TICKS(10000)//5s

/**
 * @brief �ϴ����ݸ��ֻ����������Ƕ�ʱ������һ ��2�����һ��
 * 
 */
static void TIME_update1(void) 
{
    uint8_t TIME_level;

    TIME_level = TIME;
    TIME++;
    NRF_LOG_INFO("TIME1 = %d", (uint8_t)TIME_level);
    nrf_gpio_pin_toggle(LED_3);

    return;
}

/**
 * @brief �ϴ����ݸ��ֻ����������Ƕ�ʱ������һ ��2�����һ��
 * 
 */
static void TIME_update2(void) 
{
    uint8_t TIME_level2;

    TIME_level2 = TIME2;
    TIME2++;
	NRF_LOG_INFO("TIME2 = %d", (uint8_t)TIME_level2);
	nrf_gpio_pin_toggle(LED_4);

    return;
}

/**
 * @brief TIMER callback
 * 
 * @param p_context 
 */
static void TIME_timeout_handler1(void * p_context)
{
    UNUSED_PARAMETER(p_context);
    TIME_update1();

    return;
}

/**
 * @brief TIMER callback
 * 
 * @param p_context 
 */
static void TIME_timeout_handler2(void * p_context)
{
    UNUSED_PARAMETER(p_context);
    TIME_update2();

    return;
}


/**@brief Function for the Timer initialization.
 *
 * @details Initializes the timer module. This creates and starts application timers.
 */
static void timers_init(void)
{
    // ��ʼ�������ʱ��.
    ret_code_t err_code = app_timer_init();
    APP_ERROR_CHECK(err_code);

    // Create timers.

    /* YOUR_JOB: Create any timers to be used by the application.
                 Below is an example of how to create a timer.
                 For every new timer needed, increase the value of the macro APP_TIMER_MAX_TIMERS by
                 one.
       ret_code_t err_code;
       err_code = app_timer_create(&m_app_timer_id, APP_TIMER_MODE_REPEATED, timer_timeout_handler);
       APP_ERROR_CHECK(err_code); */
	//����һ����ʱ�����ö�ʱ��ģʽ
    err_code = app_timer_create(&m_timer_id1,
                                APP_TIMER_MODE_REPEATED,
                                TIME_timeout_handler1);
    APP_ERROR_CHECK(err_code);
    //����һ����ʱ�����ö�ʱ��ģʽ
    err_code = app_timer_create(&m_timer_id2,
                                APP_TIMER_MODE_REPEATED,
                                TIME_timeout_handler2);
    APP_ERROR_CHECK(err_code);

    return;
}


//��ʼ��ʱ��ʼ��ʱ
static void application_timers_start(void)
{
    uint32_t err_code;

    // Start application timers.��ʱʱ����
    err_code = app_timer_start(m_timer_id1, TIME_LEVEL_MEAS_INTERVAL1, NULL);
    APP_ERROR_CHECK(err_code);
	
	  err_code = app_timer_start(m_timer_id2, TIME_LEVEL_MEAS_INTERVAL2, NULL);
    APP_ERROR_CHECK(err_code);

    return;
}

/**
 * @brief 
 * @param None
 * @retval None
 */
void dual_comm_init()
{
    //
    timers_init();
    application_timers_start();

    return;
}


