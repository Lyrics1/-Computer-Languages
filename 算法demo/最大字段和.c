#include <stdio.h>
#include <stdlib.h>

int MaxSort(int a[],int n);

int main(void)
{
	int *a,*b;
	int i,n,t;
	printf("���������鳤��:\n");
	scanf("%d",&n);
	a=(int *)malloc(sizeof(int)*n);
	b=(int *)malloc(sizeof(int)*n);
	printf("������%d������",n);
	for(i=0;i<n;i++)
		scanf("%d",&(a[i]));
	b[0]=a[0];
	//b��������a[i]֮ǰ������ֶκ� 
	for(i=1;i<n;i++){
		if(b[i-1]>0) b[i]=b[i-1]+a[i];
		else b[i]=a[i];	
	}
	t=b[0];
	for(i=1;i<n;i++)
		if(t<b[i])	t=b[i];
	printf("����ֶκ�Ϊ��%d\n",t);
	free (a);
	free (b); 
	return 0;	
}

