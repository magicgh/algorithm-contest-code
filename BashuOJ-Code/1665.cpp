#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<climits>
using namespace std;
int n,m;
int a[105][105]={0},b[105][105]={0};
int main(){
	int x,y,z;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)if(i!=j)a[i][j]=b[i][j]=INT_MAX;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>z;
		a[x][y]=a[y][x]=b[x][y]=b[y][x]=z;
	}
	int Min=INT_MAX;
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<k;i++)
		   for(int j=i+1;j<k;j++)
		   	 if(a[i][j]!=INT_MAX&&b[i][k]!=INT_MAX&&b[k][j]!=INT_MAX)Min=min(Min,a[i][j]+b[i][k]+b[k][j]);
		for(int i=1;i<=n;i++)
		   for(int j=1;j<=n;j++)
		     if(a[i][k]!=INT_MAX&&a[k][j]!=INT_MAX)a[i][j]=min(a[i][j],a[i][k]+a[j][k]);
	}
	if(Min==INT_MAX)puts("No solution.");
	else printf("%d",Min);
	return 0;
}
