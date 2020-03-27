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
const int MAXM=500005;
const int MAXK=30005;
const ll INF=1e18;
struct node{int to;ll val;};
struct heap
{
	int u;ll dist;
	bool operator <(const heap &rhs)
	const {return dist>rhs.dist;}
};
vector<node>a[MAXN];
bool vst[MAXN];
int n,m,k,mx,my;
ll dist[MAXN][3],path[MAXK];
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
	inline const ll getll()
	{
		ll num=0;int bj=1;
		char c=getchar();
		while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
		while(isdigit(c))num=num*10+c-'0',c=getchar();
		return num*bj;
	}
	inline void putint(ll x)
	{
	     if(x<0)putchar('-'),x=-x;
	     if(x>9)putint(x/10);
	     putchar(x%10+'0');
	}
};
using namespace FastIO;
void Dijkstra(int v0,int id)
{
	priority_queue<heap>q;
	for(ri i=1;i<=n;i++)dist[i][id]=INF,vst[i]=0;
	q.push((heap){v0,0});dist[v0][id]=0;
	while(!q.empty())
	{
		heap now=q.top();q.pop();
		if(vst[now.u])continue;
		vst[now.u]=1;
		vector<node>::iterator it;
		for(it=a[now.u].begin();it!=a[now.u].end();++it)
		{
			if(!vst[it->to]&&dist[now.u][id]+it->val<dist[it->to][id])
			{
				dist[it->to][id]=dist[now.u][id]+it->val;
				q.push((heap){it->to,dist[it->to][id]});
			}
		}
	}
}
int main()
{
	n=getint(),m=getint(),k=getint();
	for(ri i=1;i<m;i++)
	{
		int u=getint(),v=getint();ll w=getll();
		a[u].push_back((node){v,w});
		a[v].push_back((node){u,w});
	}
	mx=getint(),my=getint();
	for(ri i=1;i<=k;i++)path[i]=getll();
	Dijkstra(1,0),Dijkstra(mx,1),Dijkstra(my,2);
	for(ri i=1;i<=k;i++)
	{
		ll ret=dist[n][0];
		ll d1=dist[1][1]+path[i]+dist[n][2];
		ll d2=dist[1][2]+path[i]+dist[n][1];
		d1=d1<d2?d1:d2,ret=ret<d1?ret:d1;
		if(ret==INF)putchar('+'),putchar('I'),putchar('n'),putchar('f'),putchar('\n');
		else putint(ret),putchar('\n');
	}
	return 0;
}

