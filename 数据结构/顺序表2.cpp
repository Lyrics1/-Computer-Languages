#include<stdio.h>
#define MAX 6
typedef int ElemType;
typedef struct 
{
	ElemType elem[MAX];
	int Length;//当前包含数据个数 
}seqList;
void init_SeqList(seqList *L)
{
	L->Length=0;//初始化顺序表 （刚开始都为0个） 
 }
 void input(seqList *L,int n) //指针类型直接导致实参的改变，不用返回 
 {
 	int i;
 	for(i=2;i<n;i++)
 		{
 			printf("\n请输入第%d个数字：",i-1);
			scanf("%d",&L->elem[i]);//L指向seqList,中的Length,访问的是变量，所以加& 
			L->Length++;
		 }
		
 }
 void  inverse(seqList *L,int n)
 {
 	int i,j,t;
 	for(i=2,j=n-1;i<=j;i++,j--)
 	{
 		t=L->elem[i];
 		L->elem[i]=L->elem[j];
 		L->elem[j]=t;
 		
	 }
 }
 void output(seqList *L,int n)
 {
  	int i;
 	for(i=2;i<n;i++)
 	{
 		printf("\n第%d个数字:%d",i-1,L->elem[i]);
	 }
 }
int  Delete(seqList *L,int n,int x)
{
	int i,j,t;
	for(i=2;i<n;i++)
	{
		if(L->elem[i]==x)
		{	t=L->elem[i];
			for(j=i;j<n;j++)
			L->elem[j]=L->elem[j+1];
			n--;
		}
		L->Length--;
	
			
	}
	return n;
}
int  main(void)
{
	seqList *L;	
	int n,i=0;
	init_SeqList(L); 
	do 
	{ 
		if(i==0)
		{	printf("\n请输入元素个数：");
		i++;
		}
	  	else printf("\n请输入一个小于%d的数字:",MAX); 
		scanf("%d",&n); 
	}while(n>=MAX-1);
	n+=2;
	input(L,n); 
	output(L,n);
	inverse(L,n);
	output(L,n);
	int x;
	printf("\n亲输入你所要删除的值：");
	scanf("%d",&x);
	n=Delete(L,n,x);
	output(L,n);	 
}
