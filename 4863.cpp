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
const int MAXN=100005;
vector<int>a[MAXN];
int n,m,prt[MAXN],dep[MAXN],Size[MAXN];
int p[MAXN][20];
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline void putint(int x)
{
     if(x<0)putchar('-'),x=-x;
     if(x>9)putint(x/10);
     putchar(x%10+'0');
}
void DFS(int u,int fa,int depth)
{
	prt[u]=fa,dep[u]=depth,Size[u]=1;
	vector<int>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(*it==fa)continue;
		DFS(*it,u,depth+1);
		Size[u]+=Size[*it];
	}
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
	if(dep[a]<dep[b])swap(a,b);
	int k=log2(dep[a]);
	for(ri i=k;i>=0;i--)
		if(dep[a]-(1<<i)>=dep[b])a=p[a][i];
	if(a==b)return a;
	for(ri i=k;i>=0;i--)
		if(p[a][i]!=-1&&p[a][i]!=p[b][i])
			a=p[a][i],b=p[b][i];
	return p[a][0];
}
inline int Queryx1(int a,int b,int lca)
{
	int dist=((dep[a]+dep[b]-2*dep[lca])>>1);
	if(dep[a]<dep[b])swap(a,b);
	int k=log2(dep[a]),t=a;
	for(ri i=k;i>=0;i--)
		if(dep[a]-(1<<i)>=dep[t]-dist+1)a=p[a][i];
	return Size[prt[a]]-Size[a];
}
inline int Queryx2(int a,int b,int lca)
{
	int dist=((dep[a]+dep[b]-2*dep[lca])>>1);
	int k=log2(dep[a]),t=a;
	for(ri i=k;i>=0;i--)
		if(dep[a]-(1<<i)>=dep[t]-dist+1)a=p[a][i];
	for(ri i=k;i>=0;i--)
		if(dep[b]-(1<<i)>=dep[t]-dist+1)b=p[b][i];
	return n-Size[a]-Size[b];
}
int main()
{
	n=getint();
	for(ri i=1;i<n;i++)
	{
		int x=getint(),y=getint();
		a[x].push_back(y);
		a[y].push_back(x);
	}
	DFS(1,0,0),ST();
	m=getint();
	for(ri i=1;i<=m;i++)
	{
		int x=getint(),y=getint(),lca=LCA(x,y);
		if(x==y)putint(n),putchar('\n');
		else if(dep[lca]-dep[x]==dep[lca]-dep[y])
			putint(Queryx2(x,y,lca)),putchar('\n');
		else if((dep[x]+dep[y]-2*dep[lca])&1)putint(0),putchar('\n');
		else putint(Queryx1(x,y,lca)),putchar('\n');
	}
	return 0;
}