//̰��׼�򣺷ֽ�ɾ����ܶ����������������ʣ��ĴӺ���ǰ���ξ��� 
#include <stdio.h>
#define M 100
int main (void)
{
	int n,a[M]={0},t=1;
	printf("������һ����(����4)��\n");
	scanf("%d",&n);
	int k=2,i=0,j;
	while(n>=k){
		a[i++]=k;
		n-=k;
		k++;
	}
	if(n){
		//���ֽ���������һλ��ͬ�������ֽ������+1�ٶ�֮ǰ�Ľ��з��� 
		if(n==a[i-1]){
			a[i-1]++;
			n--; 
		} 
		for(j=0;j<n;j++)
			a[i-j-1]++; 
	} 
	for(j=0;j<i;j++) 
		t*=a[j];
	printf("�ֽ���Ϊ��");
	for(j=0;j<i;j++) 
		printf("%-5d",a[j]);
	 printf("\n���˻���%d",t);
	return 0;
}
