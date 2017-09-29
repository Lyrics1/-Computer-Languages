#include <stdio.h> 
int m[20][20];//前i个物品装入容量为j的背包中获得的最大价值

int max(int a,int b); 

int KnapSack(int n,int w[],int v[],int x[],int c);

int main(void)
{
    int s;	
    int w[20];	//重量
    int v[20];	//价值
    int x[20];	//选取状态
    int n,i;
    int c;	//背包容量
    printf("请输入背包的最大容量:\n");
    scanf("%d",&c);
    printf("输入物品数:\n");
    scanf("%d",&n);
    printf("请分别输入物品的重量:\n");
    for(i=1;i<=n;i++)
        scanf("%d",&w[i]);
    printf("请分别输入物品的价值:\n");
    for(i=1;i<=n;i++)
        scanf("%d",&v[i]);
    s=KnapSack(n,w,v,x,c);
    printf("最大物品价值为:\n");
    printf("%d\n",s);
	return 0;
}

int max(int a,int b)
{
   if(a<b)
   		a=b;
   	return a;
}

int KnapSack(int n,int w[],int v[],int x[],int c)
{
    int i,j,t=c;
    for(i=0;i<=n;i++)
        m[i][0]=0;
    for(j=0;j<=c;j++)
        m[0][j]=0;
    for(i=1;i<=n;i++)
        for(j=1;j<=c;j++)
            if(j<w[i])
                m[i][j]=m[i-1][j];
            else
                m[i][j]=max(m[i-1][j],m[i-1][j-w[i]]+v[i]);
    for(i=n;i>0;i--)
     {
       if(m[i][c]>m[i-1][c])
        {
            x[i]=1;
            c=c-w[i];
        }        
	    else      
	        x[i]=0;
    }                
    printf("选中的物品是:\n");
    for(i=1;i<=n;i++)
        printf("%d ",x[i]);
    printf("\n");       
    return m[n][t];     
}

