#include<stdio.h>
#include<stdlib.h>
#define N 10
int input(float score[],int n )
{
	int i;
	printf("输入成绩\n");
	for(i=0;i<n;i++)
		scanf("%f",&score[i]);
}
int paixu(float score[],int n,float *max,float *min,float *ave)
{
	int i,j;
	float t,sum=0;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
			if(score[i]<score[j])
			{
				t=score[i];
				score[i]=score[j];
				score[j]=score[i];
			}
		sum+=score[i];
	}
	*ave=sum/n;
	*max=score[0];
	*min=score[n-1];
}
int greads(float score[],int n,float *jg)
{	int i,t,j=0,k=0,w=0;
	 float a[n],b[n],c[n];
	for(i=0;i<n;i++)
	{	if(score[i]>=60)
		{	t++;
			if(score[i]>=60&&score[i]<=80)
			{	b[j]=score[i];j++;}
			if(score[i]>80&&score[i]<=100)
			{   c[k]=score[i];k++;}
		}
		else { a[w]=score[i];w++;}	
	}
	*jg=(t*1.0/n);
	a[w]='\0';
	b[j]='\0';
	c[k]='\0';
	for(i=0;i<w;i++)
		printf("%f",a[i]);
	for(i=0;i<j;i++)
		printf("%f",b[i]);
	for(i=0;i<k;i++)
		printf("%f",c[k]);
}
				
		
int main()
{
	float score[N],max=0,min=0,ave=0,jg=0;//jg=jigelv
	int n,choice,i;
	 printf("             成绩管理系统                  \n");
    printf("输入1：输入学生成绩： \n");
	printf("输入2：查询平均值，最高分，最低分：\n");
	printf("输入3：统计分数段人数和及格率\n");
	printf("输入4：学生成绩排序输出：\n");
	printf("输入0：退出查询\n");
	printf("请输入人数\n");
	scanf("%d\n",&n);
	printf("输入选项\n");
	scanf("%d",&choice);
	do
	{
		switch(choice)
	    {
     	    case 0:printf("你已退出查询：\n");exit(0);
       	    case 1:input(score,n);break;
		    case 2:paixu(score,n,&max,&min,&ave);
					printf("max=%f,min=%f,ave=%f",max,min,ave);break;
			case 3:greads(score,n,&jg);
					printf("及格率：%f",jg);break;
			case 4:paixu(score,n,&max,&min,&ave);
					for(i=0;i<n;i++)
						printf("%f ",score[i]);break;
		}
	}while(n!=0);
}
			

		
		
		

	
