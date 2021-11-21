#include "sys.h"   
#include "led.h"
#include "delay.h"

//
//
/**
 * @brief ��ʼ��PA8��PD2Ϊ�����.��ʹ���������ڵ�ʱ��		    
 * 
 * @desc: LED IO��ʼ��
 * 		  ���� GPIO
 */
void LED_Init(void)
{
	//ʹ��ʱ��
	RCC->APB2ENR |= 1 << 2;    //ʹ��PORTAʱ��	   	 
	RCC->APB2ENR |= 1 << 5;    //ʹ��PORTDʱ��	   	 
	GPIOA->CRH &= 0XFFFFFFF0;  //����, 0xF0 : 1111 0000
	GPIOA->CRH |= 0X00000003;  //PA8 �������   	 
    GPIOA->ODR |= 1 << 8;      //PA8 �����
											  
	GPIOD->CRL &= 0XFFFFF0FF;
	GPIOD->CRL |= 0X00000300;	//PD.2�������
	GPIOD->ODR |= 1 << 2;      //PD.2����� 

	return;
}

/**
 * @brief LED set
 * 
 */
void LED_Set()
{
	GPIO_Set(GPIOA, 8, 1);
	GPIO_Set(GPIOD, 2, 1);
	
	return;
}

/**
 * @brief LED reset
 * 
 */
void LED_Reset()
{
	GPIO_Reset(GPIOA, 8, 0);
	GPIO_Reset(GPIOD, 2, 0);
	
	return;
}


/**
 * @brief �� �� ix λ��λ 
 * 
 * @param gpio 
 * @param pin_num 
 * @param val 
 */
void GPIO_Set(GPIO_TypeDef *gpio, uint8_t pin_num, uint8_t val)
{
	u32 temp = gpio->ODR;		//�ݴ�ԭ����ֵ
	temp |= val << pin_num;
	gpio->ODR |= temp;

	return;
}

/**
 * @brief reset GPIO pin
 * 
 * @param gpio 
 * @param pin_num 
 * @param val 
 */
void GPIO_Reset(GPIO_TypeDef *gpio, uint8_t pin_num, uint8_t val)
{
	u32 temp = gpio->ODR;			//�ݴ�ԭ����ֵ
	temp &= ~(1 << pin_num);	//~ ��λȡ��
	gpio->ODR |= temp;

	return;
}





