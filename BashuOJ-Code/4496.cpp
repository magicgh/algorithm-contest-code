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
const int MAXN=200005;
const int INF=0x7fffffff/2;
struct heap
{
	int u,dist;
	bool operator <(const heap &rhs)
	const{return dist>rhs.dist;}
};
struct node{int to,val,tval;};
namespace FastIO
{
    const ll L=1<<15;
    char buffer[L],*S,*T;
    inline char getchar()
	{
        if(S==T){T=(S=buffer)+fread(buffer,1,L,stdin);if(S==T)return EOF;}
		return *S++;
    }
    inline const int getint()
	{
		ri num=0,bj=1;
		register char c=getchar();
		while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
		while(isdigit(c))num=num*10+c-'0',c=getchar();
		return num*bj;
	}
}using FastIO::getint;
int N,M,Q;
bool vst[MAXN];
int dist[MAXN],Dis[MAXN][2],prt[MAXN],dep[MAXN],p[MAXN][18],g[MAXN][18];
vector<node>Edge[MAXN];
vector<int>a[MAXN];
void Dijkstra(int v0)
{
	priority_queue<heap>q;
	for(ri i=1;i<=N;i++)
		dist[i]=INF,vst[i]=0,prt[i]=0;
	dist[v0]=0,q.push((heap){v0,dist[v0]});
	while(!q.empty())
	{
		heap now=q.top();q.pop();
		if(vst[now.u])continue;
		vst[now.u]=1;
		vector<node>::iterator it;
		for(it=Edge[now.u].begin();it!=Edge[now.u].end();++it)
		{
			if((!vst[it->to])&&dist[now.u]+it->val<dist[it->to])
			{
				dist[it->to]=dist[now.u]+it->val;
				prt[it->to]=now.u;
				q.push((heap){it->to,dist[it->to]});
			}
		}
	}
}
void DFS(int u,int depth)
{
	dep[u]=depth;
	vector<int>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
		DFS(*it,depth+1);
}
void ST()
{
	int k=log2(N);
	for(ri i=0;i<=N;i++)
		for(ri j=0;j<=k;j++)p[i][j]=-1,g[i][j]=INF;
	for(ri i=1;i<=N;i++)p[i][0]=prt[i],g[i][0]=Dis[prt[i]][2];
	p[1][0]=-1;
	for(ri j=1;j<=k;j++)
		for(ri i=1;i<=N;i++)
		{	
			if(p[i][j-1]==-1)continue;
			p[i][j]=p[p[i][j-1]][j-1];
			g[i][j]=min(g[i][j-1],g[p[i][j-1]][j-1]);
		}
}
inline int ClimbTime(int u,int Limit)
{
	int k=log2(N),ret=Dis[u][2];
	for(ri i=k;i>=0;i--)
	{	
		if(p[u][i]!=-1&&Dis[p[u][i]][1]>=Limit)
		{
			ret=min(ret,g[u][i]);
			u=p[u][i];
		}
	}
	return ret;
}
inline int ClimbLen(int u,int Limit)
{
	int k=log2(N),ret=Dis[u][2];
	for(ri i=k;i>=0;i--)
	{
		if(p[u][i]!=-1&&dep[p[u][i]]>=Limit)
		{
			ret=min(ret,g[u][i]);
			u=p[u][i];
		}
	}
	return ret;
}
int main()
{
	N=getint(),M=getint(),Q=getint();
	for(ri i=1;i<=M;i++)
	{
		int u=getint(),v=getint(),w1=getint(),w2=getint();
		Edge[u].push_back((node){v,w2,w1});
		Edge[v].push_back((node){u,w2,w1});
	}
	Dijkstra(N);
	for(ri i=1;i<=N;i++)Dis[i][2]=dist[i];
	for(ri u=1;u<=N;u++)
	{
		vector<node>::iterator it;
		for(it=Edge[u].begin();it!=Edge[u].end();++it)
			swap(it->val,it->tval);
	}
	Dijkstra(1);
	for(ri i=1;i<=N;i++)Dis[i][1]=dist[i];
	for(ri i=1;i<=N;i++)
		if(prt[i])a[prt[i]].push_back(i);
	DFS(1,0),ST();
	for(ri i=1;i<=Q;i++)
	{
		int op=getint(),pos=getint(),Limit=getint();
		if(op==1)
		{
			if(dep[pos]<Limit)printf("-1\n");
			else printf("%d\n",ClimbLen(pos,Limit));
		}
		if(op==2)
		{
			if(Dis[pos][1]<Limit)printf("-1\n");
			else printf("%d\n",ClimbTime(pos,Limit));
		}
	}
	return 0;
}


