#include<stdio.h>
#include<string.h>//�ṩstrlen()������ԭ�� 
#define PRALSE "what a girl!"//define a = 20�Ǵ���ģ����=20����a; 
void main()
{	int x=121;
	int  t;
	t=printf("%dn m l.",x);//printf�з���ֵ���������з��Ϳո� 121 F is water's boiling point.  ����31���ַ�������\n����32 
	printf("%d",t);
	char name[40];
	scanf("%s",name);//scanf��ʼ����֮�������ո�blank)���Ʊ��(tab)�����з�(newline)�����ֹͣ��ȡ���������(hello,my name)�������ȡhello��my ֮�����Ȼ�������뵫��ȴ��û������������name�� 
	printf("sizeof name=%d\n",sizeof(name));//��ͬ 
	printf("sizeof name=%d\n",sizeof name);//�����name ����ʱ���ֽ���   ����scanf����� 
	printf("strlen name=%d\n",strlen (name));//  strlen ��ֻ���ȡ������name��Ĳ���������
	//sizeof �Ƿ�����ţ���Ҫ��ȡ���Ǿ������Ĵ�С��һ���û��Լ�������ַ���֮��� ���ã���ȡ���͵Ĵ�С��Ҫ 
	printf("����strlen=%d",strlen(PRALSE));//����ַ������ַ��������ո� ��㣩������ 
	printf("����sizeof=%d",sizeof PRALSE); //����sizeof���strlen��һ������Ϊ���ȡ\o
	//���Ƕ����������  
	 /*����[signed]int                  -2147483648~+2147483648
�޷�������unsigned[int]                       0~4294967295
������ short [int]                                    -32768~32768
�޷��Ŷ�����unsigned short[int]             0~65535
������ Long int                            -2147483648~+2147483648
�޷��ų�����unsigned [int]                   0~4294967295
�ַ���[signed] char                               -128~+127
�޷����ַ��� unsigned char                       0~255
������ float                                 3.4 x 10^��-38��~  3.4 x 10^��+38��
˫����double                              1.7 x 10^��-308��~  1.7 x 10^��+308��
��˫���� long double                 1.7 x 10^��-308��~  1.7 x 10^��+308��*/
 } 
