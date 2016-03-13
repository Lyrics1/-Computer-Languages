#include<stdio.h>
int main(void)
{
	int x=3,y=2,z;
	z=x>y?++x:y++;/*如果x大于y，则z=++x,否则z=y++,就是利用x>y判断是否执行++x,*/ 
	 printf("%d",z);
}
