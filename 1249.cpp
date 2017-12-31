#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
struct point 
{
	int x[105],y[105];
	double dis[105][105];
	point(){
		memset(dis,0x7f,sizeof(dis));
	}
}map;
int n,m,xx,yy,s,t;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>map.x[i]>>map.y[i];
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>xx>>yy;
		map.dis[xx][yy]=map.dis[yy][xx]=sqrt(double((map.x[xx]-map.x[yy])*(map.x[xx]-map.x[yy]))+double((map.y[xx]-map.y[yy])*(map.y[xx]-map.y[yy])));
	}
	cin>>s>>t;
	for(int k=1;k<=n;k++)
	  for(int i=1;i<=n;i++)
	     for(int j=1;j<=n;j++)
	     {
	     	if(i!=j&&j!=k&&k!=i)map.dis[i][j]=min(map.dis[i][j],map.dis[i][k]+map.dis[k][j]);
		 }
		 cout<<fixed<<setprecision(2)<<map.dis[s][t];
	return 0;
}
