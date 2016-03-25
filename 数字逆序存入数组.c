#include<stdio.h>
void main()
{
	long x,y,i=0,k,m;
	scanf("%d",&x);
	m=x;
	while(x!=0)
	{    
		y=x%10;
		x=(x-y)/10;
		i++; 
	}            //
	printf("i=%d\n",i);
	int a[i];
	for (k=0;k<i;k++)
	{
	  a[k]=m%10;
	  m=(m-a[k])/10;
	  printf("%3d",abs(a[k]));
	}
 } 
