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
const int MAXM=200005;
const ll LLINF=1e18;
const int INTINF=0x7fffffff/2;
int n,m,A,B,C,D;
ll Dis[MAXN][4],f[MAXN],Ans;
int Deg[MAXN];
struct node{int to;ll val;};
vector<int>List[MAXN];
struct heap
{
	int u;ll dist;
	bool operator <(const heap &rhs)
	const{return dist>rhs.dist;}
};
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
	ll num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
struct SSSP
{
	bool vst[MAXN];
	ll dist[MAXN];
	vector<node>Edge[MAXN];
	inline void AddEdge(int u,int v,ll w){Edge[u].push_back((node){v,w});}
	void Dijkstra(int v0)
	{
		priority_queue<heap>q;
		for(ri i=1;i<=n;i++)
			dist[i]=LLINF,vst[i]=0;
		dist[v0]=0,q.push((heap){v0,dist[v0]});
		while(!q.empty())
		{
			heap now=q.top();q.pop();
			if(vst[now.u])continue;
			vst[now.u]=1;
			vector<node>::iterator it;
			for(it=Edge[now.u].begin();it!=Edge[now.u].end();++it)
			{
				if((!vst[it->to])&&dist[it->to]>dist[now.u]+it->val)
				{
					dist[it->to]=dist[now.u]+it->val;
					q.push((heap){it->to,dist[it->to]});
				}
			}
		}
	}
};
SSSP T1,T2;
void Topsort()
{
	queue<int>q;
	for(ri i=1;i<=n;i++)
	{
		if(Deg[i]!=-1)f[i]=1;
		if(Deg[i]==0)q.push(i);
	}
	while(!q.empty())
	{
		int now=q.front();q.pop();
		vector<int>::iterator it;
		for(it=List[now].begin();it!=List[now].end();++it)
		{
			f[*it]=max(f[now]+1,f[*it]);
			Ans=max(Ans,f[*it]);
			Deg[*it]--;
			if(!Deg[*it])q.push(*it);
		}
	}
	printf("%lld\n",Ans);
}
int main()
{
	n=getint(),m=getint();
	for(ri i=1;i<=m;i++)
	{
		int u=getint(),v=getint();ll w=getll();
		T1.AddEdge(u,v,w);
		T2.AddEdge(v,u,w);
	}
	A=getint(),B=getint(),C=getint(),D=getint();
	T1.Dijkstra(A);
	for(ri i=1;i<=n;i++)
		Dis[i][0]=T1.dist[i];
	T2.Dijkstra(B);
	for(ri i=1;i<=n;i++)
		Dis[i][1]=T2.dist[i];
	T1.Dijkstra(C);
	for(ri i=1;i<=n;i++)
		Dis[i][2]=T1.dist[i];
	T2.Dijkstra(D);
	for(ri i=1;i<=n;i++)
		Dis[i][3]=T2.dist[i];
	if(Dis[B][0]==LLINF||Dis[D][2]==LLINF){printf("-1\n");return 0;}
	memset(Deg,-1,sizeof(Deg));
	for(ri u=1;u<=n;u++)
	{
		vector<node>::iterator it;
		for(it=T1.Edge[u].begin();it!=T1.Edge[u].end();++it)
		{
			if((Dis[u][0]+it->val+Dis[it->to][1]==Dis[B][0])&&(Dis[u][2]+it->val+Dis[it->to][3]==Dis[D][2]))
			{
				List[u].push_back(it->to);
				Deg[u]=(Deg[u]==-1)?0:Deg[u];
				Deg[it->to]=(Deg[it->to]==-1)?1:Deg[it->to]+1;
			}
		}
	}
	Topsort();
	return 0;
}


