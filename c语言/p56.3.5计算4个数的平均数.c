#include<stdio.h>
/*计算四个数的平均数*/ 
int main()
{
	float a,b,c,d,average;
	printf("please input four intergets\n");
	scanf("%f%f%f%f",&a,&b,&c,&d);
	average=(a+b+c+d)/4;
	printf("%f",average);
 } 
