#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(void)
{
	int true,guess;
	srand((unsigned)time(NULL));
	true=rand()%5+1;
	printf("输入要猜的数字\n");
	scanf("%d",&true);
	if (true==guess)
	printf("猜对了~。~");
	else
	printf("猜错了o.o"); 
 } 
