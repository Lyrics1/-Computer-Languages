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
    swap(i,j,t,&g[10]);//Ϊ�˱������23	16	D:\c����\����.c	[Warning] passing argument 4 of 'swap' makes pointer from integer without a cast	
	for (i=0;i<101;i++)//������ǰ��   & �Ϳ����� 
	m[i]=0;//��ʼ��Ϊ0 
	for (i=0;i<10;i++)
	m[g[i]]++;//ͳ��ÿ���ɼ����ִ���
	for (i=0;i<101;i++)
	{
		if (m[i]!=0)
		{
			printf("g:%d=%d\n",i,m[i]);//�����Ӧ�ɼ��ͳ��ֵĴ��� 
		}
	 } 
}
