#include<stdio.h>
#include<string.h>
#define M 20
typedef struct 
{
	char ch[M];
	int len;
}SString;
int KMP(SString s,int pos,SString t,int next[])
{
	int i=pos,j=1;
	while(i<=s.len && j<=t.len)
	{
		if(j==0 || s.ch[i]==t.ch[j])
		{
			i++;
			j++;
		}
		else j=next[j];
	}
	if(j>t.len)
		return i-t.len;
	return 0;
 } 
 
 void getNext(SString s,int next[])
 {
 	int j=1,k=0;
 	next[1]=0;
 	while(j<s.len)
 	{
 		if(k==0 ||s.ch[j] == s.ch[k])
 		{
 			k++;
			 j++;
			 next[j]=k;
			 
		 }
		 else k=next[k];
	 }
 }
 
 int main()
 {
 	SString s,t;
	printf("Enter string s and t  and pos:");
	gets(s.ch);
	s.len=strlen(s.ch); 
	fflush(stdin);
	gets(t.ch);
	t.len=strlen(t.ch);
	fflush(stdin);	
	int pos;
	scanf("%d",&pos);
 	int next[t.len];
 	getNext(s,next); 
 	int locat;
	 locat=KMP(s,pos,t,next);	
	 printf("locate:%d",locat);
 }
