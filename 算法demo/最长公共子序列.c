#include <stdio.h>
#include <string.h>
#define N 100

void LCSLength(char *x,char *y,int a[][N],int b[][N]);

void LCS(int i,int j,char *x,int b[][N]);

int main (void)
{
	char x[N],y[N];
	int a[N][N],b[N][N];
	printf("请输入x序列和y序列：\n");
	gets(x);
	gets(y);	
	LCSLength(x,y,a,b);
	int i,j;
	printf("最长公共子序列为：\n"); 
	LCS(strlen(x),strlen(y),x,b);
	return 0;
}


void LCSLength(char *x,char *y,int a[][N],int b[][N])
{
	int i,j,m,n;
	m=strlen(x);
	n=strlen(y);
	for(i=1;i<=m;i++)	a[i][0]=0;
	for(i=1;i<=n;i++)	a[0][i]=0;
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++){
			if(x[i-1]==y[j-1]){
				a[i][j]=a[i-1][j-1]+1;
				b[i][j]=1;
			}
			else if(a[i-1][j]>=a[i][j-1]){
				a[i][j]=a[i-1][j];
				b[i][j]=2;
			}
			else{
				a[i][j]=a[i][j-1];
				b[i][j]=3;
			}
		}	
//	for(i=1;i<=m;i++){
//		for(j=1;j<=n;j++)
//		printf("%d ",a[i][j]);
//		printf("\n");
//	}
}

void LCS(int i,int j,char *x,int b[][N])
{
	if(i==0||j==0) return;
	if(b[i][j]==1){
		LCS(i-1,j-1,x,b);
		printf("%c",x[i-1]);
	}	
	else if(b[i][j]==2){
		LCS(i-1,j,x,b);
	}
	else LCS(i,j-1,x,b);
}
