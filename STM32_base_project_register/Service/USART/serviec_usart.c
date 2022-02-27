#include "service_usart.h"

/**
 * @brief recv usart1 mag and print at com
 * 
 * @param usart 
 */
void uart1_print_recv_msg(USART_NUM usart)
{
    u8 t;
	u8 len;	
	u16 times=0; 
    /* ���ڴ����߼�, ͨ��ȫ�ֱ��� USART_RX_STA ʵ�� */
    //����״̬
    //bit15��	������ɱ�־
    //bit14��	���յ�0x0d
    //bit13~0��	���յ�����Ч�ֽ���Ŀ
    if(USART_RX_STA & 0x8000)	//bit[15], �������
    {
        len = USART_RX_STA & 0x3fff;//�õ��˴ν��յ������ݳ���
        printf("\r\n�����͵���ϢΪ:\r\n");
        //�ٽ��Ӵ����յ������ݴӴ��ڷ��ͳ�ȥ
        for(t = 0; t < len; t++)
        {
            USART1->DR = USART_RX_BUF[t];
            while((USART1->SR & 0X40) == 0)		//bit[6]�� ������ɱ�־λ
                ;//�ȴ����ͽ���
        }
        printf("\r\n\r\n");//���뻻��
        USART_RX_STA = 0;
    }else
    {
        times++;
        if(times % 300 == 0)
            printf("����������,�Իس�������\r\n");  
            //LED1 = !LED1;
        if(times % 30 == 0)
            //LED0 =! LED0;//��˸LED,��ʾϵͳ��������.
        delay_ms(10);   
    }
}

