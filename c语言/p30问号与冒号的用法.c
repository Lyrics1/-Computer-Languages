#include<stdio.h>
int main(void)
{
	int x=3,y=2,z;
	z=x>y?++x:y++;/*���x����y����z=++x,����z=y++,��������x>y�ж��Ƿ�ִ��++x,*/ 
	 printf("%d",z);
}
