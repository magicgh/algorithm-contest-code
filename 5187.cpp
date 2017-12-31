#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#define ri register int
#define ll long long
using namespace std;
const int MAXN=50005;
const int MAXM=100005;
int c[MAXN],dep[MAXN];
int n,m,sill=320,p[MAXN][16],g[MAXN][330];
vector<int>a[MAXN];
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline int Climb(int u,int k)
{
	for(ri dk=0;k;k>>=1,++dk)if(k&1)u=p[u][dk];
	return u;
}
void DFS(int u,int fa,int depth)
{
	dep[u]=depth;
	vector<int>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(*it==fa)continue;
		p[*it][0]=u;
		DFS(*it,u,depth+1);
	}
}
void Tree_DP(int u)
{
	for(ri i=1;i<=sill;i++)
	{
		int anc=Climb(u,i);
		g[u][i]=g[anc][i]+c[u];
	}
	vector<int>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(*it==p[u][0])continue;
		Tree_DP(*it);
	}
}
inline void ST()
{
	int k=log2(n);
	for(ri j=1;j<=k;j++)
		for(ri i=1;i<=n;i++)
			p[i][j]=p[p[i][j-1]][j-1];
}
int len;
inline int LCA(int a,int b)
{
	if(dep[a]<dep[b])swap(a,b);
	int k=log2(dep[a]);
	for(ri i=k;i>=0;i--)
		if(dep[a]-(1<<i)>=dep[b])a=p[a][i],len+=(1<<i);
	if(a==b)return a;
	for(ri i=k;i>=0;i--)
		if(p[a][i]!=-1&&p[a][i]!=p[b][i])a=p[a][i],b=p[b][i],len+=(1<<(i+1));
	len+=2;
	return p[a][0];
}
inline int Query(int s,int t,int k)
{
	int lca=LCA(s,t),ret=0,len=dep[s]+dep[t]-2*dep[lca],u=s;
	if(s==t)return c[s];
	if(k<=sill)
	{
		int step=int(ceil(double(dep[s]-dep[lca])/(double)k));
		int aim=Climb(s,step*k);
		ret+=g[s][k]-g[aim][k];
		if(len%k)ret+=c[t],t=Climb(t,len%k);
		step=int(ceil(double(dep[t]-dep[lca])/(double)k));
		aim=Climb(t,step*k);
		ret+=g[t][k]-g[aim][k];
		if(!((dep[u]-dep[lca])%k))ret+=c[lca];
		return ret;
	}
	else 
	{
		int lca=LCA(s,t),ret=0,u=s;
		if(s==t)return c[s];
		while(dep[s]>=dep[lca])ret+=c[s],s=Climb(s,k);
		if(len%k)ret+=c[t],t=Climb(t,len%k);
		while(dep[t]>=dep[lca])ret+=c[t],t=Climb(t,k);
		if(!((dep[u]-dep[lca])%k))ret-=c[lca];
		return ret;
	}
}
int main()
{
	n=GetInt(),m=GetInt();
	for(ri i=1;i<=n;i++)c[i]=GetInt();
	for(ri i=1;i<n;i++)
	{
		int u=GetInt(),v=GetInt();
		a[u].push_back(v);
		a[v].push_back(u);
	}
	DFS(1,0,1),ST(),Tree_DP(1);
	for(ri i=1;i<=m;i++)
	{
		int s=GetInt(),t=GetInt(),k=GetInt();
		printf("%d\n",Query(s,t,k));
	}
	return 0;
}