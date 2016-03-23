#include<stdio.h>
int swap(int i,int j,int t,int g[10])
 {
 	for (i=0;i<10;i++)
		{
			for (j=0;j<9;j++)
			{
				if(g[j]>g[j+1])
				{
					t=g[j];
					g[j]=g[j+1];
					g[j+1]=t;
				}
			}
       }
        
} 
void main()
{
	int i,j,t;
	int g[10],m[101];
	printf("please input your greads\n");
	for (i=0;i<10;i++)
	scanf("%d",&g[i]);
    swap(i,j,t,&g[10]);//为了避免出现23	16	D:\c语言\错误.c	[Warning] passing argument 4 of 'swap' makes pointer from integer without a cast	
	for (i=0;i<101;i++)//在数组前加   & 就可以了 
	m[i]=0;//初始化为0 
	for (i=0;i<10;i++)
	m[g[i]]++;//统计每个成绩出现次数
	for (i=0;i<101;i++)
	{
		if (m[i]!=0)
		{
			printf("g:%d=%d\n",i,m[i]);//输出对应成绩和出现的次数 
		}
	 } 
}
