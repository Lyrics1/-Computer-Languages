#include<stdio.h>
#include<stdlib.h>
#include "¶þ²æÊ÷.c" 
#define size 100


//Ë³ÐòÕ» 
typedef struct 
{
	Bitree base[size];
	int top;
	int temp;

 }*StackTree;

StackTree initstack() 
 {	StackTree s;
 	s=(StackTree)malloc(sizeof(StackTree));
	 s->top=-1;
	 return s; 
  } 
  
  //ÅÐ¿ÕÕ»
  int Empty_stack(StackTree s)
  {
  	if(s->top==-1)
  		return 0;
  	return 1;
  }
  
int push_Stack(BiTree s)
{
	if(s->top== size-1 || root == NULL)
		return 0;
	s->top++;
	s->base[s->top]=root;
	s->base[(s->top)*2]=root->Lchild;
	push_stack(root->Lchild,s);
	push_stack(root->Rchild,s);
	return 1; 	
}
 
 //Á´Õ»
// typedef struct  Node
// {
//
// 	Bitree top;
// 	struct Node *next;
// }*StackLTree;
// 
// int push_Lstack(StackLTree T,Bitree root)
// {
// 	StackLTree s;
// 	s=(StackLTree)malloc(sizeof(StackLTree));
// 	if(!s) return 0;
// 	s->top=root;
// 	s->next=T->next;
// 	T->next=s;
// 	return 1;
// } 
// 
// StackLTree popget_stack(StackLTree T,Bitree root) 
// {
// 	if(!(T->next)) exit(1);
// 	StackLTree s;
// 	s=T->next;
// 	T->next=s->next;
// 	return s->top;
// }
// 
// void Perorder(Bitree root,StackLTree T)
//{
//	
//	Bitree temp;
//	temp=root;
//	while(temp!=NULL || T->next!=NULL )
//	{
//		while(temp!=NULL)
//		{
//			printf("%c",T->top->data);
//			int i=push_Lck( T,temp);
//			if(i==1) printf("right\n");
//			if(T-next!=NULL)
//			{
//				popget_stack(T,temp);
//				temp->Lchild;
//				}		 		
//	 }
//}

 int main()
 	{
 		Bitree root;
 		creat(&root);
		 initstack();	
 		preorder(root);
 		printf("\n");
 		printf("%d\n\n",Two);
 		output(root);
 		printf("\n");
 		tree(root,1);
 		change(root);
 		preorder(root);
 		printf("\n");
		int depth=treedepth(root);
		char ph[depth];
		path(root,ph,depth);
		print(root,1);
		int leaf=leafnum(root);
		printf("%d",leaf);
 		
	 }
 	
