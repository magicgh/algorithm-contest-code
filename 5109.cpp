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
const int MAXN=500005;
const int MAXM=1000005;
const ll INF=1e18;
struct node{int to;ll t,c;};
struct heap
{
	int u;ll dist;
	bool operator <(const heap &rhs)
	const{return dist>rhs.dist;}
};
vector<node>a[MAXN];
int prt[MAXN];
ll Max=-INF,dist[MAXN];
bool vst[MAXN];
int N,M,S,T;
inline ll max(const ll &a,const ll &b){return a>b?a:b;}
inline ll min(const ll &a,const ll &b){return a<b?a:b;}
namespace FastIO
{
	const int L=1<<15;
	char buf[L],*S,*T;
	char getchar()
	{
		if(S==T)
		{
			T=(S=buf)+fread(buf,1,L,stdin);
			if(S==T)return EOF;
		}
		return *S++;
	}
	inline const int GetInt()
	{
		int num=0,bj=1;
		char c=getchar();
		while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
		while(isdigit(c))num=num*10+c-'0',c=getchar();
		return num*bj;
	}
	inline const ll GetLL()
	{
		ll num=0,bj=1;
		char c=getchar();
		while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
		while(isdigit(c))num=num*10+c-'0',c=getchar();
		return num*bj;
	}
	inline void PutLL(ll x)
	{
	     if(x<0)putchar('-'),x=-x;
	     if(x>9)PutLL(x/10);
	     putchar(x%10+'0');
	}
}
using FastIO::GetInt;
using FastIO::GetLL;
using FastIO::PutLL;
void Dijkstra()
{
	priority_queue<heap>q;
	for(ri i=1;i<=N;i++)
		dist[i]=INF,vst[i]=0;
	dist[S]=0,q.push((heap){S,dist[S]});
	while(!q.empty())
	{
		heap now=q.top();q.pop();
		if(vst[now.u])continue;
		vst[now.u]=1;
		vector<node>::iterator it;
		for(it=a[now.u].begin();it!=a[now.u].end();++it)
		{
			if(it->t>Max)continue;
			if((!vst[it->to])&&dist[it->to]>dist[now.u]+(it->t*it->c))
			{
				dist[it->to]=dist[now.u]+(it->t*it->c);
				q.push((heap){it->to,dist[it->to]});
			}
		}
	}
	PutLL(dist[T]),putchar('\n');
}
void Prim()
{
	int cnt=0;
	priority_queue<heap>q;
	for(ri i=1;i<=N;i++)
		dist[i]=INF,vst[i]=0;
	dist[S]=0,q.push((heap){S,dist[S]});
	while(!q.empty()&&cnt<=N)
	{
		heap now=q.top();q.pop();
		if(vst[now.u])continue;
		vst[now.u]=1,cnt++;
		vector<node>::iterator it;
		for(it=a[now.u].begin();it!=a[now.u].end();++it)
		{
			if((!vst[it->to])&&dist[it->to]>it->t)
			{
				dist[it->to]=it->t;
				prt[it->to]=now.u;
				q.push((heap){it->to,dist[it->to]});
			}
		}
	}
	for(ri u=T;u!=S;u=prt[u])Max=max(Max,dist[u]);
	PutLL(Max),putchar(' ');
}
int main()
{
	N=GetInt(),M=GetInt();
	for(ri i=1;i<=M;i++)
	{
		int u=GetInt(),v=GetInt();
		ll t=GetLL(),c=GetLL();
		a[u].push_back((node){v,t,c});
		a[v].push_back((node){u,t,c});
	}
	S=GetInt(),T=GetInt();
	Prim(),Dijkstra();
	return 0;
}
