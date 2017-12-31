#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
long long a[505][505]={0},n,m,Max=-0x7fffffff;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
	   for(int j=1;j<=n;j++)if(i!=j)a[i][j]=0x7fffffff;
	   int x,y,z;
	   m=n-1;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>z;
		a[x][y]=a[y][x]=z;
	}
	for(int k=1;k<=n;k++)
	   for(int i=1;i<=n;i++)
	      for(int j=1;j<=n;j++)if(a[i][k]!=0x7fffffff&&a[k][j]!=0x7fffffff)a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
		  for(int i=1;i<=n;i++)
	      for(int j=1;j<=n;j++)
	      {
	       Max=max(Max,a[i][j]);
		  }
		  cout<<Max;
	return 0;
}
