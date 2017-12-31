#include<iostream>
using namespace std;
long a[10005]={0},f[10005]={0},i,j,k,m,n;
int main(){
	cin>>n>>m;
    for(i=1;i<=n;i++)cin>>a[i];
    for(i=1;i<=m;i++)f[i]=99999;
    for(i=1;i<=n;i++)
      for(j=a[i];j<=m;j++)
         f[j]=min(f[j],f[j-a[i]]+1);
         for(i=1;i<=m;i++)
         if(f[i]==99999)cout<<-1<<endl;
         else cout<<f[i]<<endl;
	return 0;
}
