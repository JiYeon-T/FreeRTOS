##### 1.����������� service �㣬ʵ�ֵײ���ϲ�Ӧ�÷ֲ�

##### 2.λ��������bit band��
#define DEVICE_REG0 ((volatile unsigned long*)(0x40000000))
#define DEVICE_REG0_BIT0 ((volatile unsigned long*)(0x40000000))
#define DEVICE_REG0_BIT1 ((volatile unsigned long*)(0x40000000))

*DEVICE_REG0 = 0xAB;        //ʹ��������ַ���ʼĴ���
*DEVICE_REG0 = *DEVICE_REG0  | 0x02;    //��ͳ�������� bit1, 
*DEVICE_REG0 = 0x01;    //λ���������� bit1, 

Ϊ�˼�λ������, Ҳ���Զ����, ͨ��һ�� (λ����ַ+λ���),���Ĵ�����ַת���ɱ�����ַ���ٽ���һ���ѡ�λ����ַ��ת����ָ�����ͱ����ĺ�
#define BITBAND(addr, bitnum)   ((addr & 0xF0000000) + 0x20000000 + ((addr & 0xFFFFF) << 5) + (bitnum << 2))
//����ַת��Ϊָ�����͵ı���
#define MEM_ADDR(addr) *((volatile unsigned long*)(addr))
MEM_ADDR(DEVICE_REG0) = 0xAB;
MEM_ADDR(DEVICE_REG0) = MEM_ADDR(DEVICE_REG0) | 0x2;    //��ͳ����
MEM_ADDR(BITBAND(DEVICE_REG0, 1)) = 0x1;        //ʹ��λ��������ַ
//ʹ��λ������ʱ, ��������Ϊ volatile ��ֹ���������Ż�

##### 3.�͹���ģʽ���Բ���һ��
(1)˯��ģʽ
(2)ֹͣģʽ
(3)����ģʽ







