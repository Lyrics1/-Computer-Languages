#include<stdio.h>
int main(void)
{
	char c;
	printf("������һ���ַ�\n");
	c=getchar();
	if(c<32)
	printf("�����ַ�");
	else if (c>='0'&&c<='9')
	printf("�����ַ�\n");
    else if(c<='z'&&c>='a')
	printf("СдӢ���ַ�");
	else if(c<='Z'&&c>='A')
	printf("��дӢ���ַ�");
	else
	printf("�����ַ�"); 	
 } 
