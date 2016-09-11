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
		
		scanf("%d%d",&s->index,&s->coef);
		printf("\n");
		r->next=s;
		r=s;
	 }
	 return Head;
 }
 
 void output(LinkList Head)
 {	int flag=1;
 	LinkList p=Head->next;
 	 printf("\n");
 	while(p)
	 {
	 	if(p->coef>0&&flag!=1)
	 		printf(" + ");
	 	if(p->coef!=1&&p->coef!=-1)
	 	{
	 		printf("%d",p->coef);
	 		if(p->index==1)
	 			printf("X");
	 		else if(p->index)printf("X ^ %d",p->index);
		 }
		 else
		 {
		 	if(p->coef==1)
		 	{
		 		
		 		if(p->index==1)
		 			printf("X");
		 		else if(p->index==0)
		 			printf("1");
		 		else printf("X ^ %d",p->index);	
			 }
			 else {
			 	if(p->index==1)
		 			printf("-X");
		 		else if(p->index==0)
		 			printf("1");
		 		else printf("-X ^ %d",p->index);	
			 }
		 }
			p=p->next;
	  		flag++;
	  } 
	  printf("\n");
	  
 }

 LinkList add(LinkList Head1,LinkList Head2)
 {
 	LinkList p1=Head1->next;
 	LinkList p2=Head2->next;
 	LinkList Head3,p3,r;
	Head3=(LinkList)malloc(sizeof(LNode));
	Head3->next=NULL;
	r=Head3;
	while(p1!=NULL&&p2!=NULL)
	{
		p3=(LinkList)malloc(sizeof(LNode));
		if(p1->index<p2->index)
		{
			p3->index=p1->index;
			p3->coef=p1->coef;
			p1=p1->next;
		}
		else if(p1->index==p2->index)
		{
			p3->index=p1->index;
			p3->coef=(p1->coef+p2->coef);
			p1=p1->next;
			p2=p2->next;
		}
		else {
			p3->index=p2->index;
			p3->coef=p2->coef;
			p2=p2->next;
		}
		if(p3->coef!=0)
		{
		//	p3->next=r->next;
			r->next=p3;
			r=p3;
		}
		else free(p3);	
	}
	
	while(p1!=NULL)
	{
		p3=(LinkList)malloc(sizeof(LNode));
		p3->coef=p1->coef;
		p3->index=p1->index;
		p1=p1->next;
		r->next=p3;
		r=p3;
	}
	while(p2!=NULL)
	{
		p3=(LinkList)malloc(sizeof(LNode));
		p3->coef=p2->coef;
		p3->index=p2->index;
		p2=p2->next;
		r->next=p3;
		r=p3;
	}
 	return Head3;
 }
 
LinkList subtract(LinkList Head1,LinkList Head2)
{
	LinkList p4=Head2,p,h,q;
	h=p=Head2->next;
	while(p!=NULL)
	{
		p->coef*=-1;
		p=p->next;		
	}
	q=add(Head1,p4);
	while(h!=NULL)
	{
	        h->coef*=-1;
        h=h->next;
    }

	return q;
}

LinkList multiplication(LinkList Head1,LinkList Head2)
{
	LinkList p1=Head1->next,p2=Head2->next;
	LinkList p3,p,q,Head,r;
	Head=(LinkList)malloc(sizeof(LNode));
	Head->next=NULL;
	q=Head;
	r=p2;
	p3=Head->next;
	while(p1!=NULL)
	{	p2=Head2->next;
		
		while(p2!=NULL)
		{   p3=(LinkList)malloc(sizeof(LNode));	
		   	p3->coef=(p1->coef*p2->coef);
			p3->index=(p1->index)+(p2->index);
			q->next=p3;
			q=p3;
			p2=p2->next;
		}
		
		p1=p1->next;
	}
	
	
	
	
	return Head;
}

LinkList dao(LinkList Head)
{
	LNode *p1,*p2,*r,*new,*k;
	LinkList Head1;
	r=Head->next;
	Head1=(LinkList)malloc(sizeof(LNode));
	Head1=Head;
	k=Head1->next;
	while(r!=NULL)
	{
		new=(LinkList)malloc(sizeof(LNode));
		new->coef=r->coef;
		new->index=r->index;		
		k->next=new;
		k=new;
	} 
	Head->next=new;
	p2=Head1;
	p1=Head1->next;
	
	while(p1!=NULL)
	{
		if(p1->index==0)
		{
			p2->next=p1->next;
			free(p1);
		}
		
		else
			p1->index--;
	}
	return Head1;
			
}
void inverse(LinkList Head)
{
	LinkList p,r,q,temp;
	temp=Head->next;
	q=temp;
	p=temp->next;
	while(p!=NULL)
	{	
		r=p->next;
		p->next=temp;
		Head->next=p;
		temp=p;
		p=r;
	}
	q->next=NULL;
	
}
void out(LinkList Head)
{
	LinkList p;
	p=Head->next;
	while(p!=NULL)
	{
		printf("%d  %d  ",p->coef,p->index);
	}
}
 int main(void)
 {
 	LNode *Head1,*Head2,*Head3_add,*Head4_subtract,*Head_multiplication;
 	int m,n;
 	printf("\n请输入多项式1 和 多项式2 的项数m  n:");
 	scanf("%d%d",&m,&n);
 	Head1=creat_LinkList(m,1);
 	Head2=creat_LinkList(n,2);
 	output(Head1);
 	output(Head2);
 	Head3_add=add(Head1,Head2);
 	output(Head3_add);
	Head4_subtract=subtract(Head1,Head2);
	output(Head4_subtract);		
	Head_multiplication=multiplication(Head1,Head2);
/*	Head_multiplication=add(Head_multiplication,Head_multiplication);
	LinkList p=Head_multiplication->next;
	while(p!=NULL)
	{
		p->coef=(p->coef)/2;
	}*/
	output(Head_multiplication);
/*	LNode *Head1_dao,*Head2_dao;
	Head1_dao=dao(Head1);
	output(Head1_dao);
	Head2_dao=dao(Head2);
	output(Head2_dao);*/
//	inverse(Head1);
//	out(Head1);
 }
 
