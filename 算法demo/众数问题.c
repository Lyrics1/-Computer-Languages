#include <stdio.h>
#include <stdlib.h> 

int main (void)
{
	int i,n,max,t,c;
	int *a;
	printf("������Ԫ�ظ�����\n");
	scanf("%d",&n);
	a=(int *)malloc(sizeof(int)*n);
	printf("������%d������\n",n);
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
	printf("������%d,������%d��\n",max,c);
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
