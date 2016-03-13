#include<stdio.h>
void main()
{
	int i,sum;
	i=0;
	do/*利用do while必须保证第一项满足条件，因为不管是否满足都要执行一次*/ 
	{
		sum+=i;
		i++;
	}while (i<=100);
	printf("%d",sum);
}
