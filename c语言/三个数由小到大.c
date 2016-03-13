#include<stdio.h>
/*引入中间变量*/ 
int main(void)
{ 
	int a,b,c,t;
	scanf("%d%d%d",&a,&b,&c);
	if (a>b)
	{
		t=a;
		a=b;
		b=t;
	}
	if (a>c)
	{
		t=a;
	    a=c;
	    c=t;
	}
	if (b>c)
	{
		t=b;
		b=c;
		c=t;
	}
	printf("%d%d%d",a,b,c);
	
	 
 } 
