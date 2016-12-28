#include <stdio.h>
#include <stdlib.h>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef char DataType ;
typedef struct Node
{
   DataType data;
   struct Node * Lchild;
   struct Node * Rchild;

}BiTNode,*BiTree;

typedef struct 
{
BiTree *base;
BiTree *top;
int stacksize;

}SqStack;


void InitSqStack(SqStack  *S1) //构造一个空栈S1
{
S1->base = (BiTree)malloc(STACK_INIT_SIZE * sizeof(BiTree));
if (!S1->base)
printf("存储分配失败！");
S1->top = S1->base;
S1->stacksize = STACK_INIT_SIZE;

}
int StackEmpty(SqStack *s1)
{ 
 
if(s1->top == s1->base)
   { 
  return 1; 
 } 

   else{ 
  return 0; 
 }
}
void Push(SqStack *S1, char e)
{
if (S1->top - S1->base >= S1->stacksize)
{
S1->base = (BiTree)realloc(S1->base, (S1->stacksize + STACKINCREMENT) * sizeof(BiTree));
if (!S1->base)
printf("分配内存失败！");
else
{
S1->top = S1->base + S1->stacksize;
S1->stacksize = S1->stacksize + STACKINCREMENT;
}
}


*S1->top = e;
S1->top = S1->top + 1;//将元素压入栈中，指针上移 

}

BiTree Pop(SqStack *S1,BiTree e) //出栈
{

if (S1->top == S1->base)
printf("运算符栈已空！");
e = *(--S1->top);
return e;


}
void CreateBiTree(BiTree *root)
{
   char ch;
   ch=getchar();
   if (ch=='#')  *root=NULL;
else
{
*root=(BiTree)malloc(sizeof(BiTNode));

(*root)->data=ch;
CreateBiTree(&(*root)->Lchild);
CreateBiTree(&(*root)->Rchild);
}





}
void PrintTree(BiTree root,int h)
{
int i=0;
if (root==NULL) return;
PrintTree(root->Rchild,h+1);
for ( i=0;i<h;i++) printf("   "); 
printf("%c\n",root->data);
PrintTree(root->Lchild,h+1);
}

void PreOrder(BiTree root)
{
  if (root)
  {
    printf("%c",root->data);
	PreOrder(root->Lchild);
	PreOrder(root->Rchild);
  
  }

}
void InOrder(BiTree  root)
{
  if (root)
  {
    InOrder(root->Lchild);
	printf("%c",root->data );
	InOrder(root->Rchild);
  }

}
void PostOrder(BiTree root)
{
  if (root)
  {
    PostOrder(root->Lchild );
	PostOrder(root->Rchild );
	printf("%c",root->data );
  
  }
}
int PostTreeDepth(BiTree root)
{
   int hl,hr,h;
   if(root==NULL)  return 0;
   else{
      hl=PostTreeDepth(root->Lchild );
	  hr=PostTreeDepth(root->Rchild);
	  h = (hl>hr? hl:hr)+1;
	  return h;
   }
}

int leaf(BiTree root)
{
 int nl,nr;
 if(root==NULL) return 0;
 if ((root->Lchild==NULL) && (root->Rchild ==NULL) ) return 1;
 nl=leaf(root->Lchild);
 nr=leaf(root->Rchild);
 return(nl+nr);

 }
void PreOrder1(BiTree root) 
{ 
    SqStack S; 
InitStack(S); 
BiTNode *p; 
p=root; 
while(p!=NULL || !StackEmpty(S))
 	{ 
   if(p)

{  visit(p->data);

    Push(S,p);
     p=p->Lchild;
}
   else 
   { 
     Pop(S,&p);
      p=p->Rchild;
    }
  }
}


void main()
{
printf("请输入:"); 
BiTree p;
CreateBiTree(&p);

    int h= PostTreeDepth(p) ;
    printf("树的高度为:%d\n",h);
    

    printf("先序序列输出："); 
PreOrder(p);
printf("\n中序序列输出："); 
InOrder(p); 
printf("\n后序序列输出：");
PostOrder(p);
int layer=1; 
printf("\n二叉树打印输出结果为：\n");
    PrintTree(p,layer);
    printf("\n二叉树的叶子节点为：%d",leaf(p)) ;
  

    
 
}
