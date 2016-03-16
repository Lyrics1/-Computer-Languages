#include<stdio.h>
void main()
{
 int n,js=0,os=0,i;
 int a[n];
 printf("please input n\n");
 scanf("%d",&n);
 printf("请输入被判断的数:"); 
 for (i=0;i<n;i++)
 scanf("%d",&a[i]);
 for (i=0;i<n;i++)
 {
  if (a[i]%2==0)
  {
   os++;
   }
  else
 {
  js++;
  }
   printf("%d，",a[i]);
  } 
  printf("os=%d,js=%d\n",os,js);
}

