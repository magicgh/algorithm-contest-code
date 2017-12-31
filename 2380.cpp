#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<map>
#define ri register int
#define ll long long
using namespace std;
const int INF=0x7fffffff;
const int MAXN=100005;
queue<int>q;
map<int,map<int,int>>Hash;
stack<int>s;
vector<int>a[MAXN],b[MAXN];
int n,m,Mod;
int cnt,part,dfn[MAXN],low[MAXN],Belong[MAXN],Size[MAXN];
int f[MAXN],g[MAXN],Ind[MAXN];
int Ans=-INF,sum;
bool Ins[MAXN];
inline void AddEdge(int x,int y)
{
	if(Hash.count(x)&&Hash[x].count(y))return;
	Hash[x][y]=1,b[x].push_back(y);Ind[y]++;
}
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void Tarjan(int u)
{
	dfn[u]=low[u]=++cnt;
	s.push(u);Ins[u]=1;
	vector<int>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(!dfn[*it])
		{
			Tarjan(*it);
			low[u]=min(low[u],low[*it]);
		}
		else if(Ins[*it])low[u]=min(low[u],dfn[*it]);
	}
	int t;
	if(low[u]==dfn[u])
	{
		part++;
		do
		{
			t=s.top();s.pop();
			Size[part]++,Ins[t]=0,Belong[t]=part;
		}
		while(t!=u);
	}
}
void Topsort()
{
	for(ri i=1;i<=part;i++)if(!Ind[i])q.push(i);
	while(!q.empty())
	{
		int x=q.front();q.pop();
		vector<int>::iterator it;
		for(it=b[x].begin();it!=b[x].end();++it)
		{
			Ind[*it]--;
			if(f[x]+Size[*it]==f[*it])g[*it]=(g[*it]+g[x])%Mod;
			if(f[x]+Size[*it]>f[*it])
			{
				f[*it]=f[x]+Size[*it];
				g[*it]=g[x];
			}
			if(!Ind[*it])q.push(*it);
		}
	}
}
int main()
{
	n=getint(),m=getint(),Mod=getint();
	for(ri i=1;i<=m;i++)
	{
		int x=getint(),y=getint();
		a[x].push_back(y);
	}
	for(ri i=1;i<=n;i++)if(!dfn[i])Tarjan(i);
	for(ri u=1;u<=n;u++)
		for(auto it=a[u].begin();it!=a[u].end();++it)
			if(Belong[u]!=Belong[*it])AddEdge(Belong[u],Belong[*it]);
	for(ri i=1;i<=part;i++)f[i]=Size[i],g[i]=1;
	Topsort();
	for(ri i=1;i<=part;i++)
	{
		if(f[i]==Ans)sum=(sum+g[i])%Mod;
		if(f[i]>Ans)Ans=f[i],sum=g[i];
	}
	printf("%d\n%d",Ans,sum%Mod);
	return 0;
}