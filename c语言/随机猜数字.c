#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(void)
{
	int true,guess;
	srand((unsigned)time(NULL));
	true=rand()%5+1;
	printf("����Ҫ�µ�����\n");
	scanf("%d",&true);
	if (true==guess)
	printf("�¶���~��~");
	else
	printf("�´���o.o"); 
 } 
