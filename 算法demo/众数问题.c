#include <stdio.h>
#include <stdlib.h> 

int main (void)
{
	int i,n,max,t,c;
	int *a;
	printf("请输入元素个数：\n");
	scanf("%d",&n);
	a=(int *)malloc(sizeof(int)*n);
	printf("请输入%d个数：\n",n);
	for(i=0;i<n;i++)
		scanf("%d",a+i);
	max=a[0];c=1;
	for(i=0;i<n;i++){
		if(c==0){
			max=a[i];
			c++;
		}
		else{
			if(max==a[i])
				c++;
			else
				c--;
		}
	}
	c=0;
	for(i=0;i<n;i++)
		if(max==a[i])
			c++;
	printf("众数是%d,出现了%d次\n",max,c);
	/*
	max=t=1;
	for(i=0;i<n-1;i++){
		if(a[i]==a[i+1])	t++;
		else{
			if(max<t)	max=t;
			t=1;
		} 
	}
	*/
	free(a);
	return 0;
}
