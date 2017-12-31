#include<iostream>
#include<cstdio>
using namespace std;
int a[200010],f[200010],i,j,n,maxn;
int main()
{  cin>>n;
   for(i=1;i<=n;i++){scanf("%d",&a[i]);f[i]=-0x7fffffff/2; }
   for(i=1;i<=n;i++)
      f[i]=max(f[i-1],0)+a[i];
   maxn=-0x7fffffff/2;
   for(i=1;i<=n;i++)
      if(f[i]>maxn)maxn=f[i];
   cout<<maxn<<endl;
   return 0;
}