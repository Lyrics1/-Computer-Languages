#include<stdio.h>
#define MAX 6
typedef int ElemType;
typedef struct 
{
	ElemType elem[MAX];
	int Length;//��ǰ�������ݸ��� 
}seqList;
void init_SeqList(seqList *L)
{
	L->Length=0;//��ʼ��˳��� ���տ�ʼ��Ϊ0���� 
 }
 void input(seqList *L,int n) //ָ������ֱ�ӵ���ʵ�εĸı䣬���÷��� 
 {
 	int i;
 	for(i=2;i<n;i++)
 		{
 			printf("\n�������%d�����֣�",i-1);
			scanf("%d",&L->elem[i]);//Lָ��seqList,�е�Length,���ʵ��Ǳ��������Լ�& 
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
 		printf("\n��%d������:%d",i-1,L->elem[i]);
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
		{	printf("\n������Ԫ�ظ�����");
		i++;
		}
	  	else printf("\n������һ��С��%d������:",MAX); 
		scanf("%d",&n); 
	}while(n>=MAX-1);
	n+=2;
	input(L,n); 
	output(L,n);
	inverse(L,n);
	output(L,n);
	int x;
	printf("\n����������Ҫɾ����ֵ��");
	scanf("%d",&x);
	n=Delete(L,n,x);
	output(L,n);	 
}
