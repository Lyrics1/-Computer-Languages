#include<stdio.h>
int main()
/*逆序输出*/ 
{
  long x,y,i=0;
  printf("please input some intergets\n");
  scanf("%d",&x);
  printf("依次输出个位，十位，百位\n"); 
  do
  {
  	y=x%10;
  	x=(x-y)/10;
    printf("%d",y);
	i++;
   } while (x>0&&i<3);
 
   return 0;
}
