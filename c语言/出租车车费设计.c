#include<stdio.h>
void main()
{
	double distence,fee;
	printf("请输出公里数：\n");
	scanf("%lf",&distence);
	if (distence<0)
	{
		printf("出错"); 
	}
   if (distence>=8)    fee=7+(5*1.7)+(int)(distence-7)*2.0;
   else if(distence<8&&distence>=3)   fee=7+(int)(distence-2)*1.7;
   else 	fee=7;
   printf("您的车费为：%lf\n",fee);
   printf("谢谢，旅途愉快%c",1);
}
