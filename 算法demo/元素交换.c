#include <stdio.h>
#include <stdlib.h> 

void Reverse(int *a,int m,int n); 

int main (void)
{
	int i,n,t,k;
	int *a;
	printf("请输入元素个数：\n");
	scanf("%d",&n);
	a=(int *)malloc(sizeof(int)*n);
	printf("请输入%d个数：\n",n);
	for(i=0;i<n;i++)
		scanf("%d",a+i);
	printf("请输入k：");
	scanf("%d",&k);
	Reverse(a,0,n);
	Reverse(a,0,n-k);
	Reverse(a,n-k,n);
	printf("交换后的数组为：\n");
	for(i=0;i<n;i++)
		printf("%-5d",a[i]); 
	free(a);
	return 0;
}


void Reverse(int *a,int m,int n)
{
	int i,j,t;
	for(i=m,j=n-1;i<j;i++,j--){
		t=a[i];
		a[i]=a[j];
		a[j]=t;
	}
}
