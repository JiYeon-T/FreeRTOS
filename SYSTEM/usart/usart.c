#include "usart.h"	  

////////////////////////////////////////////////////////////////////////////////// 	 
//���ʹ��ucos,����������ͷ�ļ�����.
#if SYSTEM_SUPPORT_OS
#include "includes.h"					//ucos ʹ��	  
#endif
//V1.3�޸�˵�� 
//֧����Ӧ��ͬƵ���µĴ��ڲ���������.
//�����˶�printf��֧��
//�����˴��ڽ��������.
//������printf��һ���ַ���ʧ��bug
//V1.4�޸�˵��
//1,�޸Ĵ��ڳ�ʼ��IO��bug
//2,�޸���USART_RX_STA,ʹ�ô����������ֽ���Ϊ2��14�η�
//3,������USART_REC_LEN,���ڶ��崮�����������յ��ֽ���(������2��14�η�)
//4,�޸���EN_USART1_RX��ʹ�ܷ�ʽ
//V1.5�޸�˵��
//1,�����˶�UCOSII��֧��
//V1.6�޸�˵�� 20150109
//uart_init����ȥ���˿���PE�ж�
//V1.7�޸�˵�� 20150322
//�޸�OS_CRITICAL_METHOD���ж�Ϊ��SYSTEM_SUPPORT_OS
////////////////////////////////////////////////////////////////////////////////// 	  
 
//�������´���,֧��printf����,������Ҫѡ��use MicroLIB	  
#if 1
#pragma import(__use_no_semihosting)             
//��׼����Ҫ��֧�ֺ���                 
struct __FILE 
{ 
	int handle; 
	/* Whatever you require here. If the only file you are using is */ 
	/* standard output using printf() for debugging, no file handling */ 
	/* is required. */ 
}; 
/* FILE is typedef�� d in stdio.h. */ 
FILE __stdout;   

//����_sys_exit()�Ա���ʹ�ð�����ģʽ    
_sys_exit(int x) 
{ 
	x = x; 
} 

//�ض���fputc����
//printf�������ָ��fputc����fputc���������
//����ʹ�ô���1(USART1)���printf��Ϣ
int fputc(int ch, FILE *f)
{      
	while((USART1->SR&0X40) == 0)
		;//�ȴ���һ�δ������ݷ������  
	USART1->DR = (u8) ch;      	//дDR,����1����������
	return ch;
}
#endif 
//end
//////////////////////////////////////////////////////////////////

#if EN_USART1_RX   //���ʹ���˽���
//ע��,��ȡUSARTx->SR�ܱ���Ī������Ĵ���   	
u8 USART_RX_BUF[USART_REC_LEN];     //���ջ���,���USART_REC_LEN���ֽ�.
//����״̬
//bit15��	������ɱ�־
//bit14��	���յ�0x0d
//bit13~0��	���յ�����Ч�ֽ���Ŀ
u16 USART_RX_STA=0;       //����״̬���

/**
 * @brief ����1�жϷ������
 * 
 * @desc: DCD USART1_IRQHandler
 * 		  (1)�س�: 0x0D 0x0A;
 * 		  (2)����в���ϵͳ, ����Ҫ OSIntEnter(), OSInetExit();
 * 		  (3)�� startup_stm32f10x_hd.s ��������;
 */
void USART1_IRQHandler(void)
{
	u8 res;	

#if SYSTEM_SUPPORT_OS 		//���SYSTEM_SUPPORT_OSΪ�棬����Ҫ֧��OS.
	OSIntEnter();    
#endif
	if(USART1->SR & (1 << 5))	//SR bit[5], RXNE==1, ���յ�����
	{	 
		res = USART1->DR; 		//UART1->DR ֻ�� bit[8:0] ��Ч
		//res = USART1->DR & 0xFF; 
		if((USART_RX_STA & 0x8000) == 0)//bit[15], ����δ���, ���浽 USART_RX_BUF ����
		{
			if(USART_RX_STA & 0x4000)//bit[14], ���յ���0x0d, ÿ�ν������ݶ�Ҫ \r\n ��β, ������Ϊ����
			{
				if(res != 0x0a)
					USART_RX_STA = 0;//���մ���,���¿�ʼ
				else 
					USART_RX_STA |= 0x8000;	//��������ˣ� ��λ bit[15]
			}
			else //��û�յ�0X0D
			{	
				if(res == 0x0d)				//��ǰ�յ� 0x0D
					USART_RX_STA |= 0x4000;
				else						//��û�յ� 0x0D, �������ֽ�
				{
					USART_RX_BUF[USART_RX_STA & 0X3FFF] = res;	//bit[13:0], ������յ�����Ч�ֽ���Ŀ, 0x3F 0011 1111
					USART_RX_STA++;			//���յ�����Ч�ֽ���Ŀ+1
					if(USART_RX_STA > (USART_REC_LEN-1))		//�յ�����̫��, ��Ϊ����
						USART_RX_STA = 0;//�������ݴ���,���¿�ʼ����	  
				}		 
			}
		}  		 									     
	}
#if SYSTEM_SUPPORT_OS 	//���SYSTEM_SUPPORT_OSΪ�棬����Ҫ֧��OS.
	OSIntExit();  											 
#endif

	return;
} 
#endif		//end EN_USART1_RX								 

/** 
 * @brief ��ʼ��IO ����1
 * 
 * @param pclk2 PCLK2ʱ��Ƶ��(hz)
 * @param bound ������ 
 */
void uart_init(u32 pclk2, u32 bound)
{  	 
	float temp;
	u16 mantissa;
	u16 fraction;	 

	temp = (float)(pclk2) / (bound * 16);//�õ�USARTDIV
	mantissa = temp;				 //�õ���������
	fraction = (temp-mantissa) * 16; //�õ�С������	 
    mantissa <<= 4;
	mantissa += fraction; 
	RCC->APB2ENR |= 1 << 2;   //ʹ��PORTA��ʱ��  
	RCC->APB2ENR |= 1 << 14;  //ʹ�ܴ���ʱ�� RCC->APB2ENR:bit[14]
	GPIOA->CRH &= 0XFFFFF00F;//IO״̬����
	GPIOA->CRH |= 0X000008B0;//IO״̬���� 
	RCC->APB2RSTR |= 1 << 14;   //��λ����1, RCC->APB2RSTR:bit[14], ��������Լ���λ
	RCC->APB2RSTR &= ~(1 << 14);//ֹͣ��λ	   	   
	//����������
 	USART1->BRR = mantissa; // ����������	 
	USART1->CR1 |= 0X200C;  //1λֹͣ,��У��λ.
#if EN_USART1_RX		  //���ʹ���˽���
	//ʹ�ܽ����ж� 
	USART1->CR1 |= 1 << 5;    //���ջ������ǿ��ж�ʹ��

	//��2��������ȼ��� ��ռ���ȼ� �� �����ȼ���ֵ����2
	#define UART1_PRIEMPTION_PRIORITY  3
	#define UART1_SUB_PRIORITY         3
	#define UART1_NVIC_GROUP           2	
	MY_NVIC_Init(UART1_PRIEMPTION_PRIORITY, UART1_SUB_PRIORITY, USART1_IRQn, UART1_NVIC_GROUP);		
#endif

	return;
}

/**
 * @brief 
 * 
 */
