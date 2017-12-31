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
const int MAXN=20005;
struct node{int to,val;};
struct stk{int u,v,val;};
vector<node>a[MAXN];
vector<node>tr[MAXN];
vector<int>Edge;
stack<stk>s;
int n,m,Q,cnt,newnode;
int dfn[MAXN],low[MAXN];
int d1[MAXN],d2[MAXN];
int p[MAXN][15],dep[MAXN],g[MAXN][15];
bool Block[MAXN];
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
void Tarjan(int u,int fa)
{
	dfn[u]=low[u]=++cnt;
	vector<node>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(it->to==fa)continue;
		if(!dfn[it->to])
		{
			s.push((stk){u,it->to,it->val});
			Tarjan(it->to,u);
			low[u]=min(low[u],low[it->to]);
			if(low[it->to]>dfn[u])//树边 
			{
				s.pop();
				tr[u].push_back((node){it->to,it->val});
				tr[it->to].push_back((node){u,it->val});
			}
			if(low[it->to]==dfn[u])//环结束 
			{
				int W=0;Edge.clear();
				while(true)
				{
					stk now=s.top();s.pop();
					Edge.push_back(now.u);
					W+=now.val,d1[now.u]=W;
					if(now.u==u&&now.v==it->to)break;
				}
				Block[++newnode]=1;
				for(unsigned ri i=0;i<Edge.size();i++)
				{
					int v=Edge[i];d2[v]=W-d1[v];
					tr[newnode].push_back((node){v,min(d1[v],d2[v])});
					tr[v].push_back((node){newnode,min(d1[v],d2[v])});
				}
			} 
		}
		else if(dfn[u]>dfn[it->to])//环边 
		{
			s.push((stk){u,it->to,it->val});
			low[u]=min(low[u],dfn[it->to]);
		}
	}
}
void DFS(int u,int depth,int val)
{
	dep[u]=depth,g[u][0]=val;
	vector<node>::iterator it;
	for(it=tr[u].begin();it!=tr[u].end();++it)
	{
		if(it->to==p[u][0])continue;
		p[it->to][0]=u;
		DFS(it->to,depth+1,it->val); 
	}
}
void ST()
{
	int k=log2(newnode);
	for(ri j=1;j<=k;j++)
		for(ri i=1;i<=newnode;i++)
			if(p[i][j-1]!=-1)
			{
				p[i][j]=p[p[i][j-1]][j-1];
				g[i][j]=g[p[i][j-1]][j-1]+g[i][j-1];
			}
}
inline int LCA(int a,int b)
{
	if(a==b)return 0;
	int Ans=0;
	if(dep[a]<dep[b])swap(a,b);
	int k=log2(dep[a]);
	for(ri i=k;i>=0;i--)
		if(dep[a]-(1<<i)>=dep[b])Ans+=g[a][i],a=p[a][i];
	if(a==b)return Ans;
	for(ri i=k;i>=0;i--)
		if(p[a][i]!=-1&&p[a][i]!=p[b][i])
			Ans+=g[a][i]+g[b][i],a=p[a][i],b=p[b][i];
	if(Block[p[a][0]])
		Ans+=min(d1[a]+d2[b],min(d2[a]+d1[b],abs(d1[a]-d1[b])));
	else Ans+=g[a][0]+g[b][0];
	return Ans;
}
int main()
{
	n=newnode=getint(),m=getint(),Q=getint();
	for(ri i=1;i<=m;i++)
	{
		int x=getint(),y=getint(),z=getint();
		a[x].push_back((node){y,z});
		a[y].push_back((node){x,z});
	}
	Tarjan(1,-1);
	memset(p,-1,sizeof(p));
	DFS(1,0,0);
	ST();
	for(ri i=1;i<=Q;i++)
	{
		int u=getint(),v=getint();
		printf("%d\n",LCA(u,v));
	}
	return 0;
}

