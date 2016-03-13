#include<stdio.h>
void main()
{
	float x,y;
	x=0;
	scanf("%f",&x);
	while (x>=0)
	{
		y+=x;
		scanf("%f",&x);
	}
	printf("%f",y);
 } 
