#include<stdio.h>
void main()
{
	double distence,fee;
	printf("�������������\n");
	scanf("%lf",&distence);
	if (distence<0)
	{
		printf("����"); 
	}
   if (distence>=8)    fee=7+(5*1.7)+(int)(distence-7)*2.0;
   else if(distence<8&&distence>=3)   fee=7+(int)(distence-2)*1.7;
   else 	fee=7;
   printf("���ĳ���Ϊ��%lf\n",fee);
   printf("лл����;���%c",1);
}
