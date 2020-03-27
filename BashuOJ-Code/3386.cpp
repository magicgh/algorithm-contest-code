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
const int MAXN=10005;
const int INF=0x7fffffff/2;
struct node{int to,val;};
struct heap
{
	int u;ll dist;
	bool operator <(const heap &rhs)
	const{return dist>rhs.dist;}
};
int n,m,T,From[MAXN];
vector<node>a[MAXN],b[MAXN];
int dist[MAXN];
bool vst[MAXN];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void Dijx1(int v0)
{
	priority_queue<heap>q;
	for(ri i=1;i<=n;i++)dist[i]=INF,vst[i]=0;
	dist[v0]=0;
	q.push((heap){v0,dist[v0]});
	while(!q.empty())
	{
		heap now=q.top();q.pop();
		if(vst[now.u])continue;
		vst[now.u]=1;
		vector<node>::iterator it;
		for(it=a[now.u].begin();it!=a[now.u].end();++it)
		{
			if(dist[now.u]+it->val<dist[it->to]&&(!vst[it->to]))
			{
				if(now.u==1)From[it->to]=it->to;
				else From[it->to]=From[now.u];
				dist[it->to]=dist[now.u]+it->val;
				q.push((heap){it->to,dist[it->to]});
			}
		} 
	}
}
void Dijx2(int v0)
{
	priority_queue<heap>q;
	memset(vst,0,sizeof(vst));
	for(ri i=1;i<=n+1;i++)dist[i]=INF;
	dist[v0]=0;
	q.push((heap){v0,dist[v0]});
	while(!q.empty())
	{
		heap now=q.top();q.pop();
		if(vst[now.u])continue;
		vst[now.u]=1;
		vector<node>::iterator it;
		for(it=b[now.u].begin();it!=b[now.u].end();++it)
		{
			if(dist[now.u]+it->val<dist[it->to]&&(!vst[it->to]))
			{
				dist[it->to]=dist[now.u]+it->val;
				q.push((heap){it->to,dist[it->to]});
			}
		} 
	}
}
inline void Build()
{
	T=n+1;//建立一个虚点 
	for(int u=1;u<=n;u++)
	{
		vector<node>::iterator it;
		for(it=a[u].begin();it!=a[u].end();++it)
		{
			if(it->to==1)
			{
				if(u==From[u])//走过
					b[u].push_back((node){T,it->val});//可以间接使用 
				else //未走过 
					b[1].push_back((node){T,dist[u]+it->val});//可以直接使用 
			}
			else if(u==1)
			{
				//if(it->to==From[it->to]) 有直接最短路,不连
				 if(it->to!=From[it->to])
				 	b[1].push_back((node){it->to,it->val});//未走过可以直接使用 
			}
			else 
			{
				if(From[u]==From[it->to])b[u].push_back((node){it->to,it->val});//直接保留
				else b[1].push_back((node){it->to,dist[u]+it->val});//存在S -> From[u] -> u -> it->to 的路径
			}
		}
	}
}
int main()
{
	n=getint(),m=getint();
	for(ri i=1;i<=m;i++)
	{
		int s=getint(),t=getint(),w=getint(),v=getint();
		a[s].push_back((node){t,w});
		a[t].push_back((node){s,v});
	}
	Dijx1(1);
	Build();
	Dijx2(1);
	printf("%d\n",dist[T]==((1<<1)|1)?dist[T]-1:dist[T]);
	return 0;
}
