#include <stdio.h>
#include <stdlib.h>
#define M 5	//个数 
#define V 10	//体积 

void Knapsack(int w[],int v[],int m[][V+1]);

void Traceback(int m[][V+1],int w[],int x[]);

int main (void)
{
	int w[M+1],v[M+1],m[M+1][V+1],x[M+1],i,j;
	w[0]=v[0]=0;
	printf("请输入%d个物品的重量：\n",M);
	for(i=1;i<=M;i++)
		scanf("%d",w+i);
	printf("请输入%d个物品的价值：\n",M);
	for(i=1;i<=M;i++)
		scanf("%d",v+i);
	Knapsack(w,v,m);
	for(i=1;i<=M;i++){
		for(j=1;j<=V;j++)
			printf("%-8d",m[i][j]);
		printf("\n");
	}
	Traceback(m,w,x);
	for(i=1;i<=M;i++)
		printf("%-5d",x[i]);
}

void Knapsack(int w[],int v[],int m[][V+1])
{
	int i,j,jm,a,b;
	jm=(w[M]-1)>V?V:(w[M]-1);
	for(i=0;i<=jm;i++)	m[M][i]=0;
	for(i=w[M];i<=V;i++)	m[M][i]=v[M];
	for(i=M-1;i>1;i--){
		jm=(w[i]-1)>V?V:(w[i]-1);
		for(j=0;j<=jm;j++)	m[i][j]=m[i+1][j];
		for(j=w[i];j<=V;j++){
			a=m[i+1][j];
			b=m[i+1][j-w[i]]+v[i];
			m[i][j]=a>b?a:b;
		}
	}
	m[1][V]=m[2][V];
	if(V>=w[1])
		m[1][V]=m[1][V]>(m[2][V-w[1]]+v[1])?m[1][V]:(m[2][V-w[1]]+v[1]);
}

void Traceback(int m[][V+1],int w[],int x[])
{
	int i;int v=V;
	for(i=1;i<M;i++)
		if(m[i][v]==m[i+1][v])	x[i]=0;
		else{
			x[i]=1;
			v-=w[i];
		}
	x[M]=(m[M][v])?1:0;
}

