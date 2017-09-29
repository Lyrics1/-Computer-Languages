#include <stdio.h>
#include <stdlib.h>

void MergeSort(int *a,int n);

void MergePass(int *a,int *b,int s,int n);

void Merge(int *a,int *b,int l,int m,int r);

int main (void)
{
	int *a;
	int i,n;
	printf("���������鳤��:\n");
	scanf("%d",&n);
	a=(int *)malloc(sizeof(int)*n);
	printf("������%d������",n);
	for(i=0;i<n;i++)
		scanf("%d",&(a[i]));
	MergeSort(a,n);
	printf("�ϲ������Ϊ��\n");
	for(i=0;i<n;i++)
		printf("%-5d",a[i]);
	free(a);
	return 0;	
} 

void MergeSort(int *a,int n)
{ 
	int *b;
	b=(int *)malloc(sizeof(int)*n);
	//ÿС��ĳ��� 
	int s=1;	
	while(s<n){
		//������a�ϲ���b 
		MergePass(a,b,s,n);
		s+=s;
		//������b�ϲ���a
		MergePass(b,a,s,n);
		s+=s;
	} 
	free(b);
}

//������ 
void MergePass(int *a,int *b,int s,int n)
{	int i=0,j;
	//�ϲ���СΪs������������ 
	while(i<=n-2*s){
		Merge(a,b,i,i+s-1,i+2*s-1);
		i=i+2*s;
	}
	//ʣ��������һ�鲻ȫ 
	if(i+s<n)	Merge(a,b,i,i+s-1,n-1);
	//ֻʣ��һ�� 
	else{
		 for(j=i;j<=n-1;j++)	b[j]=a[j];
	}
}

//��������������ϲ�������b�� 
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
