#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int dx[5]={0,-1,1,0,0},dy[5]={0,0,0,-1,1};
int r,c,Map[105][105],f[105][105],ans=0;
int dfs(int x,int y)
{
	if(x<1||y<1||x>r||y>c)return 0;
	if(f[x][y])return f[x][y];
	for(int i=1;i<=4;i++)if(Map[x+dx[i]][y+dy[i]]<Map[x][y])f[x][y]=max(f[x][y],dfs(x+dx[i],y+dy[i]));
	f[x][y]++;
	return f[x][y];
}
int main(){
	cin>>r>>c;
	memset(Map,0,sizeof(Map));
	memset(f,0,sizeof(f));
	for(int i=1;i<=r;i++)
	   for(int j=1;j<=c;j++)cin>>Map[i][j];
	   for(int i=1;i<=r;i++)
	      for(int j=1;j<=c;j++)
	      {
	      	ans=max(ans,dfs(i,j));
		  }
	   cout<<ans;
	return 0;
}
