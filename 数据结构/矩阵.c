#include<stdio.h>
#include<stdlib.h> 
#define M 20
typedef int ElementType,Triple;
typedef struct 
{
	int row,col;
	ElementType value;
}Triple;
typedef struct 
{
	Triple data[M+1];
	int row,col,nums;
}TSMatrix;
TSMatrix * first(int m,int n,int data[])
{
	TSMatrix *A,*B,*C;
	//A=(TSMatrix *)malloc(sizeof(TSMatrix));
	int i,j;
	for(i=0;i<m;i++)
	{	
		for(j=0;j<n;j++)
		{	
			if(data[i][j]!=0)
			{	A=(TSMatrix *)malloc(sizeof(TSMatrix));
				A->data[i].value=data[i][j];
				A->data[i].row=i;
				A->data[i].col=j;
				A->nums=(m*n);
				A->row=m;
			    A->col=n;
			    break;
			}
		}
	}
	 return A;
}
int shuzu() 
{
	printf("please input row col:");
	int m,n;
	scanf("%d%d",&m,&n);
	int data[m][n];
	int i,j;
	for(i=0;i<m;i++)
	{	
		for(j=0;j<n;j++)
		{
			scanf("%d",&data[i][j]);
		}
	 } 
	return data;
}
int main(void)
{
	int *data=shuzu();
	TSMatrix *A,*B;
	first(m,n,data);
	 
}
