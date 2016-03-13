#include<stdio.h>
int main(void)
{
	char c;
	printf("请输入一个字符\n");
	c=getchar();
	if(c<32)
	printf("控制字符");
	else if (c>='0'&&c<='9')
	printf("数字字符\n");
    else if(c<='z'&&c>='a')
	printf("小写英文字符");
	else if(c<='Z'&&c>='A')
	printf("大写英文字符");
	else
	printf("其他字符"); 	
 } 
