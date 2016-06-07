#include<stdio.h>
#include<stdlib.h>
#define N 3
#define SB 3
typedef struct stu

{
	char name[15];
	char num[15];
	float score[SB];
}STU;
int main()
{
	STU s[N];
	int i,j;
	FILE *fp1,*fp2;
	fp1=fopen("wenjian1.txt","wt");
	if(fp1==NULL)
	{
		printf("error\n");
		exit(0);
	}
//	printf("please input name,num\n");
	for(i=0;i<N;i++)
	{	printf("please input name,num\n");
		scanf("%s%s",s[i].name,s[i].num);
		printf("1:yuwen,2:math,3:engliah\n");
		for(j=0;j<SB;j++)
			scanf("%f",&s[i].score[j]);
	}
	for(i=0;i<N;i++)
	{
		fprintf(fp1,"%s%s",s[i].name,s[i].num);
		for(j=0;j<SB;j++)
			fprintf(fp1,"%f",s[i].score[j]);
	}
	fclose(fp1);
	fp2=fopen("wenjian1.txt","rt");
	printf("output\n");
	for(i=0;i<N;i++)
	{
		fscanf(fp2,"%s%s",s[i].name,s[i].num);
		printf("%s%s",s[i].name,s[i].num);
		for(j=0;j<SB;j++)
		{
			fscanf(fp2,"%f",&s[i].score[j]);  
			printf("%f",s[i].score[j]);
		}
	}
	fclose(fp2);
}
