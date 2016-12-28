#include <stdio.h>
#include <stdlib.h>
typedef struct Polynomial
{
	long int coef;	
	int exp;	 
	struct Polynomial *next;
}Polyn;

Polyn *CreatePoly(int n);
void PrintPoly(Polyn *p);
Polyn *AddPoly(Polyn *a,Polyn *b);
Polyn *SubPoly(Polyn *a,Polyn *b);

int main (void)
{
	Polyn *t,*s,*a;
	int m,n;
	printf("Enter first number of the cofe ,输入第一个和第二个多项式的非零项数");
	scanf("%d",&m);
	
	t=CreatePoly(m);
	scanf("%d",&n);
	s=CreatePoly(n);
	a=SubPoly(t,s);
	PrintPoly(a);
	return 0;
}

Polyn *CreatePoly(int n)
{
	Polyn *h,*r,*s;
	int c,e,i;
	char a,b;
	h=(Polyn *)malloc(sizeof(Polyn));	 
	r=h;	 
	getchar();
	for(i=0;i<n;i++)
	{	printf("输入格式　（系数，指数）："); 
		scanf("%c%d,%d%c",&a,&c,&e,&b);
		s=(Polyn *)malloc(sizeof(Polyn));
		s->coef=c;
		s->exp=e;
		r=r->next=s;
	}
	r->next=NULL;
	return h;
}

void PrintPoly(Polyn *p)
{
	Polyn *q=p->next;
	int flag=1;
	if(!q){
		putchar('0');
		printf("\n");
		return;
	}
	while(q){
		if(q->coef>0&&flag!=1)	putchar('+');
		if(q->coef-1&&q->coef!=-1){
			printf("%g",q->coef);
			if(q->exp==1)	putchar('X');
			else if(q->exp)	printf("X^%d",q->exp);
		}
		else{
			if(q->coef==1){
				if(!q->exp)	putchar('1');
				else if(q->exp==1)	putchar('X');
				else printf("X^%d",q->exp);
			}
			if(q->coef==-1){
				if(!q->exp)	printf("-1");
				else if(q->exp==1)	printf("-X");
				else printf("-X^%d",q->exp); 
			}
		}
		q=q->next;
		flag++;
	}
}

Polyn *AddPoly(Polyn *a,Polyn *b)
{
	Polyn *p=a->next,*q=b->next,*h,*pc,*qc;
	pc=(Polyn *)malloc(sizeof(Polyn));
	pc->next=NULL;
	h=pc;
	while(p&&q){
		qc=(Polyn *)malloc(sizeof(Polyn));
		if(q->exp>p->exp){
			qc->coef=p->coef;
			qc->exp=p->exp;
			p=p->next;
		}
		else if(p->exp==q->exp){
			qc->coef=p->coef+q->coef;
			qc->exp=p->exp;
			p=p->next;
			q=q->next;
		}
		else{
			qc->coef=q->coef;
			qc->exp=q->exp;
			q=q->next;
		}
		if(qc->coef){
			qc->next=pc->next;
			pc->next=qc;
			pc=qc;
		}
		else free(qc);
	}
	while(p){
		qc=(Polyn *)malloc(sizeof(Polyn));
		qc->coef=p->coef;
		qc->exp=p->exp;
		p=p->next;
		qc->next=pc->next;
		pc->next=qc;
		pc=qc;
	}
	while(q){
		qc=(Polyn *)malloc(sizeof(Polyn));
		qc->coef=q->coef;
		qc->exp=q->exp;
		q=q->next;
		qc->next=pc->next;
		pc->next=qc;
		pc=qc;
	}
	return h;
}

Polyn *SubPoly(Polyn *a,Polyn *b)
{
	Polyn *h=b,*p=b->next,*t;
	while(p){
		p->coef*=-1;
		p=p->next;
	}
	t=AddPoly(a,h);
	for(p=h->next;p;p=p->next)
	p->coef*=-1;
	return t;
}

