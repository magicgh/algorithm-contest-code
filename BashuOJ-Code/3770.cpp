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
#define ll long long
using namespace std;
const int MAXN=105;
const int INF=0x7fffffff/2;
struct point{int x,y;};
int Max,Min;
int n,m,map[MAXN][MAXN];
bool vst[MAXN][MAXN];
int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline bool BFS(int L,int R)
{
	memset(vst,0,sizeof(vst));
	queue<point>q;
	q.push((point){1,1});
	while(!q.empty())
	{
		point now=q.front();q.pop();
		if(vst[now.x][now.y])continue;
		vst[now.x][now.y]=1;
		for(ri i=0;i<4;i++)
		{
			point next=(point){now.x+dx[i],now.y+dy[i]};
			if(next.x>=1&&next.x<=n&&next.y>=1&&next.y<=m&&!vst[next.x][next.y]&&L<=map[next.x][next.y]&&map[next.x][next.y]<=R)
			{
				if(next.x==n&&next.y==m)return 1;
				q.push(next);
			}
		}
	}
	return 0;
}
inline bool Check(int k)
{
	for(ri i=0;i<=k;i++)
		if(BFS(map[1][1]+i-k,map[1][1]+i))return 1;
	return 0;
}
int main()
{
	n=getint(),m=getint();
	Max=-INF,Min=INF;
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=m;j++)
		{
			map[i][j]=getint();
			Max=max(Max,map[i][j]);
			Min=min(Min,map[i][j]);
		}
	int l=0,r=Max-Min;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(Check(mid))r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",l);
	return 0;
}

