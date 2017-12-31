#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<climits>
using namespace std;
int n,m,f[305][305]={0};
int main(){
	cin>>n>>m;
	int x,y,z;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
		if(i!=j)f[i][j]=INT_MIN;
	for(int i=1;i<=m;i++)cin>>x>>y>>z,f[x][y]=z;
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
		if(f[i][k]!=INT_MIN&&f[k][j]!=INT_MIN)f[i][j]=max(f[i][j],f[i][k]+f[k][j]);
		int Max=INT_MIN;
	for(int i=1;i<=n;i++)
	   for(int j=1;j<=n;j++)Max=max(Max,f[i][j]);
	   cout<<Max;
	return 0;
}
