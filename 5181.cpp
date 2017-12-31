#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<vector>
#include<stack>
#define ri register int
#define ll long long
using namespace std;
const int MAXN=200005;
const int Limit=200000;
stack<int>s;
int T,N,M,cnt,part;
int dfn[MAXN],low[MAXN],Deg[MAXN];
ll Base[MAXN],f[MAXN],Size[MAXN];
bool Ins[MAXN];
ll Mod;
vector<int>a[MAXN];
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(bj==-1||c=='-')?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline void Init()
{
	Base[0]=1;
	for(ri i=1;i<=Limit;i++)
		Base[i]=Base[i-1]*i%Mod;
	memset(Ins,0,sizeof(Ins));
	for(ri i=0;i<=Limit;i++)
		dfn[i]=0,low[i]=0,Size[i]=0,Deg[i]=0,a[i].clear();
	while(!s.empty())s.pop();
	cnt=part=0;
}
inline ll Pow(ll a,ll b)
{
	ll ret=1,base=a;
	while(b)
	{
		if(b&1)ret=ret*base%Mod;
		base=base*base%Mod;
		b>>=1;
	}
	return ret;
}
inline ll C(ll n,ll m)
{
	if(n<m)return 0;
	return Base[n]*Pow(Base[m]*Base[n-m]%Mod,Mod-2)%Mod;
}
inline ll Lucas(ll n,ll m)
{
	if(!m)return 1;
	return Lucas(n/Mod,m/Mod)%Mod*C(n%Mod,m%Mod)%Mod;
}
void Tarjan(int u)
{
	dfn[u]=low[u]=++cnt;
	s.push(u),Ins[u]=1;
	vector<int>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(!dfn[*it])
		{
			Tarjan(*it);
			low[u]=min(low[u],low[*it]);
		}
		else if(Ins[*it])
			low[u]=min(low[u],dfn[*it]);
	}
	if(dfn[u]==low[u])
	{
		int t;part++;
		do{t=s.top();Ins[t]=0,s.pop();}
		while(t!=u);
	}
}
void DFS(int u)
{
	f[u]=1;
	vector<int>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		DFS(*it);
		Size[u]+=Size[*it];
		f[u]=f[u]*f[*it]%Mod*C(Size[u],Size[*it])%Mod;
	}
	Size[u]++;
}
inline ll Solve()
{
	for(ri i=1;i<=M;i++)
	{
		int x=GetInt(),y=GetInt();
		a[y].push_back(x);
		Deg[x]++;
	}
	if(!M)return Base[N];
	for(ri i=1;i<=N;i++)
		if(!dfn[i])Tarjan(i);
	if(part!=N)return 0ll;
	for(ri i=1;i<=N;i++)
		if(!Deg[i])a[0].push_back(i);
	DFS(0);
	return f[0];
}
int main()
{
	T=GetInt();
	while(T--)
	{
		N=GetInt(),M=GetInt(),Mod=GetInt();
		Init();
		printf("%lld\n",Solve());
	}
	return 0;
}
