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
const int MAXN=50005;
const int INF=0x7fffffff/2;
int n,k,Max=-INF;
int prt[MAXN],d[MAXN],p[MAXN][17],val[MAXN];
vector<int>a[MAXN];
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
void DFS(int u,int depth)
{
	d[u]=depth;
	vector<int>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(*it==prt[u])continue;
		prt[*it]=u;
		DFS(*it,depth+1);
	}
}
void ST()
{
	memset(p,-1,sizeof(p));
	for(ri i=1;i<=n;i++)p[i][0]=prt[i];
	for(ri j=1;j<=log2(n);j++)
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
inline void Pushup(int u)
{
	vector<int>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(*it==prt[u])continue;
		Pushup(*it);
		val[u]+=val[*it];
	}
	Max=max(Max,val[u]);
}
int main()
{
	n=getint(),k=getint();
	for(ri i=1;i<n;i++)
	{
		int u=getint(),v=getint();
		a[u].push_back(v);
		a[v].push_back(u);
	}
	DFS(1,0),ST();
	for(ri i=1;i<=k;i++)
	{
		int u=getint(),v=getint(),lca=LCA(u,v);
		val[u]++,val[v]++,val[lca]--;
		if(prt[lca])val[prt[lca]]--;
	}
	Pushup(1);
	printf("%d\n",Max);
	return 0;
}


