������:

(1)��ջ����������, ������ RAM �� ��û�п����� flash �� Ӧ�ò��ᣬ flash �൱�ڴ��̣�



##### FreeRTOS

##### 1.Task

```C
BaseType_t xTaskCreate( TaskFunction_t pxTaskCode,
                        const char * const pcName,
                        const uint16_t usStackDepth,
                        void * const pvParameters,
                        UBaseType_t uxPriority,
                        TaskHandle_t * const pxCreatedTask );
```

?	������Ҫ RAM �������������йص�״̬��Ϣ(������ƿ�)������Ҳ��Ҫһ���� RAM ����Ϊ�����ջ�����ʹ�ú��� xTaskCreate()����������Ļ�����ô��Щ**����� RAM �ͻ��Զ��Ĵ� FreeRTOS �Ķ��з���**��**��˱����ṩ�ڴ�����ļ���Ĭ������ʹ��heap_4.c ����ڴ�����ļ������Һ� configSUPPORT_DYNAMIC_ALLOCATION ����Ϊ 1**�����ʹ�ú��� xTaskCreateStatic()�����Ļ���Щ RAM ����Ҫ�û����ṩ�ˡ�

?	�´���������Ĭ�Ͼ��Ǿ���̬�ģ������ǰû�б����������ȼ�������������ô������ͻ�������������̬��ʼ���У��������������������ǰ���������󣬶����Դ�������
