#include<iostream>
using namespace std;
int main()
{
    string a,b;
    cin>>a>>b;
    int i,n,s,j,sa=1,sb=1;
    s=a.length();
    n=b.length();
    for(i=0;i<=s;i++)
    {
      sa=((a[i]-'A'+1)*sa)%47;
      }
      for(j=0;j<=n;j++)
      {
        sb=((b[j]-'A'+1)*sb)%47;
        }
        
        if(sa==sb)
        {
          cout<<"GO";
          }
          if(sa!=sb) 
          {
               cout<<"STAY";
               }
        
      
      
        
    
//system("pause");
return 0;
}
