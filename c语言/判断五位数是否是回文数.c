#include<stdio.h>
int main(void)
{
	int x;
	int ge,shi,qian,wan;
	printf("������һ����λ����\n");
	scanf("%d",&x);
	if (x>10000&&x<1000000)
	{
		wan=x/10000;
		qian=x/1000%10;
		shi=x%100/10;
		ge=x%10;
		if (wan==ge&&qian==shi)
		printf("�ǻ�����");
		else
		printf("���ǻ�����");
	}
	else
	printf("�������");
 } 
