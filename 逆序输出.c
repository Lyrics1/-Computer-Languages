#include<stdio.h>
int main()
/*ÄæĞòÊä³ö*/ 
{
  long x,y;
  printf("please input some intergets\n");
  scanf("%d",&x);
  do
  {
  	y=x%10;
  	x=(x-y)/10;
  	printf("%d",y);
   } while (x>10);
   if (x>=0)
   printf("%d",x);
   return 0;
}
input github;
zhangfan 
