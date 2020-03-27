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
const int MAXN=505;
const int INF=0x7fffffff/2;
struct heap{int x,y;};
int n,m,map[MAXN][MAXN];
int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
int L[MAXN],R[MAXN],f[MAXN],vst[MAXN][MAXN];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void BFSDown()
{
	queue<heap>q;
	for(ri i=1;i<=m;i++)q.push((heap){1,i});
	while(!q.empty())
	{
		heap now=q.front();q.pop();
		if(vst[now.x][now.y])continue;
		vst[now.x][now.y]=1;
		for(ri i=0;i<4;i++)
		{
			heap next=(heap){now.x+dx[i],now.y+dy[i]};
			if(next.x>=1&&next.x<=n&&next.y>=1&&next.y<=m&&!vst[next.x][next.y]&&map[next.x][next.y]<map[now.x][now.y])
				q.push(next);
		}	
	}
}
void BFSUp(int k)
{
	queue<heap>q;
	q.push((heap){n,k});
	while(!q.empty())
	{
		heap now=q.front();q.pop();
		if(vst[now.x][now.y])continue;
		vst[now.x][now.y]=k;
		for(ri i=0;i<4;i++)
		{
			heap next=(heap){now.x+dx[i],now.y+dy[i]};
			if(next.x>=1&&next.x<=n&&next.y>=1&&next.y<=m&&!vst[next.x][next.y]&&map[next.x][next.y]>map[now.x][now.y])
				q.push(next);
		}
	}
}
void Liner_DP()
{
	for(ri i=1;i<=m;i++)f[i]=INF;
	for(ri i=1;i<=m;i++)
		for(ri j=1;j<=m;j++)
			if(L[j]<=i&&i<=R[j])
				f[i]=min(f[i],f[L[j]-1]+1);
	printf("1\n%d\n",f[m]);
}
int Judge()
{
	int cnt=0;
	memset(vst,0,sizeof(vst));
	BFSDown();
	for(ri i=1;i<=m;i++)if(!vst[n][i])cnt++;
	return cnt;
}
void Solve()
{
	memset(vst,0,sizeof(vst));
	for(ri i=1;i<=m;i++)L[i]=INF,R[i]=0;
	for(ri i=1;i<=m;i++)
	{
		if(vst[n][i])continue;
		BFSUp(i);
		for(ri j=1;j<=m;j++)if(vst[1][j]==i)L[j]=i;
	}
	memset(vst,0,sizeof(vst));
	for(ri i=m;i>=1;i--)
	{
		if(vst[n][i])continue;
		BFSUp(i);
		for(ri j=1;j<=m;j++)if(vst[1][j]==i)R[j]=i;
	}
	Liner_DP();
}
int main()
{
	n=getint(),m=getint();
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=m;j++)map[i][j]=getint();
	int t=Judge();
	if(t)printf("0\n%d\n",t);
	else Solve();
	return 0;
}

