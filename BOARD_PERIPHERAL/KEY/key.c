#include "key.h"
#include "delay.h"
 	    
/**
 * @brief ������ʼ������
 * 		  PA0, PA15 �� PC5 ���ó����� 
 * 
 */
void KEY_Init(void)
{
	RCC->APB2ENR |= 1<<2;     	//ʹ��PORTAʱ��
	RCC->APB2ENR |= 1<<4;     	//ʹ��PORTCʱ��
	JTAG_Set(SWD_ENABLE);		//�ر�JTAG,����SWD

    //TODO:
    //WK_UP ���������� ***************************************************
    //�����ж�һ���ǲ���Ӳ��������
    //PA0 - WK_UP ����������
	GPIOA->CRL &= 0XFFFFFFF0;	//PA0 ���ó�����, ģ������ģʽ	  
	GPIOA->CRL |= 0X00000008;   //���� / ��������ģʽ
    GPIOA->ODR &= 0xFFFFFFFF;   //���������� GPIOA->ODR &= 0xFFFFFFF7         

	GPIOA->CRH &= 0X0FFFFFFF;	//PA15���ó�����	  
	GPIOA->CRH |= 0X80000000; 	//���� / ��������ģʽ		 
	GPIOA->ODR |= (1 << 15);	//PA15����, PA0Ĭ������

	GPIOC->CRL &= 0XFF0FFFFF;	//PC5���ó�����	  
	GPIOC->CRL |= 0X00800000;   
	GPIOC->ODR |= 1 << 5;	   		//PC5����, ͨ��������ݼĴ�����������, Ĭ������

	return;
} 

/**
 * @brief ����������
 * 		  ���ذ���ֵ
 * 
 * @param mode mode:0,��֧��������;1,֧��������;
 * @return u8 ����ֵ��0��û���κΰ�������; KEY0_PRES��KEY0����; KEY1_PRES��KEY1����; WKUP_PRES��WK_UP���� 
 * 		   ע��˺�������Ӧ���ȼ�,KEY0>KEY1>WK_UP!!
 */
u8 KEY_Scan(u8 mode)
{
	static u8 key_up = 1;//�������ɿ���־
	if(mode)
        key_up = 1;  //֧������	
	  
    if(key_up && (KEY0==0 || KEY1==0 /*|| WK_UP==1*/)) //KEY_UP����������
    {
        delay_ms(10);//ȥ���� 
        key_up = 0;
        if(KEY0 == 0)
            return KEY0_PRES;
        else if(KEY1 == 0)
            return KEY1_PRES;
        // else if(WK_UP == 1)
        //     return WKUP_PRES; 
    }else if(KEY0==1 && KEY1==1 /*&& WK_UP==0*/)
        key_up = 1;

	return 0;// �ް�������
}

/**
 * @brief �жϰ���
 *        ���� GPIO ʱ�� -> ����Ϊ���� -> �����ж� -> ���ж�
 * 		  д�жϷ�����
 */
