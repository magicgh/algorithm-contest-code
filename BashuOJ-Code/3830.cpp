#include<iostream>
using namespace std;
int n,x,c=0,i=1,a=0,b=0,f;
int main(){
    cin>>n>>x;
    for(i=1;i<=n;i++)
    {
      f=i;
      while(f!=0)
      {
         a=f%10;
         f=f/10;
         if(a==x)b++;
           }
           }
           cout<<b;
           
    return 0;
}