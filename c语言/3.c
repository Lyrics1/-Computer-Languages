/*求圆的面积*/
#include<stdio.h>
#include<conio.h>
#define PI 3.14159
int main(void)
{
	float s,r;
	system("cls");/*清屏，用于人机对话*/ 
	printf("请输入半径r:");
	scanf("%f", &r);
	if (r<0)
	{
	    printf("半径不能小于0");
		exit(0);
	}
	s=PI*pow(r,2);
	printf("s=%.3f",s);
return 0;
}
