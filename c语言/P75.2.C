#include<stdio.h> 
int main(void)
{
	int x;
	scanf("%d",&x);
	if (x>0&&x%2==0)
	{
		printf("正数偶数"); 
	}
	if (x>0&&x%2!=0)
	{
		printf("正数奇数"); 
	 }
	 if (x<0&&x%2==0)
	 {
	 	printf("负数偶数"); 
	 }
	 if (x<0&&x%2!=0)
	 {
	 	printf("负数奇数"); 
	 }
}
