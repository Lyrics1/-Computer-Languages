#include<stdio.h>
#include<string.h> 
#define M 20
typedef struct 
{
	char ch[M];
	int len;
}SString;

int Index(SString s,int pos,SString t)
{
	int i=pos,j=1;
	while(i<s.len && j<t.len)//����i<=s.len��ԭ����gets()��������Я��\0,���������һλƥ�䣬�����Ǵ��㿪ʼ��ģ�����û��== 
	{
		if(s.ch[i]==t.ch[j])                         
		{
			i++;
			j++;
		}
		else {
			i=i-j+2;
			j=1;
		}
	}
	printf("%d jjj=",j) ;
	if(j>=t.len)
	 	return i-t.len;
	else return 0;
}

int main()
{
	SString s,t;
	printf("Enter string s and t:");
	gets(s.ch);
	s.len=strlen(s.ch); 
	fflush(stdin);
	gets(t.ch);
	t.len=strlen(t.ch);
	fflush(stdin);	
	int i=1;
	printf("%d%d",s.len,t.len);
	int j=Index(s,i,t);
		printf("prefect %d",j); 
}


