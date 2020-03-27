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
const int MAXN=100005;
const int MAXM=300005;
const int INTINF=0x7fffffff/2;
const ll LLINF=1e18;
struct node{int to;ll val;};
vector<node>a[MAXN];
int N,M;
int prt[MAXN],p[MAXN][18],dep[MAXN],Deg[MAXN];
ll dist[MAXN],S[MAXN],g[MAXN][18];
bool vst[MAXN];
ll A,B,C;
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
void DFS(int u,int fa)
{
	vst[u]=1;dep[u]=dep[fa]+1;
	vector<node>::iterator it;
    for(it=a[u].begin();it!=a[u].end();++it)
	{
        if(vst[it->to])continue;
        dist[it->to]=dist[u]+it->val;
        prt[it->to]=u;
        DFS(it->to,u);
    }
}
void ST1()
{
	memset(p,-1,sizeof(p));
	for(ri i=2;i<=N;i++)p[i][0]=prt[i];
	int k=log2(N);
	for(ri j=1;j<=k;j++)
		for(ri i=1;i<=N;i++)
			if(p[i][j-1]!=-1)
				p[i][j]=p[p[i][j-1]][j-1];
}
inline int LCA(int a,int b)
{
	if(dep[a]<dep[b])swap(a,b);
	int k=log2(dep[a]);
	for(ri i=k;i>=0;i--)
		if(dep[a]-(1<<i)>=dep[b])a=p[a][i];
	if(a==b)return a;
	for(ri i=k;i>=0;i--)
		if(p[a][i]!=-1&&p[a][i]!=p[b][i])
			a=p[a][i],b=p[b][i];
	return p[a][0];
}
void Prepare()
{
	ll MaxL1=-LLINF,MaxL2=-LLINF;
	int Maxid1,Maxid2;
	for(ri i=2;i<=N;i++)
		if(dist[i]>MaxL1)MaxL1=dist[i],Maxid1=i;
	for(ri i=1;i<=N;i++)
	{
		int lca=LCA(i,Maxid1);
		if(dist[i]+dist[Maxid1]-2*dist[lca]>MaxL2)
			MaxL2=dist[i]+dist[Maxid1]-2*dist[lca],Maxid2=i;
	}
	for(ri i=1;i<=N;i++)
	{
		int lca1=LCA(i,Maxid1),lca2=LCA(i,Maxid2);
		ll Value=max(dist[i]+dist[Maxid1]-2*dist[lca1],dist[i]+dist[Maxid2]-2*dist[lca2]);
		S[i]=(Value+A)*B%C;
	}
}
void ST2()
{
	for(ri i=1;i<=N;i++)g[i][0]=S[p[i][0]];
	int k=log2(N);
	for(ri j=1;j<=k;j++)
		for(ri i=1;i<=N;i++)
			if(p[i][j-1]!=-1)
				g[i][j]=max(g[i][j-1],g[p[i][j-1]][j-1]);
}
inline int Climbx1(int u,int lca,int k,ll Limit)
{
	if(dep[u]<=dep[lca])return -1;
	for(;dep[p[u][k]]<dep[lca]&&k>=0;--k);
	if(g[u][k]<Limit)return Climbx1(p[u][k],lca,k-1,Limit);
	for(ri i=k-1;i>=0;i--)
		if(g[u][i]<Limit)u=p[u][i];
	return p[u][0];
}
inline int Climbx2(int u,int lca,int k,ll Limit)
{
	int ret;
	if(dep[u]<=dep[lca])return -1;
	for(;dep[p[u][k]]<dep[lca]&&k>=0;k--);
	ret=Climbx2(p[u][k],lca,k-1,Limit);
	if(ret!=-1)return ret;
	if(g[u][k]<Limit)return -1;
	for(ri i=k-1;i>=0;i--)
		if(g[p[u][i]][i]>=Limit)u=p[u][i];
	return p[u][0];
}
int main()
{
	N=getint(),M=getint(),A=getll(),B=getll(),C=getll();
	for(ri i=1;i<N;i++)
	{
		int u=getint(),v=getint();ll w=getll();
		a[u].push_back((node){v,w});
		a[v].push_back((node){u,w});
		Deg[u]++,Deg[v]++;
	}
	S[0]=-1e18;
	for(ri i=1;i<=N;i++)
		if(Deg[i]!=-1){DFS(i,0);break;}
	ST1(),Prepare(),ST2();
	for(ri i=1;i<=M;i++)
	{
		int u=getint(),v=getint();
		ll Limit=getll();
		int lca=LCA(u,v),ret=-1;
		if(S[u]>=Limit)ret=u;
		if(ret==-1)ret=Climbx1(u,lca,log2(dep[u]),Limit);
		if(ret==-1)ret=Climbx2(v,lca,log2(dep[v]),Limit);
		if(ret==-1&&S[v]>=Limit)ret=v;
		printf("%d\n",ret);
	}
	return 0;
}
