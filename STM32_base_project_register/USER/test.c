#include "sys.h"
#include "usart.h"		
#include "delay.h"	
#include "led.h" 
#include "key.h" 

 
int main(void)
{			
	u8 t;
	u8 len;	
	u16 times=0; 

	Stm32_Clock_Init(9); //ϵͳʱ������
	delay_init(72);	     //��ʱ��ʼ�� 
	uart_init(72,9600);	 //���ڳ�ʼ��Ϊ9600
	LED_Init();		  	 //��ʼ����LED���ӵ�Ӳ���ӿ�
	// LED_Set();
	// LED_Reset();

	while(1)
	{
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

	return 0; 
}














