//贪心准则：分解成尽可能多的连续递增的数，剩余的从后向前依次均分 
#include <stdio.h>
#define M 100
int main (void)
{
	int n,a[M]={0},t=1;
	printf("请输入一个数(大于4)：\n");
	scanf("%d",&n);
	int k=2,i=0,j;
	while(n>=k){
		a[i++]=k;
		n-=k;
		k++;
	}
	if(n){
		//若分解的数和最后一位相同，则最后分解的数先+1再对之前的进行分配 
		if(n==a[i-1]){
			a[i-1]++;
			n--; 
		} 
		for(j=0;j<n;j++)
			a[i-j-1]++; 
	} 
	for(j=0;j<i;j++) 
		t*=a[j];
	printf("分解结果为：");
	for(j=0;j<i;j++) 
		printf("%-5d",a[j]);
	 printf("\n最大乘积：%d",t);
	return 0;
}
