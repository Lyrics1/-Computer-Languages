#include<stdio.h>
int main(void)
{
	int age,money;
	float price;
	char f;
	printf("请输入年龄和普通票价age,price:");
	scanf("%d %d",&age,&money);
	if (age<=12)
	   money=10;
    if (age>=60);
       money=price*0.3;
     printf("money=%f",money);
return 0;
	       
	
}
