#include<stdio.h>
#include<math.h>
int main(void)
{
	int a,b,c;
	printf("请输入三角形的边长\n");
	scanf("%d,%d,%d",&a,&b,&c);
	if (a<0||b<0||c<0)
	{
		printf("抱歉，边长不能为负数");

	}
   if (a+b<=c||a+c<=b||b+c<=a)
   {
   	printf("不符合三角形条件");
	   exit(1); 
	} 
	if ((pow(a,2)+pow(b,2))==pow(c,2)||(pow(a,2)+pow(c,2))==pow(b,2)||(pow(b,2)+pow(c,2))==pow(a,2))
	printf("是直角三角形");
	else
	printf("其他三角形"); 
} 
