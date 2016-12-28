#include<stdio.h>
#include<stdlib.h>
#define M 100
typedef char Datetype;
typedef struct  csNode {
	Datetype data;
	struct csNode * Firstchild;
	struct csNode * Nextsibling;
}*csTree;

typedef struct storTree {
	csTree data[M];
	int top;
}*stackStor;

void  Initstack(stackStor *s) {
	*s=(stackStor)malloc(sizeof(stackStor));
	if(*s==NULL)
		return;
	(*s)->top=-1;
	

}

int IsEmpty(stackStor s) {
	if(s->top==-1)
		return 0;
	return 1;
}

void pushStack(stackStor s,csTree x) {
	if(s->top==M-1 || x==NULL)
		return;		
	s->top++;
	s->data[s->top]=x;
}
//csTree getpopstack(stackStor s) {
//	csTree x;
//	if(!IsEmpty(s))
//		return;
//	else {
////		csTree x;
//		x=(*s)->data[(*s)->top];
//	}
//
//}
csTree popstack(stackStor s) {
	if(s->top==-1)
		return NULL;
	else {
		csTree x;
		x=(s)->data[(s)->top];
		(s)->top--;
		return x;
	}

}
void CScreat(csTree *root) {
	char ch;
	ch=getchar();
	if(ch=='#')
		*root=NULL;
	else {
		*root=(csTree)malloc(sizeof(struct csNode));
		(*root)->data=ch;
		CScreat(&((*root)->Firstchild));
		CScreat(&((*root)->Nextsibling));
	}
}

void output(csTree root) {
	if(root) {
		printf("%c",root->data);
		output(root->Firstchild);
		output(root->Nextsibling);

	}
}
//树的叶子节点；
void Leaf(csTree root) {
	if(root) {
		if(root->Firstchild == NULL )
			printf("%c",root->data);
		Leaf(root->Firstchild);

		Leaf(root->Nextsibling);
	}
}

//非递归先序遍历
void peorder(csTree root) {
	stackStor s;
	csTree p;
	Initstack(&s);//初始化时如果是void 类型则要用二级指针 
	p=root;
	while(p!=NULL || IsEmpty(s)!=0) {
		
		if(p!=NULL) {
			printf("%c",p->data);
			pushStack(s,p);
			p=p->Firstchild;
		}
		 else {
		 	//中序非递归 printf("%c",p->data);
			p=popstack(s);
			p=p->Nextsibling;
		}
	}
}

//树后序非递归 应该是二叉树的中序 
//void peorderh(csTree root)
//{
//	stackStor s;
//	csTree p,q;
//	p=NULL;
//	Initstack(&s);
//	p=root;
//	q=NULL;
//	while(p!=NULL || IsEmpty(s)!=0)
//	{
//		if(p!=NULL)
//		{	pushStack(s,p);
//			p=p->Firstchild;
//			
//		}
//		else {
////				getpopstack(&s,&p);
//			
////			printf("%c",q->data);
//			if(p->Nextsibling==NULL || p->Nextsibling == q)
//			{	p=popstack(s);
//				printf("%c",p->data);
//				q=p;
//				p=NULL;
//			}
//			p=p->Nextsibling;
//		
//		}
//	 } 
// } 
 
 
int main(void) {
	csTree root,p;
	stackStor s;
	CScreat(&root);
	output(root);
	printf("\n");
	Leaf(root);
	printf("\n");
	peorder(root);
	printf("\n");


}
