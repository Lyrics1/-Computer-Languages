#include<stdio.h>
#include<math.h>
void main()
{
	float x,y;
	printf("ÇëÊäÈëÊı×Öx\n");
	scanf("%f",&x);
	if (x<10) 
	y=x+1;
	else if(x>=10&&x<20) 
	y=pow(x,2);
	else if(x>=20) 
	y=6*x+9;
	printf("y=%f",y);
}
