#include <iostream>  
#include <algorithm>  
#include <string.h>  
#include <cstdio>  
#include <cctype>  
#include <cmath>  
#include <string>  
#include <vector>  
using  namespace std;  
int main()  
{  
  ios::sync_with_stdio(false);  
  int k,i,flag;  
  string n;  
  while(cin>>n>>k)  
  {  
    vector <char> s(n.begin(),n.end());  
    while(k--)  
    {  
      vector <char>::iterator j=s.begin();  
      i=0;  
      while(i!=s.size()-1)  
      {  
        flag=1;  
        if(s[i]>s[i+1])  
        {s.erase(j);flag=0;break;}  
        i++;j++;  
      }  
      if(flag)  
      s.erase(j);  
    }  
    for(i=0;i<s.size();i++)  
      if(s[i]!='0')break;  
    while(i!=s.size())  
      cout<<s[i++];  
    cout<<endl;  
  }  
  return 0;  
}  

