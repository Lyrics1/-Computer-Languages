#include<stdio.h>
int main (void)
{
	float x;
	printf("ÇëÊäÈë³É¼¨£º");
	scanf("%f",&x);
	if (x>=90)
	printf("A");
	if (60<=x<=89)
	printf("B");
	if (x<60)
	printf("C");
}
