#include <stdio.h>  
int m;  
int tempcount,bestcount;  
int temp1[100]={0};  
int temp2[100]={0};  
void dfs(int t)  
{  
    if(t==m){  
        if(tempcount<bestcount){  
            bestcount=tempcount;  
            for(int i=1;i<=bestcount;i++)  
            {  
                temp2[i]=temp1[i];  
            }  
        }  
        return;  
    }  
      
      
    int temp=t/2;  
    tempcount++;  
    if(tempcount<bestcount&& t>0){  
        temp1[tempcount]=1;  
        dfs(temp);  
          
    }  
    tempcount--;  
      
    temp=3*t;  
    tempcount++;  
    if(tempcount<bestcount){  
        temp1[tempcount]=2;  
        dfs(temp);  
    }  
    tempcount--;  
      
      
}  
  
int main()  
{  
    int n;  
    scanf("%d %d",&n,&m);  
    tempcount=0;  
    bestcount=100;  
    dfs(n);  
    printf("%d\n",bestcount);  
    for(int i=bestcount;i>=1;i--){  
        if(temp2[i]==2)  
            printf("f");  
        if(temp2[i]==1)  
            printf("g");  
    }  
    printf("\n");  
    return 0;  
 }   
