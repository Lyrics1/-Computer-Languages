#include<stdio.h>
int main()
/*�������*/ 
{
  long x,y,i=0;
  printf("please input some intergets\n");
  scanf("%d",&x);
  printf("���������λ��ʮλ����λ\n"); 
  do
  {
  	y=x%10;
  	x=(x-y)/10;
    printf("%d",y);
	i++;
   } while (x>0&&i<3);
 
   return 0;
}
