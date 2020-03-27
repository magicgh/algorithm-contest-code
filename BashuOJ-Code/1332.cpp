#include<iostream>
using namespace std;
int a[1000005]={0},f[1000005]={0};
int main()
{
int n,i,j,m;
    for(i=2;i<=1000;i++)
    if(a[i]==0)
    for(j=i*i;j<=1000000;j=j+i)a[j]=1;
    for(i=2;i<=1000000;i++){f[i]=f[i-1];if(a[i]==0)f[i]++;}
    while(cin>>n>>m)cout<<f[m]-f[n-1]<<endl;
    return 0;
}