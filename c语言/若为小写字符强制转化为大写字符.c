#include<stdio.h>
/*若是小写字符，则转化为大写字符*/ 
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
