/*��Բ�����*/
#include<stdio.h>
#include<conio.h>
#define PI 3.14159
int main(void)
{
	float s,r;
	system("cls");/*�����������˻��Ի�*/ 
	printf("������뾶r:");
	scanf("%f", &r);
	if (r<0)
	{
	    printf("�뾶����С��0");
		exit(0);
	}
	s=PI*pow(r,2);
	printf("s=%.3f",s);
return 0;
}
