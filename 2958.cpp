#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
long long n,m,a[1005][1005],f[1005][1005],g[1005][1005];
int main(){
	cin>>n>>m;
	memset(a,0,sizeof(a));
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
	for(int i=1;i<=n;i++)
	   for(int j=1;j<=m;j++)cin>>a[i][j];
	for(int i=1;i<=n;i++)
	   for(int j=1;j<=m;j++)
	   {
	   	int k=0,t=a[i][j];
	   	while(t%2==0){t/=2,k++;}
	   	f[i][j]=k;
	   	k=0,t=a[i][j];
	   	while(t%5==0){t/=5;k++;}
	   	g[i][j]=k;
	   }
	   for(int i=2;i<=n;i++)
	   {
	   	f[i][1]+=f[i-1][1];
	   	g[i][1]+=g[i-1][1];
	   }
	    for(int i=2;i<=m;i++)
	   {
	   	f[1][i]+=f[1][i-1];
	   	g[1][i]+=g[1][i-1];
	   }
	   for(int i=2;i<=n;i++)
	   for(int j=2;j<=m;j++)
	   {
	   	f[i][j]+=min(f[i-1][j],f[i][j-1]);
	   	g[i][j]+=min(g[i-1][j],g[i][j-1]);
	   }
	   cout<<min(f[n][m],g[n][m]);
	return 0;
}
