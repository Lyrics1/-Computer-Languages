#include <stdio.h> 
int m[20][20];//ǰi����Ʒװ������Ϊj�ı����л�õ�����ֵ

int max(int a,int b); 

int KnapSack(int n,int w[],int v[],int x[],int c);

int main(void)
{
    int s;	
    int w[20];	//����
    int v[20];	//��ֵ
    int x[20];	//ѡȡ״̬
    int n,i;
    int c;	//��������
    printf("�����뱳�����������:\n");
    scanf("%d",&c);
    printf("������Ʒ��:\n");
    scanf("%d",&n);
    printf("��ֱ�������Ʒ������:\n");
    for(i=1;i<=n;i++)
        scanf("%d",&w[i]);
    printf("��ֱ�������Ʒ�ļ�ֵ:\n");
    for(i=1;i<=n;i++)
        scanf("%d",&v[i]);
    s=KnapSack(n,w,v,x,c);
    printf("�����Ʒ��ֵΪ:\n");
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
    printf("ѡ�е���Ʒ��:\n");
    for(i=1;i<=n;i++)
        printf("%d ",x[i]);
    printf("\n");       
    return m[n][t];     
}

