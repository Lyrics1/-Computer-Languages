#include<stdio.h>
void main()
{
	int i,sum;
	i=0;
	do/*����do while���뱣֤��һ��������������Ϊ�����Ƿ����㶼Ҫִ��һ��*/ 
	{
		sum+=i;
		i++;
	}while (i<=100);
	printf("%d",sum);
}
