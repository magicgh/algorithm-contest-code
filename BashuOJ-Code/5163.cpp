#include<iostream>
#include<cstdio>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<vector>
#include<queue>
#include<stack>
#define ri register int
#define uri unsigned register int
#define ll long long
#define pii pair<int,int>
#define mp make_pair
using namespace std;
const int MAXN=5005;
const int MAXM=105005;
struct Path{int u,v;ll w;};
struct Inf
{
	int lca,id;ll w;
	Inf(int a,int b,ll c){lca=a,id=b,w=c;}
};
Path b[MAXM];
vector<Path>Edge;
vector<int>G[MAXN];
int N,M,Q,Log;
int p[MAXN][15],pos[MAXN][15];
int prt[MAXN],dep[MAXN];
ll g[MAXN][15];
bool Ban[MAXM];
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(bj==-1||c=='-')?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline bool cmp(const Path &a,const Path &b){return a.w<b.w;}
inline ll GetLL()
{
	ll num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(bj==-1||c=='-')?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline int getfa(int u)
{
	if(prt[u]==u)return u;
	else return prt[u]=getfa(prt[u]);
}
inline void AddEdge(int u,int v,ll w)
{
	Edge.push_back((Path){u,v,w});
	Edge.push_back((Path){v,u,w});
	G[u].push_back(Edge.size()-2);
	G[v].push_back(Edge.size()-1);
}
void Kruskal()
{
	int tot=0;
	sort(b+1,b+M+1,cmp);
	for(ri i=1;i<=N;i++)prt[i]=i;
	for(ri i=1;i<=M;i++)
	{
		int f1=getfa(b[i].u),f2=getfa(b[i].v);
		if(f1!=f2)
		{
			prt[f1]=f2;
			AddEdge(b[i].u,b[i].v,b[i].w);
			if(++tot>=N-1)break;
		}
	}
}

void DFS(int u,int fa,int depth)
{
	p[u][0]=fa,dep[u]=depth;
	for(uri i=0;i<G[u].size();i++)
	{
		Path &next=Edge[G[u][i]];
		if(next.v==fa||Ban[G[u][i]])continue;
		g[next.v][0]=next.w,pos[next.v][0]=G[u][i];
		DFS(next.v,next.u,depth+1);
	}
}
inline void ST()
{
	for(ri j=1;j<=Log;j++)
		for(ri i=1;i<=N;i++)
		{
			if(p[i][j-1]==-1)continue;
			p[i][j]=p[p[i][j-1]][j-1];
			if(g[i][j-1]>g[p[i][j-1]][j-1])
			{
				g[i][j]=g[i][j-1];
				pos[i][j]=pos[i][j-1];
			}
			else
			{
				g[i][j]=g[p[i][j-1]][j-1];
				pos[i][j]=pos[p[i][j-1]][j-1];
			}
		}
}
inline Inf LCA(int a,int b)
{
	ll ret=0,po=0;
	if(dep[a]<dep[b])swap(a,b);
	int k=log2(dep[a]);
	for(ri i=k;i>=0;i--)
	{
		if(dep[a]-(1<<i)>=dep[b])
		{
			if(ret<g[a][i])
				ret=g[a][i],po=pos[a][i];
			a=p[a][i];
		}
	}
	if(a==b)return Inf(a,po,ret);
	for(ri i=k;i>=0;i--)
	{
		if(p[a][i]!=-1&&p[a][i]!=p[b][i])
		{
			if(ret<g[a][i])
				ret=g[a][i],po=pos[a][i];
			if(ret<g[b][i])
				ret=g[b][i],po=pos[b][i];
			a=p[a][i],b=p[b][i];
		}
	}
	if(ret<g[a][0])
		ret=g[a][0],po=pos[a][0];
	if(ret<g[b][0])
		ret=g[b][0],po=pos[b][0];
	return Inf(p[a][0],po,ret);
}
inline const char Getchar()
{
	register char ch[10];
	scanf("%s",ch);
	return ch[0];
}
inline void Add()
{
	int t1=GetInt(),t2=GetInt();ll w=GetLL();
	Inf C=LCA(t1,t2);
	if(w>=C.w)return;
	Ban[C.id]=Ban[C.id^1]=1;
	AddEdge(t1,t2,w);
	memset(p,-1,sizeof(p));
	memset(g,0,sizeof(g));
	memset(pos,0,sizeof(pos));
	DFS(1,0,0);
	ST();
}
inline void Query()
{
	int t1=GetInt(),t2=GetInt(),t3=GetInt(),t4=GetInt();
	Inf A=LCA(t1,t2),B=LCA(t3,t4);
	printf((A.w^B.w)==0?"Baozika\n":"madoka\n");
}
int main()
{
	N=GetInt(),M=GetInt(),Log=log2(N);
	for(ri i=1;i<=M;i++)
	{
		int u=GetInt(),v=GetInt();ll w=GetLL();
		b[i]=(Path){u,v,w};
	}
	memset(p,-1,sizeof(p));
	Kruskal(),DFS(1,0,0),ST();
	Q=GetInt();
	for(ri i=1;i<=Q;i++)
	{
		char ch=Getchar();
		if(ch=='a')Add();
		else if(ch=='g')Query();
	}
	return 0;
}
