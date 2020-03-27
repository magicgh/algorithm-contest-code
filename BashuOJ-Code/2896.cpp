#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int a[505][505]={0},n,m,t[505][505]={0};
int main(){
cin>>n>>m;
	for(int i=1;i<=n;i++)
	   for(int j=1;j<=n;j++)if(i!=j)a[i][j]=0x7fffffff;
	   int x,y,z;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>z;
		a[x][y]=a[y][x]=z;
	}
	int Min=0x7fffffff,MinNo1=0,MinNo2=0;
	for(int k=1;k<=n;k++)
	   for(int i=1;i<=n;i++)
	      for(int j=1;j<=n;j++)if(a[i][k]!=0x7fffffff&&a[k][j]!=0x7fffffff)a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
	   for(int i=1;i<=n;i++)
	      for(int j=1;j<=n;j++)
	       for(int k=1;k<=n;k++)
		  t[i][j]+=min(a[i][k],a[j][k]);
	      for(int i=1;i<n;i++)
	         for(int j=i+1;j<=n;j++)
	         {
	         	if(Min>t[i][j])Min=t[i][j],MinNo1=i,MinNo2=j;
			 }
	         cout<<MinNo1<<' '<<MinNo2;
	return 0;
}
