#include<stdio.h>
void main()
{
	int x,sum;
	x=1;
	loop: scanf("%d",&x);
	       sum+=x;
	if (x>0)
	goto loop;/*����һ���µ�ѭ���ṹ�������ں����ĵ���*/
	printf("%d",sum);
}
