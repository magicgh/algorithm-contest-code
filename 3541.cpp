#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
long long n,m,a[105][105],f[105][105],t[105][105];
int main(){
	cin>>n>>m;
	getchar();
	memset(a,0,sizeof(a));
	memset(f,0,sizeof(f));
	memset(t,0,sizeof(t));
	for(int i=1;i<=n;i++)
	{
	   for(int j=1;j<=m;j++)a[i][j]=getchar()-'0';
	   getchar();
	   }
	f[1][1]=a[1][1];
	if(f[1][1])t[1][1]=1;
	for(int i=2;i<=n;i++)
	{
		f[i][1]=f[i-1][1]+a[i][1];
		if(f[i][1])t[i][1]=1;
	}
	for(int i=2;i<=m;i++)
	{
		f[1][i]=f[1][i-1]+a[1][i];
		if(f[1][i])t[1][i]=1;
	}
	for(int i=2;i<=n;i++)
	   for(int j=2;j<=m;j++)
	   {
	   	int s1=0,s2=0;
	   f[i][j]=max(f[i-1][j],f[i][j-1])+a[i][j];
	   if(f[i-1][j]+a[i][j]==f[i][j])s1=1;
	   if(f[i][j-1]+a[i][j]==f[i][j])s2=1;
	   t[i][j]=t[i-1][j]*s1+t[i][j-1]*s2;
	   }
	   cout<<f[n][m]<<endl<<t[n][m];
	   
	return 0;
}
