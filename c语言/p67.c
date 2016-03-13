#include<stdio.h>
void main()
{
	int j=11;
	switch(j)
	{
		case 1:j+=1;
		case 2:j+=2;
		default:j+=4;
		case 3:j+=3;
		case 10:j;
	}
	printf("j=%d",j);
 } 
