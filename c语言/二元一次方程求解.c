#include<stdio.h>
#include<math.h>
void main()
{
	float a,b,c,t,x1,x2,x;
	printf("�������Ԫһ�η��̵�ϵ��a,b,c\n");
	scanf("%f%f%f",&a,&b,&c);
	t=pow(b,2)-(4*a*c);
	x1=((-b)+sqrt(t))/(2*a);
	x2=((-b)-sqrt(t))/(2*a);
	x=-c/b;
	if (a=0)
	printf("���Ƕ�Ԫһ�η���,Ϊһ�η��̽�Ϊ��\nx=%f",x);
	else
	{
		if (t>0)
		printf("������������ͬ�Ľ⣺\nx1=%f,x2=%f",x1,x2);
		else if (fabs(t)==0)
		printf("������������ͬ�Ľ�:\nx1=x2=%f",x1);
		else
		{
		printf("��������������Ľ�:\nx1=%8.4f+%8.4fi\n",-b/2*a,sqrt(t)/2*a);
		printf("x1=%8.4f+%8.4fi",-b/2*a,-sqrt(t)/2*a); 	
		 }
	 } 
}
