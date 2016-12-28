#include<stdio.h>
#include<stdlib.h> 
#define M 20
#include"������ջl.c"

//˳��洢 
//typedef struct
//{
//	int tree[M+1];
//	int last;
// }Bittree;
 int Two=0;
typedef struct Nodetree
{
	int data;
	struct Nodetree *Lchild;
	struct Nodetree *Rchild;
	int Ltag;//�����������Ķ��� 
	int Rtag;
 } *Bitree;
 
  
 //��������
 void creat(Bitree *root);
 void output(Bitree root);
 void preorder(Bitree root);
 void change(Bitree root);
 int path(Bitree root,char ph[],int len);
 int treedepth(Bitree root);
 void print(Bitree root,int loop);
 int push_Lstack(StackLTree T,Bitree root);
 Bitree popget_stack(StackLTree T,Bitree root) ;
 void Perorder(Bitree root,StackLTree T);
 	
  
 	//���� 
 	void creat(Bitree *root)
 {
 	char ch;
 	ch=getchar();
	if(ch=='#')
		*root=NULL;
	else {
	 		*root=(Bitree)malloc(sizeof(struct Nodetree));
	 		(*root)->data=ch;
	 		creat(&((*root)->Lchild));
	 		creat(&((*root)->Rchild));
		 }
 }
 
 //�����������Ľ���
// Bitree pre=NULL;
// void Tcreate (Bitree *root)
// {
//	if(root)
//	{
//		if((*root)->Lchild != NULL)
//				(*root)->Ltag=0;	
//		else {
//			(*root)->Ltag = 1;
//			(*root)->Lchild=*pre;//d->qian=b; g->qian=d;
//		}
//		*pre=*root;	//a,b,d,g
//		if((*root)->Rchild != NULL)    //b,
//			(*root)->Rtag=0;
//		else {
//				(*root)->Rtag=1;
//				(*root)->Rchild=(*root)->Lchild;    //b->hou=D ; g->hou=d.;
//			}
////		root=pre;
//		Tcreate(&(*root)->Lchild);
//		
//		Tcreate(&(*root)->Rchild);
//}
//	
//	 
 // } 
 //��� 
 void output(Bitree root)
 {
 	if(root)
 	{
 			printf("%c",root->data);
 	output(root->Lchild);
 	output(root->Rchild);
	 }
 
 }
 //�����õ���Ϊ2�� 
 void preorder(Bitree root)
 {
 	if(root)
 	{
 		if(root->Lchild!=NULL && root->Rchild!=NULL)
 			Two++;
 		printf("%c",root->data); 
 		preorder(root->Lchild);
 		preorder(root->Rchild);
	 }
	
 }
 //���ҽ��� 
 	void change(Bitree root)
 	{
 		Bitree temp; 
 		if(root)
 		{
 			temp=root->Lchild;
 			root->Lchild=root->Rchild;
 			root->Rchild=temp;
 			change(root->Lchild);
 			change(root->Rchild);
 			
		 }
	 }
 
//��·����� 
int path(Bitree root,char ph[],int len)
 {
 	int i;
	if(root)
	{
		if(root->Lchild==NULL && root->Rchild==NULL)
		{	ph[len]=root->data;
			printf("%c: ",ph[len]); 
			for(i=0;i<len;i++)
				printf("%c",ph[i]);
			printf("\n");
			return 0;
		}
		ph[len]=root->data;
		path(root->Lchild,ph,len+1);
		path(root->Rchild,ph,len+1);
	 } 	
 }
 //shu����� 
 int treedepth(Bitree root)
 {
 	int l,r,h;
 	if(root)
 		return 0;
	l=treedepth(root->Lchild);
	r=treedepth(root->Rchild);
	h=l>r? l:r;
	return h+1;	
 }
 
 //�Զ�Ԫ�������A,1)
 void print(Bitree root,int loop)
 {
 	if(root)
 	{
 		printf("(%c,%d) ",root->data,loop);
 		print(root->Lchild,loop+1);
 		print(root->Rchild,loop+1);
 		
	 }
  } 
  //Ҷ�ӽڵ����Ŀ 
  int leafnum(Bitree root)
  {
  	int l,r;
  	if(root==NULL) 
  		return 0;
  	if(root->Lchild==NULL && root->Rchild==NULL)
  		return 1;
  	l=leafnum(root->Lchild);
  	r=leafnum(root->Rchild);
  	return l+r;
  }
  
  //�������
  
  void tree(Bitree root,int h)
  {
  	if(root==NULL)
  		return;
  	tree(root->Rchild,h+1);
  	int i=0;
  	for(i=0;i<h;i++)
  		printf("    ");
	printf("%c\n",root->data);	
	tree(root->Lchild,h+1);
	 
   } 
// int main()
// 	{
// 		Bitree root;
// 		creat(&root);	
// 		preorder(root);
// 		printf("\n");
// 		printf("%d\n\n",Two);
// 		output(root);
// 		printf("\n");
// 		tree(root,1);
// 		change(root);
// 		preorder(root);
// 		printf("\n");
//		int depth=treedepth(root);
//		char ph[depth];
//		path(root,ph,depth);
//		print(root,1);
//		int leaf=leafnum(root);
//		printf("%d",leaf);
// 		
//	 }
// 	
