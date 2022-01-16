#include "thread_algo.h"
#include "sys.h"

/**************************** global varible ******************************/
static StackType_t IdleTaskStack[configMINIMAL_STACK_SIZE]; //�������������ջ
static StaticTask_t IdleTaskTCB; //����������ƿ�

static StackType_t TimerTaskStack[configTIMER_TASK_STACK_DEPTH]; //��ʱ�����������ջ
static StaticTask_t TimerTaskTCB; //��ʱ������������ƿ�

/**************************** macro definition ******************************/

/**************************** macro definition ******************************/

//����thread algorithm�����й�
StackType_t ThreadAlgoStack[THREAD_ALGO_STK_SIZE]; //�����ջ
StaticTask_t ThreadAlgoTCB;             //������ƿ�
TaskHandle_t ThreadAlgo_Handler;        //������


//���ʹ�þ�̬��
// �� �� �� �� Ҫ �� �� ʵ �� �� �� �� �� vApplicationGetIdleTaskMemory() ��
// vApplicationGetTimerTaskMemory()��ͨ������������������������Ͷ�ʱ����������������
// ջ��������ƿ�����ڴ棬���������������� mainc.c �ж��壬

/**
 * @brief ��������������ջ��������ƿ���ڴ�Ӧ�����û����ṩ
 * 
 * @param ppxIdleTaskTCBBuffer ������ƿ��ڴ�
 * @param ppxIdleTaskStackBuffer �����ջ�ڴ�
 * @param pulIdleTaskStackSize �����ջ��С
 */
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, 
                                    StackType_t **ppxIdleTaskStackBuffer, 
                                    uint32_t *pulIdleTaskStackSize)
{
    *ppxIdleTaskTCBBuffer = &IdleTaskTCB;
    *ppxIdleTaskStackBuffer = IdleTaskStack;
    *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
}

/**
 * @brief ��ȡ��ʱ�������������ƿ��ڴ��
 *         �� �� �� �� �� �� �� �� �� �� ʱ �� �� �� �� �� �� API ���������
*          vApplicationGetIdleTaskMemory()�� vApplicationGetTimerTaskMemory()����ȡ��Щ�ڴ档
 * @param ppxTimerTaskTCBBuffer ������ƿ��ڴ�
 * @param ppxTimerTaskStackBuffer �����ջ�ڴ�
 * @param pulTimerTaskStackSize �����ջ��С
 * @retval None
 */
void vApplicationGetTimerTaskMemory(StaticTask_t **ppxTimerTaskTCBBuffer, 
                                    StackType_t **ppxTimerTaskStackBuffer, 
                                    uint32_t *pulTimerTaskStackSize)
{
    *ppxTimerTaskTCBBuffer = &TimerTaskTCB;
    *ppxTimerTaskStackBuffer = TimerTaskStack;
    *pulTimerTaskStackSize = configTIMER_TASK_STACK_DEPTH;
}

/**
 * @brief �߳���ں���
 * 
 * @param pvParameters 
 */
void thread_algo_enery(void *pvParameters) //������
{

    while(1)
    {
        //printf("Thread_algo running...\r\n");
        vTaskDelay(2000);
    }
}

