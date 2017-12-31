#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int n,k,m,f[105][105]={0},t;
int main(){
	cin>>n>>m;
	memset(f,0,sizeof(f));
	for(int i=0;i<n;i++)
	   for(int j=0;j<n;j++)cin>>f[i][j];
	for(int k=0;k<n;k++)
	   for(int i=0;i<n;i++)
	      for(int j=0;j<n;j++)
{
	if(f[i][k]!=-1&&f[k][j]!=-1)
	{
	      if(f[i][j]==-1)f[i][j]=f[i][k]+f[k][j];
	      else f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
		  }
	  }
	      for(int i=0;i<n;i++)cout<<f[i][m]<<' ';
	return 0;
}