#include<stdio.h>
#include<stdlib.h>
#include "������.c" 
#define size 100


//˳��ջ 
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
  
  //�п�ջ
  int Empty_stack(StackTree s)
  {
  	if(s->top==-1)
  		return 0;
  	return 1;
  }
  
int push_Stack(StackTree s,Bitree root)
{
	if(s->top== size-1 || root == NULL)
		return 0;
	s->top++;
	s->base[s->top]=root;
	s->base[(s->top)*2]=root->Lchild;
	s->base[((s->top)*2+1)]=root->Rchild;
	push_Stack(s,root->Lchild);
	push_Stack(s,root->Rchild);
	return 1; 	
}
 
// ��ջ
// 

 int main()
 	{
 		Bitree root;
 		creat(&root);
 		
 		//˳��ջ�洢������ 
// 		StackTree s ;	  
// 		int i=push_Stack(s,root);
// 		printf("%d",i);
		//��ջ
//		 StackLTree T;
//		Perorder(root,T);
	//�����ʾ��������Ľ��	
		  
//		preorder(root);
//		printf("\n");
// 		printf("%d\n\n",Two);
//		output(root);
//		printf("\n");
// 		tree(root,1);
// 		change(root);
// 		preorder(root);
//		printf("\n");
//		int depth=treedepth(root);
//		char ph[depth];
//		path(root,ph,depth);
//		print(root,1);
//		int leaf=leafnum(root);
//		printf("%d",leaf);
 		
	 }
 	
