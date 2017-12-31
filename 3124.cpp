#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define ri register int
using namespace std;
const int INF=0x7fffffff/2;
int dx[]={-1,1,0,0,-1,-1,1,1},dy[]={0,0,-1,1,-1,1,-1,1};
int n,k,map[1005][1005],dist[1005][1005];
bool vst[1005][1005];
struct heap
{
	int x,y,dis;
	bool operator <(const heap &rhs)const{return dis>rhs.dis;}
};
priority_queue<heap>q;
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void FloodFill()
{
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=n;j++)dist[i][j]=INF/2;
	for(ri i=1;i<=n;i++)//来自边界的FloodFill 
	{
		q.push((heap){0,i,0});
		q.push((heap){i,0,0});
		q.push((heap){n+1,0,0});
		q.push((heap){0,n+1,0});
	}
	while(!q.empty())
	{
		heap now=q.top();q.pop();
		if(vst[now.x][now.y])continue;
		vst[now.x][now.y]=1;
		for(ri k=0;k<8;k++)
		{
			heap next=(heap){now.x+dx[k],now.y+dy[k]};
			if(next.x>=1&&next.x<=n&&next.y>=1&&next.y<=n)
			{
				int val=(map[now.x][now.y]&&!map[next.x][next.y]);
				if(dist[next.x][next.y]>dist[now.x][now.y]+val)
				{
					dist[next.x][next.y]=dist[now.x][now.y]+val;
					q.push((heap){next.x,next.y,dist[next.x][next.y]});
				}
			}
		}
	}
}
int main()
{
	char ch;
	n=getint(),k=getint();
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=n;j++)
		{
			while(ch=getchar())if(isdigit(ch))break;
			map[i][j]=ch-'0';
		}
	FloodFill();
	for(ri i=1;i<=k;i++)
	{
		int x=getint(),y=getint();
		printf("%d ",dist[x][y]);
	}
	return 0;
}

