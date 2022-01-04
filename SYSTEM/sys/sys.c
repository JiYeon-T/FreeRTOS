#include "sys.h"

//********************************************************************************  
//THUMBָ�֧�ֻ������
//�������·���ʵ��ִ�л��ָ��WFI  
void WFI_SET(void)
{
	//
	// ���: WFI
	//
	__ASM volatile("wfi");		  //WFI
}

//�ر������ж�
void INTX_DISABLE(void)
{		  
	__ASM volatile("cpsid i");  // CPSID I
}

//���������ж�
void INTX_ENABLE(void)
{
	__ASM volatile("cpsie i"); // CPSIE I
}

//����ջ����ַ
//addr:ջ����ַ
__asm void MSR_MSP(u32 addr) 
{
    MSR MSP, r0 			//set Main Stack value
    BX r14
}
