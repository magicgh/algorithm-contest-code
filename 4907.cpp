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
const int MAXN=300005;
const int delta=300000;
struct Game{int dir,val,Unit;};
vector<int>a[MAXN];
vector<Game>Player[MAXN];
int n,m,W[MAXN],d[MAXN];
int prt[MAXN],p[MAXN][20],Ans[MAXN];
int Up[MAXN],Down[MAXN<<1];
namespace FastIO
{
    const ll L=1<<15;
    char buffer[L],*S,*T;
    inline char getchar()
	{
        if(S==T){T=(S=buffer)+fread(buffer,1,L,stdin);if(S==T)return EOF;}
		return *S++;
    }
    inline int getint()
	{
        register char c;register ll rec=0,f=1;
        for(c=getchar();c<'0'||c>'9';c=getchar())if(c=='-')f=-1;
        while(c>='0'&&c<='9')rec=(rec<<1)+(rec<<3)+(c-'0'),c=getchar();
        return rec*f;
    }
}using FastIO::getint;
void DFS(int u,int dep)
{
	d[u]=dep;
	vector<int>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(*it==prt[u])continue;
		prt[*it]=u;
		DFS(*it,dep+1);
	}
}
inline void putint(int x)
{
     if(x<0)putchar('-'),x=-x;
     if(x>9)putint(x/10);
     putchar(x%10+'0');
}
void ST()
{
	memset(p,-1,sizeof(p));
	for(ri i=1;i<=n;i++)p[i][0]=prt[i];
	int k=log2(n);
	for(ri j=1;j<=k;j++)
		for(ri i=1;i<=n;i++)
			if(p[i][j-1]!=-1)p[i][j]=p[p[i][j-1]][j-1];
}
inline int LCA(int a,int b)
{
	if(d[a]<d[b])swap(a,b);
	int k=log2(d[a]);
	for(ri i=k;i>=0;i--)
		if(d[a]-(1<<i)>=d[b])a=p[a][i];
	if(a==b)return a;
	for(ri i=k;i>=0;i--)
		if(p[a][i]!=-1&&p[a][i]!=p[b][i])a=p[a][i],b=p[b][i];
	return p[a][0];
}
void Query(int u)
{
	int Up0=Up[W[u]+d[u]],Down0=Down[d[u]-W[u]+delta];
	vector<Game>::iterator it;
	for(it=Player[u].begin();it!=Player[u].end();++it)
	{
		if(!it->dir)Up[it->val]+=it->Unit;
		else Down[it->val+delta]+=it->Unit;
	}
	vector<int>::iterator eit;
	for(eit=a[u].begin();eit!=a[u].end();++eit)
		if(*eit!=prt[u])Query(*eit);
	int Up1=Up[W[u]+d[u]],Down1=Down[d[u]-W[u]+delta];
	Ans[u]+=Up1-Up0+Down1-Down0;
}
int main()
{
	n=getint(),m=getint();
	for(ri i=1;i<n;i++)
	{
		int u=getint(),v=getint();
		a[u].push_back(v);
		a[v].push_back(u);
	}
	DFS(1,0),ST();
	for(ri i=1;i<=n;i++)W[i]=getint();
	for(ri i=1;i<=m;i++)
	{
		int s=getint(),t=getint(),lca=LCA(s,t);
		int dist=d[s]+d[t]-2*d[lca];
		Player[s].push_back((Game){0,d[s],1});		
		Player[t].push_back((Game){1,d[t]-dist,1});		
		Player[lca].push_back((Game){0,d[s],-1});		
		Player[prt[lca]].push_back((Game){1,d[t]-dist,-1});		
	}
	Query(1);
	for(ri i=1;i<=n;i++)putint(Ans[i]),putchar(32);
	return 0;
}

