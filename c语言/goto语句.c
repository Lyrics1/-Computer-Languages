#include<stdio.h>
void main()
{
	int x,sum;
	x=1;
	loop: scanf("%d",&x);
	       sum+=x;
	if (x>0)
	goto loop;/*构成一个新的循环结构，类似于函数的调用*/
	printf("%d",sum);
}
