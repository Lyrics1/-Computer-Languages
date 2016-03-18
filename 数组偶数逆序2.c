#include<stdio.h>
int main()
{
 int n;
 printf("please input n:");
 scanf("%d",&n);
 int i,j,t,k,a[n];
 for (i=0;i<n;i++)
 {
  scanf("%d",&a[i]);
 }
 if (n%2==0)
 {
  for (i=0,j=(n/2)-1-i;i<j;i++)
 {
  t=a[i];
  a[i]=a[j];
  a[j]=t;
 }
 for (k=0,i=n/2,j=n-1-k;i<j;i++,k++)
 {
  t=a[i];
  a[i]=a[j];
  a[j]=t;
  i++;
 }
 for (i=0;i<n;i++)
 {
  printf("%d,",a[i]);
 }
}
}

