#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct node
{
	ElemType index;
	ElemType coef;
	struct node *next;
 } LNode,*LinkList;
 LinkList creat_LinkList(int n,int j)
 {
 	LinkList Head=(LinkList)malloc(sizeof(LinkList));
 	Head->next=NULL;
 	LNode *s,*r=Head;
 	int i,Index,Coef;
 	for(i=0;i<n;i++)
 	{
 		s=(LinkList)malloc(sizeof(LNode));
 		printf("\nplease input dploy%d index(指数) and coef(系数)：",j);
		
		scanf("%d",&s->index);
		printf("\n");
		r->next=s;
		r=s;
	 }
	 return Head;
 }
 
 
void inverse(LinkList Head)
{
	LinkList p,q;
	p=Head->next;
	Head->next=NULL;
	while(p)
	{
		q=p;
		p=p->next;
		q->next=Head->next;
		Head->next=q;
	}
	
}
	
void out(LinkList Head)
{
	LinkList p;
	p=Head->next;
	while(p!=NULL)
	{
		printf("%d    ",p->index);
		p=p->next;
	}
}

void split(LinkList Head)
{
	LinkList p,q,t,r;
	q=Head;
	t=p=Head->next;
	r=p->next;
	while(r!=NULL)
	{
			if(r->index<p->index)
			{
				t->next=r->next;
				r->next=p;
				q->next=r;
				p=r;
				r=t->next;
			}
			else {
			r=r->next;
			t=t->next;

				}					
	}
}

 int main(void)
 {
 	LNode *Head1,*Head2,*Head3_add,*Head4_subtract,*Head_multiplication;
 	int m,n;
 	printf("\n请输入多项式1 和 多项式2 的项数m  n:");
 	scanf("%d",&m);
 	Head1=creat_LinkList(m,1);
	out(Head1);	
// 	Head2=creat_LinkList(n,2);
//	inverse(Head1);
	printf("shuchu");
	split(Head1);
	out(Head1);
	
 }
 
