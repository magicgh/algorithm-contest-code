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
const ll Mod=1000000007ll;
const int MAXN=100005;
const int MAXK=18;
struct Path{int u,v;};
struct Direct{int fa;ll val;int u,v;};
struct Inf{ll val;int u,v;};
Direct P[MAXN];
Inf T[10];
Path Edge[MAXN];
vector<int>a[MAXN];
ll w[MAXN],Ans[MAXN],Len[MAXN];
int dep[MAXN],prt[MAXN],p[MAXN][MAXK],q[MAXN];
int N;
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
inline bool cmp(const Inf &a,const Inf &b){return a.val>b.val;}
void DFS(int u,int fa,int depth,int val)
{
	prt[u]=fa,dep[u]=depth,Len[u]=val;
	vector<int>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(*it==fa)continue;
		DFS(*it,u,depth+1,val+w[*it]);
	}
}
void ST()
{
	memset(p,-1,sizeof(p));
	for(ri i=1;i<=N;i++)
		p[i][0]=prt[i];
	int k=log2(N);
	for(ri j=1;j<=k;j++)
		for(ri i=1;i<=N;i++)
		{
			if(p[i][j-1]==-1)continue;
			p[i][j]=p[p[i][j-1]][j-1];
		}
}
inline int LCA(int a,int b)
{
	if(dep[a]<dep[b])swap(a,b);
	int k=log2(dep[a]);
	for(ri i=k;i>=0;i--)
		if(dep[a]-(1<<i)>=dep[b])a=p[a][i];
	if(a==b)return a;
	for(ri i=k;i>=0;i--)
		if(p[a][i]!=p[b][i]&&p[a][i]!=-1)a=p[a][i],b=p[b][i];
	return p[a][0];
}
inline ll GetDist(int u,int v)
{
	int lca=LCA(u,v);
	return Len[u]+Len[v]-2*Len[lca]+w[lca];
}
inline ll Pow(ll a,ll b)
{
	ll ret=1,base=a;
	while(b)
	{
		if(b&1)ret=(ret*base)%Mod;
		base=(base*base)%Mod;
		b>>=1;
	}
	return ret;
}
inline int getfa(int u)
{
	if(P[u].fa==u)return u;
	else return P[u].fa=getfa(P[u].fa);
}
int main()
{
	N=GetInt(),Ans[N]=1;
	for(ri i=1;i<=N;i++)
	{
		w[i]=GetLL(),Ans[N]=Ans[N]*w[i]%Mod;
		P[i]=(Direct){i,w[i],i,i};
	}
	for(ri i=1;i<N;i++)
	{
		int u=GetInt(),v=GetInt();
		a[u].push_back(v);
		a[v].push_back(u);
		Edge[i]=(Path){u,v};
	}
	DFS(1,0,0,w[1]);
	ST();
	for(ri i=1;i<N;i++)q[i]=GetInt();
	for(ri i=N-1;i>=1;i--)
	{
		int u=Edge[q[i]].u,v=Edge[q[i]].v;
		int f1=getfa(u),f2=getfa(v);
		Ans[i]=Ans[i+1]*Pow(P[f1].val,Mod-2)%Mod*Pow(P[f2].val,Mod-2)%Mod;
		T[1]=(Inf){GetDist(P[f1].u,P[f1].v),P[f1].u,P[f1].v};
		T[2]=(Inf){GetDist(P[f2].u,P[f2].v),P[f2].u,P[f2].v};
		T[3]=(Inf){GetDist(P[f1].u,P[f2].u),P[f1].u,P[f2].u};
		T[4]=(Inf){GetDist(P[f1].v,P[f2].v),P[f1].v,P[f2].v};
		T[5]=(Inf){GetDist(P[f1].u,P[f2].v),P[f1].u,P[f2].v};
		T[6]=(Inf){GetDist(P[f1].v,P[f2].u),P[f1].v,P[f2].u};
		sort(T+1,T+6+1,cmp);
		Ans[i]=Ans[i]*T[1].val%Mod;
		if(f1!=f2)P[f1].fa=f2;
		P[f2]=(Direct){P[f2].fa,T[1].val,T[1].u,T[1].v};
	}
	for(ri i=1;i<=N;i++)printf("%lld\n",Ans[i]);
	return 0;
}

