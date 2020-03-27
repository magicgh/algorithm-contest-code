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
const int MAXN=1000005;
const ll INF=1e18;
struct node{int x,y;};
vector<node>Edge;
vector<int>G[MAXN<<1];
ll Ans,value[MAXN],f[MAXN][2],Max;
int n,x,y,Cut,B[MAXN<<1];
bool vst[MAXN];
inline void AddEdge(int x,int y,int i)
{
	Edge.push_back((node){x,y});
	Edge.push_back((node){y,x});
	G[x].push_back(Edge.size()-2);
	G[y].push_back(Edge.size()-1);
	B[Edge.size()-2]=B[Edge.size()-1]=i;
}
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline ll getll()
{
	ll num=0;int bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
void DFS(int u,int fa)
{
	vst[u]=1;
	for(ri i=0;i<G[u].size();i++)
	{
		node &E=Edge[G[u][i]];
		if(E.y==fa)continue;
		if(vst[E.y])x=u,y=E.y,Cut=B[G[u][i]];
		else DFS(E.y,u);
	}
}
void Tree_DP(int u,int fa)
{
	f[u][0]=0,f[u][1]=value[u];
	for(ri i=0;i<G[u].size();i++)
	{
		node &E=Edge[G[u][i]];
		if(E.y==fa||B[G[u][i]]==Cut)continue;
		Tree_DP(E.y,u);
		f[u][0]+=max(f[E.y][0],f[E.y][1]);
		f[u][1]+=f[E.y][0];
	}
}
int main()
{
	n=getint();
	for(int i=1;i<=n;i++)
	{
		value[i]=getll();int Hate=getint();
		AddEdge(i,Hate,i);
	}
	for(ri i=1;i<=n;i++)
	{
		if(!vst[i])
		{
			DFS(i,0);
			Tree_DP(x,0);
			Max=f[x][0];
			Tree_DP(y,0);
			Max=max(Max,f[y][0]);
			Ans+=Max;
		}
	}
	printf("%lld\n",Ans);
	return 0;
}

