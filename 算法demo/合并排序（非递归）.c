#include <stdio.h>
#include <stdlib.h>

void MergeSort(int *a,int n);

void MergePass(int *a,int *b,int s,int n);

void Merge(int *a,int *b,int l,int m,int r);

int main (void)
{
	int *a;
	int i,n;
	printf("请输入数组长度:\n");
	scanf("%d",&n);
	a=(int *)malloc(sizeof(int)*n);
	printf("请输入%d个数：",n);
	for(i=0;i<n;i++)
		scanf("%d",&(a[i]));
	MergeSort(a,n);
	printf("合并排序后为：\n");
	for(i=0;i<n;i++)
		printf("%-5d",a[i]);
	free(a);
	return 0;	
} 

void MergeSort(int *a,int n)
{ 
	int *b;
	b=(int *)malloc(sizeof(int)*n);
	//每小组的长度 
	int s=1;	
	while(s<n){
		//将数组a合并到b 
		MergePass(a,b,s,n);
		s+=s;
		//将数组b合并到a
		MergePass(b,a,s,n);
		s+=s;
	} 
	free(b);
}

//不明白 
void MergePass(int *a,int *b,int s,int n)
{	int i=0,j;
	//合并大小为s的相邻子数组 
	while(i<=n-2*s){
		Merge(a,b,i,i+s-1,i+2*s-1);
		i=i+2*s;
	}
	//剩余两组有一组不全 
	if(i+s<n)	Merge(a,b,i,i+s-1,n-1);
	//只剩余一组 
	else{
		 for(j=i;j<=n-1;j++)	b[j]=a[j];
	}
}

//将两个有序数组合并到数组b中 
void Merge(int *a,int *b,int l,int m,int r)
{
	int i,j,k;
	i=l;j=m+1;k=0;
	while(i<=m||j<=r){
		if(i<=m&&a[i]<a[j]||j>r)	
			b[k++]=a[i++];
		else b[k++]=a[j++];
	}
	printf("B:\n");
	for(j=0;j<k;j++)
		printf("%d ",b[j]);
	printf("\n");
}
