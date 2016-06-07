#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 3
 struct stu
{
    char num[15];
    char name[15];
    float score[N];
    struct stu *next;
};
struct stu *creat()/*创建链表*/ 
{
    struct stu *head,*p,*q;
	int i;
	head=(struct stu *)malloc(sizeof(struct stu));
	printf("\nnumber: ");
	scanf("%s",head->num);
	printf("\nname: ");
	scanf("%s",head->name);
	for(i=0;i<N;i++)
	{	if(i==0)
			printf("input score: yuwen   math    english\n");
		scanf("%f",&head->score[i]);
	}
	p=q=head;
	int pass;
	printf("are you continue input student information ?\n1: (yes) 0: (no)\n");
	scanf("%d",&pass);
//	scanf("%c",&pass);
	while(pass==1)
	{
		p=(struct stu *)malloc(sizeof(struct stu));
		printf("\nnumber: ");
	    scanf("%s",p->num);
        printf("\nname: ");
    	scanf("%s",p->name);
    	for(i=0;i<N;i++)
    	{	
			if(i==0)
        		printf("input score: yuwen   math    english\n");
        	scanf("%f",&p->score[i]);
    	}
		printf("are you continue input student information ?\ny/Y   1: (yes) \nn/N   0:(no)\n");
   	 	scanf("%d",&pass);
	//	scanf("%c",&pass);
	}
	p->next=NULL;
	return head;	
}
struct stu *find(struct stu *f)//查找 
{
	struct stu *p;
	p=f;
	char num[15];
	int pass;
	printf("are you find ? \n  y/Y 1:  (yes)\n  2: n/N (no)\n");
	scanf("%d",&pass);
	while(pass==1)
	{
		printf("please input the student number: ");
		scanf("%s",num);
		while(p!=NULL)
		{
			if((strcmp(num,p->num))==0)
				return p;
			p=p->next;
		}
		//return NULL;
	}
	return NULL;
}
struct stu *insert(struct stu *head)//增加 
{
	struct stu *pre,*p;
	struct stu *new;
	pre=p=head;
	int i,j;
	printf("\nare you sure to insert ?\n  1: continue\n  0: stop\n");
	scanf("%d",&j);
	if(j==1)
	{
		new=(struct stu *)malloc(sizeof(struct stu));
		printf("\nplease input the  new student information :\n");
		printf("\nnumber: ");
        scanf("%s",new->num);
        printf("\nname: ");
        scanf("%s",new->name);
        for(i=0;i<N;i++)
        {
            if(i==0)
                printf("input score: yuwen   math    english\n");
            scanf("%f",&new->score[i]);
        }
		p=p->next;
		new->next=p;
		pre->next=new;
	}
	return head;
}
struct stu *delete(struct stu *head)//删除 
{
	char number[15];
	struct stu *pre,*p;
	pre=p=head;
	printf("\n\nplease input the student  number :");
	scanf("%s",number);
	while((p!=NULL)&&((strcmp(number,p->num))!=0))
	{
	//	if((strcmp(number,p->num))!=0)
			pre=p;
			p=p->next;
	}
	if((strcmp(number,p->num))==0)
	{
		if(p==head)
			head=p->next;
		else 
			pre->next=p->next;
		free(p);
	}
	else printf("\nnot found\n");
	return head;
}
void output(struct stu *head)//输出 
{
	struct stu *p;
	p=head;
	int i,j=0;
	while(p!=NULL)
	{   if(j==0)
		printf("        num             name          yuwen   math     engliah\n\n");	
		printf("%-d:%10s%15s",j+1,p->num,p->name);
		for(i=0;i<N;i++)
			printf("%6.0f",p->score[i]);
		printf("\n");
		j++;
		p=p->next;
	}

}

	
		
			
		
	
int main()
{
	struct stu *head,*fin;
	printf("***************student's   greeds     system**************************\n");
	int i,j;
	printf("\nn  0:exit(0)\n  1 :input\n  2: find\n  3:  insert\n  4:  delete\n  5:  output\n");
	scanf("%d",&i);
	while(i!=0)
	{	
		switch(i)
		{	
			case 1:head=creat();break;
			case 2:fin=find(head);
					if(fin!=NULL)
					{
						printf("num             name          yuwen   math     engliah\n\n");
						printf(" %15s%15s",fin->num,fin->name);
					
					for(j=0;j<N;j++)
					printf("%6.0f",fin->score[i]);
					}
					else  printf("not fond \n");break; 
			case 3:fin=find(head);
					if(fin==NULL)
						printf("already   exisis \n");
					else head=insert(head);break;
			case 4:head=delete(head);break;
			case 5:output(head);break;
			

		}
		printf("\n\n0:exit(0)\n 1 :input\n 2: find\n 3:  insert\n  4:  delete\n  5:  output\n");
		scanf("%d",&i);
	}
}
	
	

	
	
