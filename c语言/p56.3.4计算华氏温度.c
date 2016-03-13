#include<stdio.h>
/*计算华氏温度最后保留两位小数*/ 
int main(void)
{
	float T,c;
	printf("please input a temperary\n");
	scanf("%f",&T);
	c=5.0/9*(T-32);
	printf("%.2f",c);
}
