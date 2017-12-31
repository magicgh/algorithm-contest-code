#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<limits>
using namespace std;
const double DOUBLE_MAX=(numeric_limits<double>::max)();
double dist[51][51][51]={0};
int N,M,Q;
int main(){
	cin>>N>>M;
	int x,y,z;
    for(int i=1;i<=N;i++)
    for(int j=1;j<=N;j++)
    for(int t=0;t<=N;t++)
	   dist[i][j][t]=DOUBLE_MAX;
	for(int i=1;i<=M;i++)
	{
		cin>>x>>y>>z;
		dist[x][y][1]=min(double(z),dist[x][y][1]);
	}
	for(int t=2;t<=N;t++)	
	for(int k=1;k<=N;k++)
	for(int i=1;i<=N;i++)
	for(int j=1;j<=N;j++)
		if(dist[i][k][t-1]!=DOUBLE_MAX&&dist[k][j][1]!=DOUBLE_MAX)dist[i][j][t]=min(dist[i][j][t],dist[i][k][t-1]+dist[k][j][1]);
	for(int i=1;i<=N;i++)
	   for(int j=1;j<=N;j++)
	      {for(int t=1;t<=N;t++)
	      	if(dist[i][j][t]!=DOUBLE_MAX)dist[i][j][0]=min(dist[i][j][0],double(dist[i][j][t]/t));
		  }
	cin>>Q;
	for(int i=1;i<=Q;i++)
	{
		cin>>x>>y;
		if(dist[x][y][0]==DOUBLE_MAX)puts("OMG!");
		else printf("%.3lf\n",dist[x][y][0]);
	}
	return 0;
}
