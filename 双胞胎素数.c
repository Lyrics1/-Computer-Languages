#include<stdio.h>
int main()
{
	int x,y,i,j;
	int m=1,t,n=0;
	scanf("%d%d",&x,&y);
	for(i=x;i<y;i++)
	{
		if(i%2!=0)
		for(j=2;j<i;j++)
		
		{
			if(i%j==0||(i+2)%(j)==0)
			break;
		}
		if(j==i&&(i+2)<=y)//如果没有规定（i+2）<=y;则会出现i+2>y 
		printf("(%d,%d)",i,i+2);
		
	}
	return 0;
}
  

