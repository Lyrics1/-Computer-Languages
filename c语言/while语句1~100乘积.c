#include<stdio.h>
void main()
{
	float x=1;
	double y=1;
	while (x<=100)
	{
		y*=x;
		x++;
	}
	printf("%d",y);
}
