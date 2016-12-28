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

 } *StackTree;

StackTree  InitStack(BiTree s)
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
 {
 	if(!(T->next)) exit(1);
 	StackLTree s;
 	s=T->next;
 	T->next=s->next;
 	return s->top;
 }
 
 void Perorder(Bitree root,StackLTree T)
{
	
	Bitree temp;
	temp=root;
	while(temp!=NULL || T->next!=NULL )
	{
		while(temp!=NULL)
		{
			printf("%c",T->top->data);
			int i=push_Lck( T,temp);
			if(i==1) printf("right\n");
			if(T-next!=NULL)
			{
				popget_stack(T,temp);
				temp->Lchild;
				}		
	 
		
 		
	 }
}
