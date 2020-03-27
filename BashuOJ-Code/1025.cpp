#include<iostream>
using namespace std;
long n,t=0,a[4]={6,2,4,8};
int main()
{
    cin>>n;
    if(n<=1){cout<<1<<endl;return 0;}
    while(n)
    {
       t+=(n%5==2)+(n%5==4)*2+n/5;    
       n/=5;
      }
      cout<<a[t%4]<<endl;
      return 0;
      }
