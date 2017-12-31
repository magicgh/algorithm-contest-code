#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int gcd(int a,int b)
{
    if(b==0)return a;
    else return gcd(b,a%b);
}
int main(){
    int n,a[105]={0};
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
       long long t1=gcd(a[1],a[2]),t2=a[1]*a[2]/t1,t3=0;
    for(int i=3;i<=n;i++)
    {
        t1=gcd(t1,a[i]);
        t3=gcd(t2,a[i]);
        t2=t2*a[i]/t3;
    }
    cout<<t1<<endl<<t2;
    return 0;
}