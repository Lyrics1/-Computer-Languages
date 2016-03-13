#include<stdio.h>
int main(void)
{
  float total=0,gread,aver;
  int number,x;
  printf("please input your greads");
  scanf("%d",&number);
  for (x=1;x<=number;x++)
  {
  	scanf("%f",&gread);
  	total+=gread;
  }
  aver=total/number;
  printf("%f",aver); 
  
}
