#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<deque>
#include<stack>
#include<vector>
#define ri register int
#define ll long long
using namespace std;
const int MAXN=10005;
const int MAXM=50005;
const ll INF=1e18;
struct node{int to;ll val;};
struct path{int u,v;ll w;};
path Edge[MAXM];
vector<node>a[MAXN];
ll dist[MAXN],fare[MAXN];
bool ext[MAXN];
int n,m,s,t;
ll oil,Max=-INF,Min=INF;
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline const ll getll()
{
	ll num=0;int bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline void Build_Graph(ll Limit)
{
	for(ri i=1;i<=n;i++)a[i].clear();
	for(ri i=1;i<=m;i++)
	{
		int u=Edge[i].u,v=Edge[i].v;ll w=Edge[i].w; 
		if(fare[u]>Limit||fare[v]>Limit)continue;
		a[u].push_back((node){v,w});
		a[v].push_back((node){u,w});
	}
}
inline ll SPFA(int v0)
{
	deque<int>q;
	for(ri i=1;i<=n;i++)dist[i]=INF,ext[i]=0;
	dist[v0]=0,q.push_back(v0),ext[v0]=1;
	while(!q.empty())
	{
		int now=q.front();q.pop_front();ext[now]=0;
		vector<node>::iterator it;
		for(it=a[now].begin();it!=a[now].end();++it)
		{
			if(dist[it->to]>dist[now]+it->val)
			{
				dist[it->to]=dist[now]+it->val;
				if(!ext[it->to])
				{
					if(!q.empty()&&dist[it->to]<dist[q.front()])
						q.push_front(it->to);
					else q.push_back(it->to);
					ext[it->to]=1;
				}
			}
		}
	}
	return dist[t];
}
ll Binary()
{
	ll l=Min,r=Max;
	while(l<=r)
	{
		ll mid=(l+r)>>1;
		Build_Graph(mid);
		if(SPFA(s)<=oil)r=mid-1;
		else l=mid+1;
	}
	return l;
}
int main()
{
	n=getint(),m=getint(),s=getint(),t=getint(),oil=getll();
	for(ri i=1;i<=n;i++)
		fare[i]=getll(),Min=min(Min,fare[i]),Max=max(Max,fare[i]);	
	for(ri i=1;i<=m;i++)
	{
		int u=getint(),v=getint();ll w=getll();
		Edge[i]=(path){u,v,w};
	}
	Build_Graph(INF);
	if(SPFA(s)>oil)printf("-1\n");
	else printf("%lld\n",Binary());
	return 0;
}

