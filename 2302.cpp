#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int m,n,a[105][105],f[155][105][105];
int main(){
cin>>m>>n;
memset(a,0,sizeof(a));
memset(f,0,sizeof(f));
for(int i=1;i<=m;i++)
   for(int j=1;j<=n;j++)cin>>a[i][j];
   for(int k=3;k<=m+n;k++)
      for(int i=1;i<=m;i++)
         for(int j=i+1;j<=m;j++)
         {
         	int Max=-0x7fffffff;
         	Max=max(Max,f[k-1][i][j]);
         	Max=max(Max,f[k-1][i-1][j]);
         	Max=max(Max,f[k-1][i][j-1]);
         	Max=max(Max,f[k-1][i-1][j-1]);
         	f[k][i][j]=Max+a[i][k-i]+a[j][k-j];
		 }
		 cout<<f[n+m-1][m-1][m];
 	return 0;
}
