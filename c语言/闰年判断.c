#include<stdio.h>
int main(void)
{
	int year;
	scanf("%d",&year);
	if (year%400==0&&year%100!=0||year%4==00)
	printf("ÈòÄê",year);
	else
	printf("Æ½Äê"); 
} 
