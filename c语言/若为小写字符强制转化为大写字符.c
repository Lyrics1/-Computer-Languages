#include<stdio.h>
/*����Сд�ַ�����ת��Ϊ��д�ַ�*/ 
void main()
{
	char x;
	printf("please input char x\n");
	scanf("%c",&x);
	if (x>='a' && x<='z')
	printf("%c",x-32);
	else 
	printf("%c",x);
}
