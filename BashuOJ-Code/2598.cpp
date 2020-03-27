#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#define Max 0x7fffffff
#define Min -0x7fffffff
using namespace std;
int dx[5]={0,0,0,-1,1},dy[5]={0,-1,1,0,0},m,n,t;
char map[105][105]={0};
int lx,ly,rx,ry,cnt=0;
bool vst[105][105]={0};
void dfs(int x,int y)
{
	cnt++;
	lx=min(x,lx);
	ly=min(y,ly);
	rx=max(x,rx);
	ry=max(y,ry);
	vst[x][y]=1;
    for(int i=1;i<=4;i++)
    {
    int xx=x+dx[i];
    int yy=y+dy[i];
    if(xx>0&&x<=m&&yy>0&&yy<=n&&!(vst[xx][yy])&&map[xx][yy]=='#')
    	dfs(xx,yy);
	}
	return;
}
int main(){
	int Room=0,Cow=0;
	cin>>m>>n;
	memset(map,0,sizeof(map));
	memset(vst,0,sizeof(vst));
	for(int i=1;i<=m;i++)
	  for(int j=1;j<=n;j++)cin>>map[i][j];
	  for(int i=1;i<=m;i++)
	     for(int j=1;j<=n;j++)
	     if(!vst[i][j]&&map[i][j]=='#')
	     {
	     cnt=0;
		 lx=Max,ly=Max,rx=Min,ry=Min;
		 dfs(i,j);
		 if((rx-lx+1)*(ry-ly+1)==cnt)Room++;
		 else Cow++;
		 }
		 cout<<Room<<endl<<Cow<<endl; 
	return 0;
}
