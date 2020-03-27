#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<deque>
#include<stack>
#include<vector>
#define ri register int
#define ll long long
using namespace std;
const int MAXN=505;
const ll INF=1e18;
struct path{int to;ll val;};
struct node{int x,y;ll c;};
vector<path>a[MAXN];
vector<node>Edge;
vector<int>G[MAXN<<1];
node b[100005];
struct heap
{
	int u;ll dist;
	bool operator <(const heap &rhs)
	const{return dist>rhs.dist;}
};
int n,m,S,T;
int cap[MAXN],gap[MAXN<<1],lev[MAXN<<1];
ll Ans,dist[MAXN];
bool vst[MAXN],ext[MAXN];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline ll getll()
{
	ll num=0;int bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline void AddEdge(int x,int y,ll c)
{
	Edge.push_back((node){x,y,c});
	Edge.push_back((node){y,x,0});
	G[x].push_back(Edge.size()-2);
	G[y].push_back(Edge.size()-1);
}
void SPFA(int v0)
{
	deque<int>q;
	for(int i=1;i<=n;i++)dist[i]=INF;
	q.push_back(v0);dist[v0]=0;ext[v0]=1;
	while(!q.empty())
	{
		int now=q.front();
		q.pop_front();
		ext[now]=0;
		vector<path>::iterator it;
		for(it=a[now].begin();it!=a[now].end();++it)
		{
			if(dist[it->to]>dist[now]+it->val)
			{
				dist[it->to]=dist[now]+it->val;
				if(!ext[it->to])
				{
					if(!q.empty()&&dist[q.front()]>dist[it->to])q.push_front(it->to);
					else q.push_back(it->to);
				}
			}                                                                                      
		}
	}
}
ll DFS(int now,ll f)
{
	if(now==T)return f;
	ll ret=0,delta;
	for(ri i=0;i<G[now].size();i++)
	{
		node &next=Edge[G[now][i]];
		if(next.c>0&&lev[next.x]==lev[next.y]+1)
		{
			delta=DFS(next.y,min(f,next.c));
			f-=delta,ret+=delta;
			Edge[G[now][i]].c-=delta,Edge[G[now][i]^1].c+=delta;
			if(!f||lev[S]==T)return ret;
		}
	}
	if(!(--gap[lev[now]]))lev[S]=T;
	gap[++lev[now]]++;
	return ret;
}
inline void MaxFlow()
{
	S=1,T=(n<<1);
	gap[0]=T;
	while(lev[S]<T)Ans+=DFS(S,INF);
	printf("%lld\n",Ans);
}
int main()
{
	n=getint(),m=getint();
	for(ri i=1;i<=m;i++)
	{
		int u=getint(),v=getint();ll w=getll();
		a[u].push_back((path){v,w});
		a[v].push_back((path){u,w});
		b[i]=(node){u,v,w};
	}
	for(ri i=1;i<=n;i++)cap[i]=getint();
	SPFA(1);
	for(ri i=1;i<=m;i++)
	{
		if(dist[b[i].x]+b[i].c==dist[b[i].y])AddEdge(b[i].x+n,b[i].y,INF);
		if(dist[b[i].y]+b[i].c==dist[b[i].x])AddEdge(b[i].y+n,b[i].x,INF);
	}
	for(ri i=1;i<=n;i++)
	{
		if(i==1||i==n)AddEdge(i,i+n,INF);
		else AddEdge(i,i+n,(ll)cap[i]);
	}
	MaxFlow();
	return 0;
}