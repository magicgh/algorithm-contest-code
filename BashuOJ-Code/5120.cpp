#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define ri register int
#define ll long long
using namespace std;
const int MAXN=50005;
const int Limit=50000;
const ll INF=1e18;
struct node{int to;ll val;};
vector<node>a[MAXN],b[MAXN];
int n,m,cnt,part;
stack<int>s;
int dfn[MAXN],low[MAXN],Belong[MAXN],Deg[MAXN];
ll dist[MAXN];
bool vst[MAXN];
inline const int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline const ll GetLL()
{
	ll num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline void Clear()
{
	cnt=part=0;
	while(!s.empty())s.pop();
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(vst,0,sizeof(vst));
	memset(Belong,0,sizeof(Belong));
	for(ri i=1;i<=Limit;i++)
		a[i].clear(),b[i].clear();
}
void Tarjan(int u)
{
	dfn[u]=low[u]=++cnt;
	s.push(u);vst[u]=1;
	vector<node>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(!dfn[it->to])
		{
			Tarjan(it->to);
			low[u]=min(low[u],low[it->to]);
		}
		else if(vst[it->to])
			low[u]=min(low[u],dfn[it->to]);
	}
	if(dfn[u]==low[u])
	{
		int t;part++;
		do
		{
			t=s.top();s.pop();vst[t]=0;
			Belong[t]=part;
		}
		while(t!=u);
	}
}
void Topsort()
{
	queue<int>q;
	ll Ans=0;
	for(ri i=1;i<=part;i++)dist[i]=INF;
	q.push(Belong[1]),dist[Belong[1]]=0;
	while(!q.empty())
	{
		int now=q.front();q.pop();
		vector<node>::iterator it;
		for(it=b[now].begin();it!=b[now].end();++it)
		{
			Deg[it->to]--;
			dist[it->to]=min(dist[it->to],it->val);
			if(!Deg[it->to])q.push(it->to);
		}
	}
	for(ri i=1;i<=part;i++)
		if(dist[i]!=INF)Ans+=dist[i];
	printf("%lld\n",Ans);
}
int main()
{
	while(n=GetInt(),m=GetInt())
	{
		if(n==0&&m==0)break;
		Clear();
		for(ri i=1;i<=m;i++)
		{
			int u=GetInt()+1,v=GetInt()+1;
			ll w=GetLL();
			a[u].push_back((node){v,w});
		}
		for(ri i=1;i<=n;i++)
			if(!dfn[i])Tarjan(i);
		for(ri u=1;u<=n;u++)
		{
			vector<node>::iterator it;
			for(it=a[u].begin();it!=a[u].end();++it)
			{
				if(Belong[u]==Belong[it->to])continue;
				b[Belong[u]].push_back((node){Belong[it->to],it->val});
				Deg[Belong[it->to]]++;
			}
		}
		Topsort();
	}
	return 0;
}


