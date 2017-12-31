#include<iostream>
using namespace std;
int n,a[10025]={0},t[10025]={0},f[10025]={0},total=0,i,j;
int main()
{
     int v,i;  
         cin>>v>>n;
            for(i=1;i<=n;i++)cin>>a[i]>>t[i];
          for(i=1;i<=n;i++)
            for(j=v;j>=a[i];j--)
            {
            f[j]=max(f[j],f[j-a[i]]+t[i]);
            }
            cout<<f[v];
    return 0;
}