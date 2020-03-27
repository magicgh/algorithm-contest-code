#include<iostream>
using namespace std;
int F(int n)
{
int i,s=1,k=0,u=0;
if(n==0){return 0;}
if(n==1){cout<<"2(0)";return 0;}
if(n==2){cout<<"2";return 0;}
if(n==3){cout<<"2+2(0)";return 0;}
    while(s<=n){s=s*2;k++;}
      k--;
      u=n-(s/2);
      cout<<"2(";
      F(k);
      cout<<")";
      if(u>0){cout<<"+";F(u);}
      }
int main()
{
    int n;
    cin>>n;
    F(n);
    
    //system("pause");
    return 0;
}
                   
