#include<stdio.h>
#include<stdlib.h> 
#define M 5

//Ë³Ðò´æ´¢ 
//pedef struct
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
 } *Bitree;
 	
 	
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
// void output(Bitree root)
// {
// 	
// }
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
 
 	void change(Bitree root,Bitree root1)
 	{
 		Bitree temp; 
 		if(root)
 		{
 			temp=root->Lchild;
		 }
	 }
 
 int main()
 	{
 		Bitree root;
 		creat(&root);	
 		preorder(root);
 		printf("%d",Two);
 		
	 }
