#include<stdio.h>
void main()
{
	int m,n,r;
	printf("please input two number,m,n\n");
	scanf("%d%d",&m,&n);
	r=m%n;
	while (r!=0)
	{
		m=n;
		n=r;
		r=m%n;
	}
	printf("���Լ��=%d",r);
 } 
