#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<vector>
#include<stack>
#define ri register int
#define ll long long
using namespace std;
const int MAXN=5005;
const int MAXS=1030;
const int INF=0x7fffffff/2;
struct node{int to,sta;};
struct heap
{
	int u,sta,dist;
	bool operator <(const heap &rhs)
	const{return dist>rhs.dist;}
};
vector<node>a[MAXN];
int n,m,k;
int key[MAXN];
bool vst[MAXN][MAXS];
int dist[MAXN][MAXS];
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(bj==-1||c=='-')?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
int BFS(int v0)
{
	priority_queue<heap>q;
	for(ri i=1;i<=n;i++)
		for(ri j=0;j<(1<<k);j++)
			dist[i][j]=INF;
	dist[v0][key[v0]]=0;
	q.push((heap){v0,key[v0],dist[v0][key[v0]]});
	while(!q.empty())
	{
		heap now=q.top();q.pop();
		if(vst[now.u][now.sta])continue;
		vst[now.u][now.sta]=1;
		if(now.u==n)return now.dist;
		vector<node>::iterator it;
		for(it=a[now.u].begin();it!=a[now.u].end();++it)
		{
			if((now.sta&it->sta)!=it->sta)continue;
			int next_s=now.sta|key[it->to];
			if(vst[it->to][next_s])continue;
			if(dist[it->to][next_s]>dist[now.u][now.sta]+1)
			{
				dist[it->to][next_s]=dist[now.u][now.sta]+1;
				if(it->to==n)return dist[it->to][next_s];
				q.push((heap){it->to,next_s,dist[it->to][next_s]});
			}
		}
	}
	return -1;
}
int main()
{
	n=GetInt(),m=GetInt(),k=GetInt();
	for(ri i=1;i<=n;i++)
	{
		for(ri j=1;j<=k;j++)
		{
			int x=GetInt();
			if(x)key[i]|=(1<<(j-1));
		}
	}
	for(ri i=1;i<=m;i++)
	{
		int u=GetInt(),v=GetInt(),sta=0;
		for(ri j=1;j<=k;j++)
		{
			int x=GetInt();
			if(x)sta|=(1<<(j-1));
		}
		a[u].push_back((node){v,sta});
	}
	int ret=BFS(1);
	if(ret==-1)printf("No Solution\n");
	else printf("%d\n",ret);
	return 0;
}
