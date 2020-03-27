#include<iostream>
using namespace std;
int main()
{
    long long n,i,a,s=1,h=0; 
    cin>>n;
    for(i=1;i<=n;i++)
{     a=i;
      while(a!=0)
    {  s=a*s;
       a=a-1;
    }
    h=h+s;
    s=1;
    }
    cout<<h; 
       
    
return 0;
}
