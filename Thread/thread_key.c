#include "thread_key.h"

/**************************** global varible ******************************/
TaskHandle_t KeyTask_Handler;   //������
xQueueHandle Key_Queue;          //��Ϣ���о��

/**************************** macro definition ******************************/

/**************************** macro definition ******************************/

/**
 * @brief hardware_init
 * 
 */
static void hardware_init()
{
    KEY_Init();

    return;
}

/**
 * @brief software_init
 * 
 */
static void software_init()
{

}

/**
 * @brief resource_init
 * 
 */
static void resource_init()
{
    Key_Queue = xQueueCreate(KEY_Q_SIZE, sizeof(uint8_t));  //��ʼ����Ϣ����
}

/**
 * @brief key_task
 * 
 * @param pvParameters 
 */
void key_task(void *pvParameters)
{
    uint8_t key = 0;
    hardware_init();
    software_init();
    resource_init();

    while(1)
    {
        //printf("Key thread running...\r\n");
        //���в���ϵͳ�ĵط�ʹ�� ��ѯ����������
        key = KEY_Scan(0);

        //����
        //printf("thread_key = %d\r\n", key);
        if(Key_Queue!=NULL && key!=0)
        {
            xQueueSend(Key_Queue, &key, 1000);   //���͵���Ϣ����
        }
        switch(key)
        {
            //���� WKUP ����
            //���°���һֱ��������, ��������Ҳ��Ч��
            case WKUP_PRES:
                //vTaskSuspend(Task1Task_Handler); //�������� 1 (2)
                //printf("�������� 1 ������!\r\n");
                break;
            case KEY0_PRES:
                //vTaskResume(Task1Task_Handler); //�ָ����� 1 (3)
                printf("�ָ����� 1 ������!\r\n");
                break;
            case KEY1_PRES:
                //vTaskSuspend(Task2Task_Handler);//�������� 2 (4)
                printf("�������� 2 ������!\r\n");
                break;
            default:
                //printf("%s No keyboard input.\r\n", __func__);
                break;
        }
        vTaskDelay(10); //��ʱ 10ms
    }
}
