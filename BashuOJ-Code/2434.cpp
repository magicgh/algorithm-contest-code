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
const int MAXN=80005;
struct node{int u,v;};
struct edge{int to,val;}; 
vector<node>Edge; 
vector<int>G[MAXN];
vector<int>Cau;
vector<edge>tr[MAXN];
stack<node>s;
int low[MAXN],dfn[MAXN];
int n,m,cnt,W,tot,Ans;
int d1[MAXN],d2[MAXN],dist[MAXN],List[MAXN];
bool Block[MAXN];
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline void AddEdge(int u,int v)
{
	Edge.push_back((node){u,v});
	Edge.push_back((node){v,u});
	G[u].push_back(Edge.size()-2);
	G[v].push_back(Edge.size()-1);
}
inline void AddEdgeT(int u,int v,int w)
{
	tr[u].push_back((edge){v,w});
}
void Tarjan(int u,int Ban)
{
	dfn[u]=low[u]=++cnt;
	for(unsigned ri i=0;i<G[u].size();i++)
	{
		node next=Edge[G[u][i]];
		if((G[u][i]^1)==Ban)continue;
		if(!dfn[next.v])
		{
			s.push(next);
			Tarjan(next.v,G[u][i]);
			low[u]=min(low[u],low[next.v]);
			if(low[next.v]>dfn[u])
			{
				s.pop();
				AddEdgeT(next.u,next.v,1);
			}
			if(low[next.v]==dfn[u])
			{
				Cau.clear(),Block[++n]=1,W=0;
				AddEdgeT(u,n,0); 
				while(true)
				{
					node now=s.top();s.pop();
					if(now.u!=u)Cau.push_back(now.u);
					W++,dist[now.u]=W;
					if(now.u==u&&now.v==next.v)break;
				}
				for(unsigned ri i=0;i<Cau.size();i++)
				{
					int v=Cau[i];
					AddEdgeT(n,v,min(abs(dist[v]-dist[u]),W-abs(dist[v]-dist[u])));//u、v两点的距离 
				} 
			}
		}
		else if(dfn[u]>dfn[next.v])
		{
			s.push(next);
			low[u]=min(low[u],dfn[next.v]);
		}
	}
}
void Tree_DP(int u)
{
	vector<edge>::iterator it;
	for(it=tr[u].begin();it!=tr[u].end();++it)
	{
		Tree_DP(it->to);
		if(d1[it->to]+it->val>d1[u])
			d2[u]=d1[u],d1[u]=d1[it->to]+it->val;
		else if(d1[it->to]+it->val>d2[u])
			d2[u]=d1[it->to]+it->val;
	}
	if(Block[u])
	{
		deque<int>q;tot=0;
		List[++tot]=0; 
		for(it=tr[u].begin();it!=tr[u].end();++it)
			List[++tot]=d1[it->to];
		for(ri i=1;i<=tot;i++)
			List[tot+i]=List[i];
		tot<<=1;
		q.push_back(1);
		for(ri i=2;i<=tot;i++)
		{
			while(!q.empty()&&i-q.front()>tot/4)q.pop_front();//保持环中最短路的关系
			Ans=max(Ans,List[i]+List[q.front()]+i-q.front());
			while(!q.empty()&&List[q.back()]-q.back()<=List[i]-i)q.pop_back(); 
			q.push_back(i);
		}
	}
	else Ans=max(Ans,d1[u]+d2[u]);
}
int main()	
{
	n=getint(),m=getint();
	for(ri i=1;i<=m;i++)
	{
		int u=0,v,k=getint();
		for(ri j=1;j<=k;j++)
		{
			v=getint();
			if(u)AddEdge(u,v);
			u=v;
		}
	} 
	Tarjan(1,-1); 
	Tree_DP(1);
	printf("%d\n",Ans);
	return 0;
}
