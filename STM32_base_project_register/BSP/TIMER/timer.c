#include "timer.h"
#include "led.h"

/**
 * @brief ͨ�ö�ʱ���жϳ�ʼ��
 *        ����ʱ��ѡ��ΪAPB1��2������APB1Ϊ36M
 * @param[in]  arr �Զ���װֵ
 * @param[in]  psc ʱ��Ԥ��Ƶ��
 */
void TIM3_Int_Init(u16 arr, u16 psc)
{
	RCC->APB1ENR |= 1<<1;	//TIM3ʱ��ʹ��    
 	TIM3->ARR = arr;  	//�趨�������Զ���װֵ 
	TIM3->PSC = psc;  	//Ԥ��Ƶ������
	TIM3->DIER |= 1<<0;   //��������ж�				
	TIM3->CR1 |= 1<<0;    //ʹ�ܶ�ʱ��3
  	MY_NVIC_Init(TIM3_PRIEMPTION_PRIORITY, TIM3_SUB_PRIORITY, TIM3_IRQn, TIM3_NVIC_GROUP); //��ռ1�������ȼ�3����2									 
}

/**
 * @brief ��ʱ��3�жϷ������
 * 
 */
void TIM3_IRQHandler(void)
{ 		    		  			    
	if(TIM3->SR & 0X0001)//����ж�
	{
		LED1 =! LED1;			    				   				     	    	
	}				   
	TIM3->SR &= ~(1<<0);//����жϱ�־λ 	    
}