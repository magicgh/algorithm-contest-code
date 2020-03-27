#include<iostream>
using namespace std;
int  a[10005]={0},b[10005]={0},f[1000005]={0},i,j,k,m,n;
int main(){
	cin>>n>>m;
    for(i=1;i<=n;i++)cin>>a[i];
    for(i=1;i<=n;i++)cin>>b[i];
    for(i=1;i<=m;i++)f[i]=999999;
    for(i=1;i<=n;i++)
      for(j=1;j<=b[i];j++)
         for(k=m;k>=a[i];k--)
         f[k]=min(f[k],f[k-a[i]]+1);
         for(i=1;i<=m;i++)
         if(f[i]!=999999)cout<<f[i]<<endl;
         else cout<<-1<<endl;
	return 0;
}
