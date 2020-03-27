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
const int MAXN=300005;
vector<int>a[MAXN],b[MAXN];
stack<int>s;
int n,cnt,part,w[MAXN];
int dfn[MAXN],low[MAXN],Belong[MAXN],sum[MAXN],f[MAXN],Deg[MAXN];
bool Ins[MAXN],vst[MAXN];
double Ans;
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline void AddEdge(int u,int v){b[v].push_back(u),Deg[u]++;}
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
		else if(Ins[*it])
			low[u]=min(low[u],dfn[*it]);
	}
	if(dfn[u]==low[u])
	{
		int t;part++;
		do
		{
			t=s.top();s.pop();Ins[t]=0;
			Belong[t]=part,sum[part]+=w[t];
		}while(t!=u);
	}
}
void Topsort()
{
	queue<int>q;
	for(ri i=1;i<=part;i++)
	{
		if(!Deg[i])q.push(i);
		f[i]=sum[i];
	}
	while(!q.empty())
	{
		int now=q.front();q.pop();
		vector<int>::iterator it;
		for(it=b[now].begin();it!=b[now].end();++it)
		{
			Deg[*it]--;
			f[*it]+=f[now];
			if(!Deg[*it])q.push(*it);
		}
	}
}
int main()
{
        int size=40<<20;
        __asm__ ("movq %0,%%rsp\n"::"r"((char*)malloc(size)+size));
	n=GetInt();
	for(ri i=1;i<=n;i++)
	{
		int x=GetInt();
		a[i].push_back(x);
	}
	for(ri i=1;i<=n;i++)w[i]=GetInt();
	for(ri i=1;i<=n;i++)
		if(!dfn[i])Tarjan(i);
	for(ri u=1;u<=n;u++)
	{
		vector<int>::iterator it;
		for(it=a[u].begin();it!=a[u].end();++it)
			if(Belong[u]!=Belong[*it])AddEdge(Belong[u],Belong[*it]);
	}
	Topsort();
	for(ri i=1;i<=n;i++)Ans+=(double)f[Belong[i]];
	printf("%.6lf",Ans/(double)n);
        exit(0);
	return 0;
}
