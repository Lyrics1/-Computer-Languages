#include<stdio.h>
#include<stdlib.h>
typedef struct Polynomial
{
	float coef;
	int expn;
	struct Polynomial *next;
}Polynomial,*linklist;


Polynomial *CreatPoly(int n)
{
	Polynomial *head,*rear,*s;
	int c,e;
	int i;
	char k,h;
	head=(Polynomial *)malloc(sizeof(Polynomial));
	 fflush(stdin);
	rear = head;
	for (i=1;i<=n;i++)
	{
		
		s=(Polynomial *)malloc(sizeof(Polynomial));
		scanf("%c%d,%d%c",&k,&c,&e,&h);
		s->coef = c;
		s->expn = e;
		rear->next = s;
		rear = s;	
	}
	rear->next=NULL;
	return (head);
}
linklist add(linklist pa,linklist pb)
 {
 	linklist qa=pa->next;
 	linklist qb=pb->next;
 	linklist headc,pc,qc;
	pc=(linklist)malloc(sizeof(struct Polynomial));
	pc->next=NULL;
    headc=pc;
	while(qa!=NULL && qb!=NULL)
	{
		qc=(linklist)malloc(sizeof(struct Polynomial));
		if(qa->expn < qb->expn)
		{
			qc->coef = qa->coef;
			qc->expn = qa->expn;
			qa=qa->next;
		}
		else if(qa->expn == qb->expn)
		{
			
			qc->coef=(qa->coef+qb->coef);
			qc->expn = qa ->expn;
			qa=qa->next;
			qb=qb->next;
		}
		else {
			qc->coef =qb->coef;
			qc->expn=qb->expn;
			qb=qb->next;
		}
		if(qc->coef!=0)
		{
	
			qc->next=pc->next;
			pc->next=qc;
			pc=qc;
		}
		else free(qc);	
	}
		while(qa!=NULL)
	{
		qc=(linklist)malloc(sizeof(struct Polynomial));
		qc->coef=qa->coef;
		qc->expn=qa->expn;
		qa=qa->next;
		qc->next=pc->next;
		pc->next=qc;
		pc=qc;
	}
	while(qb!=NULL)
	{
		qc=(linklist)malloc(sizeof(struct Polynomial));
		qc->coef=qb->coef;
		qc->expn=qb->expn;
		qb=qb->next;
		qc->next=pc->next;
		pc->next=qc;
		pc=qc;
	}
	pc->next=NULL;
 	return headc;
 }
void PrintPolyn(linklist p)
{
	
	 linklist q=p->next;
	int flag=1;
	if (!q)
	{
		putchar('0');
		printf("\n");
		return;
	}
	while (q)
	{
		if (q->coef>0 && flag!=1)    printf("+");
		if (q->coef!=1 && q->coef!=-1)
		{
			printf("%g",q->coef);
		    if (q->expn==1)  printf("X");
			else if(q->expn)printf("X^%d",q->expn);
		}
		else 
		{
			if(q->coef==1)
		{
			if(!q->expn) printf("1");
			else if (q->expn==1)  printf("X");
			else printf("X^%d",q->expn);
		}
		if(q->coef==-1)
		{
			if(!q->expn) printf("-1");
			else if (q->expn==1)  printf("-X");
			else printf("-X^%d",q->expn);
		}
		
	}
	q=q->next;
	flag++;
}
    printf("\n");
	
	
}
int main()
{   
     int n,x;
     scanf("%d",&n);
      
    linklist pa,pb,pc;
    pa=CreatPoly(n);  
    scanf("%d",&x);
   
    pb=CreatPoly(x);
    PrintPolyn(pb);
    pc=add(pa,pb);
    PrintPolyn(pc);
     
    return 0;

}
