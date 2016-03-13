/*求两个数的最大值 */
#include<stdio.h>
void main()
{
	int a,b;
	int max;
	printf("请输入a,b:");
	scanf("%d, %d", &a, &b);
	if (a>b)
    {
	  max=a;
	}
	else
	    max=b;  
	printf("max=%d",max);    
 } 
