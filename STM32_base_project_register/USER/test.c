#include "test.h"
 
int main(void)
{			
	Stm32_Clock_Init(9); 	//ϵͳʱ������
	delay_init(72000000);	     //��ʱ��ʼ�� 
	uart_init(72000000, 9600);	 //���ڳ�ʼ��Ϊ9600
	LED_Init();		  	 //��ʼ����LED���ӵ�Ӳ���ӿ�
	KEY_Init();
	EXTI_Init();
	printf("intialized.");
	//watch intialization

	while(1)
	{
		//open watch dog
		uart1_print_recv_msg(S_USART1);
		// printf("%d\n", KEY_Scan(1));
		// if(cmd == "circle loop"){
		// 	while(1);	//dog will bark
		// }

		//feed watch dog
		
		//printf("thread running...\n");
		//delay_ms(1000);
	}

	
}














