#include<stdio.h>
#include<stdlib.h>
typedef struct Lnode
{
	int number;
	int passward;
	struct Lnode *next;
}*LinkList;
LinkList  creat_List(int n)
{	
	LinkList H,p,r;
	H=(LinkList)malloc(sizeof(LinkList));
	scanf("%d",&H->passward);
	H->number=1;
	r=p=H;
	int i;
	for(i=0;i<n-1;i++){
		p=(LinkList)malloc(sizeof(LinkList));
		scanf("%d",&p->passward);
		p->number=i+2;
		r->next=p;
		r=p;
	}
	p->next=H;
	return H;
}
void out_passward(LinkList H,int m,int n)
{
	int i,j,pass=0,password=0;
	LinkList p,r,temp;
	temp=p=r=H;
	for(j=1;j<=n;j++)
	{		
			
	
		for(i=1;i<=m;i++)
		{temp=p;
			if(i==m)
				{
					p=p->next;
					r->next=p;
					printf("%d ",temp->number);
					m=temp->passward;
					
					free(temp);	
					break;
				}
				r=p;
				p=p->next;
				temp=p;
				}
		}
	}	
 
int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	LinkList Head,p;
	Head=creat_List(n);
	out_passward(Head,m,n);	
 } 
