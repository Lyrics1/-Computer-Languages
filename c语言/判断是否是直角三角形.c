#include<stdio.h>
#include<math.h>
int main(void)
{
	int a,b,c;
	printf("�����������εı߳�\n");
	scanf("%d,%d,%d",&a,&b,&c);
	if (a<0||b<0||c<0)
	{
		printf("��Ǹ���߳�����Ϊ����");

	}
   if (a+b<=c||a+c<=b||b+c<=a)
   {
   	printf("����������������");
	   exit(1); 
	} 
	if ((pow(a,2)+pow(b,2))==pow(c,2)||(pow(a,2)+pow(c,2))==pow(b,2)||(pow(b,2)+pow(c,2))==pow(a,2))
	printf("��ֱ��������");
	else
	printf("����������"); 
} 
