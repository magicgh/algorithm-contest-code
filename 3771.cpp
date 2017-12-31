#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<deque>
#include<stack>
#include<vector>
#define ri register int
#define ll long long
using namespace std;
const int MAXN=305;
const int INF=0x7fffffff/2;
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
int n,N,M,E,P,L,K,Min=INF;
int f[MAXN][MAXN];
struct node{int to,val;};
bool Charge[MAXN];
struct Graph
{
	vector<node>a[10005];
	int dist[10005];
	bool ext[10005];
	inline void AddEdge(int u,int v,int w){a[u].push_back((node){v,w});}
	void SPFA(int v0)
	{
		deque<int>q;
		for(ri i=0;i<=n;i++)dist[i]=INF,ext[i]=0;
		q.push_back(v0),dist[v0]=0,ext[v0]=1;
		while(!q.empty())
		{
			int now=q.front();q.pop_front();ext[now]=0;
			vector<node>::iterator it;
			for(it=a[now].begin();it!=a[now].end();++it)
			{
				if(dist[now]+it->val<dist[it->to])
				{
					dist[it->to]=dist[now]+it->val;
					if(!ext[it->to])
					{
						if(!q.empty()&&dist[q.front()]>dist[it->to])q.push_front(it->to);
						else q.push_back(it->to);
						ext[it->to]=1;
					}
				}
			}
		}
	}
};
Graph Dif,Path;
void Floyed()
{
	for(ri k=1;k<=N;k++)
	{
		if(Charge[k])continue;
		for(ri i=1;i<=N;i++)
			for(ri j=1;j<=N;j++)
				if(i!=j&&f[i][k]!=INF&&f[k][j]!=INF)
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]); 
	}
}
int main()
{
	n=N=getint(),M=getint(),E=getint(),P=getint(),L=getint(),K=getint();
	for(ri i=1;i<=N;i++)
		for(ri j=1;j<=N;j++)if(i!=j)f[i][j]=INF;
	for(ri i=1;i<=E;i++)
	{
		int u=getint(),v=getint(),w=getint();
		f[u][v]=f[v][u]=min(f[u][v],w);
	}
	for(ri i=1;i<=P;i++)
	{
		int u=getint(),v=getint(),t=getint();
		Dif.AddEdge(v,u-1,-t);
	}
	for(ri i=1;i<=N;i++)
	{
		Dif.AddEdge(i-1,i,1);
		Dif.AddEdge(i,i-1,0);
	}
	Dif.AddEdge(0,N,M),Dif.AddEdge(N,0,M);
	Dif.SPFA(0);
	for(ri i=1;i<=N;i++)if(Dif.dist[i]-Dif.dist[i-1]==1)Charge[i]=1;
	Floyed();n=(K+1)*N;
	for(ri i=1;i<=N;i++)
		for(ri j=1;j<=N;j++)
			if(f[i][j]!=INF)
			{
				for(ri k=0;k<=K;k++)
				{
					if(f[i][j]<=L&&k!=K)Path.AddEdge(k*N+i,(k+1)*N+j,0);
					if(i!=j)Path.AddEdge(k*N+i,k*N+j,f[i][j]);
				}
			}
	Path.SPFA(1);
	for(ri i=0;i<=K;i++)
		Min=min(Min,Path.dist[i*N+N]);
	printf("%d",Min);
	return 0;
}
