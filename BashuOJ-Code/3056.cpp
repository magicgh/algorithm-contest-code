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
const int MAXM=200005;
const int MAXN=20005;
struct path{int x,y;ll z;};
struct node{int to;ll val;};
vector<node>a[MAXN];
path b[MAXM];
int n,m,q,Mcnt,prt[MAXN];
int p[MAXN][20],d[MAXN];
ll g[MAXN][20],v[MAXN];
inline bool cmp(const path &a,const path &b){return a.z<b.z;}
inline void addedge(int x,int y,ll z)
{
	a[x].push_back((node){y,z});
	a[y].push_back((node){x,z});
}
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
	int bj=1;ll num=0;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline int getfa(int u)
{
	if(prt[u]==u)return u;
	return prt[u]=getfa(prt[u]);
}
void Kruskal()
{
	for(ri i=1;i<=n;i++)prt[i]=i;
	for(ri i=1;i<=m;i++)
	{
		int f1=getfa(b[i].x),f2=getfa(b[i].y);
		if(f1!=f2)
		{
			prt[f2]=f1;
			addedge(b[i].x,b[i].y,b[i].z);
			if(++Mcnt>=n-1)break;
		}
	}
}
void DFS(int u,int dep,ll val)
{
	d[u]=dep,v[u]=val;
	vector<node>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(prt[u]==it->to)continue;
		prt[it->to]=u;
		DFS(it->to,dep+1,it->val);
	}
}
void ST()
{
	memset(p,-1,sizeof(p));
	for(int i=1;i<=n;i++)p[i][0]=prt[i],g[i][0]=v[i];
	int k=int(log2(n));
	for(int j=1;j<=k;j++)
		for(int i=1;i<=n;i++)
			if(p[i][j-1]!=-1)
				p[i][j]=p[p[i][j-1]][j-1],g[i][j]=max(g[i][j-1],g[p[i][j-1]][j-1]);
}
inline ll LCA(int a,int b)
{
	ll Ans=0;
	if(d[a]<d[b])swap(a,b);
	int k=int(log2(d[a]));
	for(int i=k;i>=0;i--)
		if(d[a]-(1<<i)>=d[b])
			Ans=max(Ans,g[a][i]),a=p[a][i];
	if(a==b)return Ans;
	for(int i=k;i>=0;i--)
		if(p[a][i]!=-1&&p[a][i]!=p[b][i])
		{
			Ans=max(Ans,max(g[a][i],g[b][i]));
			a=p[a][i],b=p[b][i];
		}
	return max(Ans,max(g[a][0],g[b][0]));
}
int main()
{
	n=getint(),m=getint();
	for(ri i=1;i<=m;i++)
	{
		int x=getint(),y=getint();
		ll z=getll();
		b[i]=(path){x,y,z};
	}
	sort(b+1,b+m+1,cmp);
	Kruskal();
	memset(prt,0,sizeof(prt));
	DFS(1,0,0),ST();
	q=getint();
	for(ri i=1;i<=q;i++)
	{
		int x=getint(),y=getint();
		printf("%lld\n",LCA(x,y));
	}
	return 0;
}

