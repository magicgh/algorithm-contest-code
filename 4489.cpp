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
const int MAXM=100005;
const int INF=0x7fffffff/2;
struct node{int to,val,year;};
struct path{int u,v,year;};
vector<node>a[MAXN];
path b[MAXM];
int n,m,t,tot,Banu,Banv;
int dist[MAXN],prt[MAXN],Old[MAXN];
bool vst[MAXN];
struct heap
{
	int u,dist;
	bool operator <(const heap &rhs)
	const{return dist>rhs.dist;}
};
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline bool cmp(const path &a,const path &b){return a.year<b.year;}
bool Dijkstra(int v0,int type,int Limit)
{
	priority_queue<heap>q;
	for(ri i=1;i<=n;i++)
	{
		dist[i]=INF,vst[i]=0;
		if(type==1)prt[i]=0,Old[i]=0;
	}
	dist[v0]=0,q.push((heap){v0,dist[v0]});
	while(!q.empty())
	{
		heap now=q.top();q.pop();
		if(vst[now.u])continue;
		vst[now.u]=1;
		vector<node>::iterator it;
		for(it=a[now.u].begin();it!=a[now.u].end();++it)
		{
			if(it->year<=Limit&&type!=1)continue;
			if((!vst[it->to])&&dist[now.u]+it->val<dist[it->to])
			{
				dist[it->to]=dist[now.u]+it->val;
				if(type==1)prt[it->to]=now.u,Old[it->to]=it->year;
				q.push((heap){it->to,dist[it->to]});
			}
		}
	}
	return dist[n]>=t;
}
inline bool Check(int Limit)
{
	return Dijkstra(1,0,Limit);
}
inline int Binary()
{
	int l=1,r=tot;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(Check(b[mid].year))r=mid-1;
		else l=mid+1;
	}
	return b[l].year;
}
int main()
{
	n=getint(),m=getint(),t=getint();
	for(ri i=1;i<=m;i++)
	{
		int u=getint(),v=getint(),w=getint(),y=getint();
		a[u].push_back((node){v,w,y});
		b[++tot]=(path){u,v,y};
	}
	Dijkstra(1,1,INF);
	if(dist[n]>=t)
	{
		printf("-1 %d\n",dist[n]);
		return 0;
	}
	else
	{
		sort(b+1,b+tot+1,cmp);
		printf("%d\n",Binary());
	}
	return 0;
}


