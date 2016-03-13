#include<stdio.h>
/*计算梯形的面积*/ 
void main()
{
	float a,b,h,s;
	printf("输入上底a,下底b,高h\n");
	scanf("%f%f%f",&a,&b,&h);
	s=((a+b)*h)/2;
	printf("%f",s);
}
