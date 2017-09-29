#include <stdio.h>
#include <stdlib.h>

int MaxSort(int a[],int n);

int main(void)
{
	int *a,*b;
	int i,n,t;
	printf("请输入数组长度:\n");
	scanf("%d",&n);
	a=(int *)malloc(sizeof(int)*n);
	b=(int *)malloc(sizeof(int)*n);
	printf("请输入%d个数：",n);
	for(i=0;i<n;i++)
		scanf("%d",&(a[i]));
	b[0]=a[0];
	//b数组里存放a[i]之前的最大字段和 
	for(i=1;i<n;i++){
		if(b[i-1]>0) b[i]=b[i-1]+a[i];
		else b[i]=a[i];	
	}
	t=b[0];
	for(i=1;i<n;i++)
		if(t<b[i])	t=b[i];
	printf("最大字段和为：%d\n",t);
	free (a);
	free (b); 
	return 0;	
}

