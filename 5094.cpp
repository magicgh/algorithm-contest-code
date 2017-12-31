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
int n,m;
int prt[MAXN],dep[MAXN],p[MAXN][20],Size[MAXN];
inline const int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
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
	for(int i=k;i>=0;i--)if(p[a][i]!=-1&&p[a][i]!=p[b][i])a=p[a][i],b=p[b][i];
	return p[a][0];
}
inline int Climbx1(int u,int v,int lca,int dist)
{
	int a=u,b=v,k;
	k=log2(dep[a]);
	for(ri i=k;i>=0;i--)
		if(dep[a]-(1<<i)>=dep[u]-dist+1)a=p[a][i];
	k=log2(dep[b]);
	for(ri i=k;i>=0;i--)
		if(dep[b]-(1<<i)>=dep[v]-dist+1)b=p[b][i];
	return n-Size[a]-Size[b];
}
inline int Climbx2(int u,int v,int lca,int dist)
{
	if(dep[u]<dep[v])swap(u,v);
	int a=u,k;
	k=log2(dep[a]);
	for(ri i=k;i>=0;i--)
		if(dep[a]-(1<<i)>=dep[u]-dist+1)a=p[a][i];
	return Size[prt[a]]-Size[a];
}
int main()
{
	n=GetInt();
	for(ri i=1;i<n;i++)
	{
		int u=GetInt(),v=GetInt();
		a[u].push_back(v); 
		a[v].push_back(u); 
	}
	DFS(1,0,0),ST();
	m=GetInt();
	for(ri i=1;i<=m;i++)
	{
		int u=GetInt(),v=GetInt(),lca=LCA(u,v),dist=dep[u]+dep[v]-2*dep[lca];
		if(u==v)printf("%d\n",n);
		else if(dist&1)printf("0\n");
		else if(dep[u]-dep[lca]==dep[v]-dep[lca])printf("%d\n",Climbx1(u,v,lca,dist>>1));
		else printf("%d\n",Climbx2(u,v,lca,dist>>1));
	}
	return 0;
}


