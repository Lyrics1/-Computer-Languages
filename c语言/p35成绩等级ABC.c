#include<stdio.h>
int main (void)
{
	float x;
	printf("������ɼ���");
	scanf("%f",&x);
	if (x>=90)
	printf("A");
	if (60<=x<=89)
	printf("B");
	if (x<60)
	printf("C");
}
