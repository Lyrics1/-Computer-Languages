#define PI 3.14159
#include <stdio.h>
void main()
{
	float r;
	float s,l; 
	scanf("%f",&r);
	s=PI*r*r;
	l=2*PI*r;
	printf("���=%6.3f,l=%5f",s,l);
}
