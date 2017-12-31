#include<iostream>
#include<cstdio>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<vector>
#include<queue>
#include<stack>
#define ri register int
#define ll long long
#define pii pair<int,int>
#define mp make_pair
using namespace std;
const int MAXN=1000005;
stack<int>s;
vector<int>a[MAXN],b[MAXN];
int n,m,part,cnt,tot,Max;
int dfn[MAXN],low[MAXN],belong[MAXN],Size[MAXN],Deg[MAXN],List[MAXN];
bool vst[MAXN];
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(bj==-1||c=='-')?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
void Tarjan(int u)
{
	dfn[u]=low[u]=++cnt;
	s.push(u);vst[u]=1;
	vector<int>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(!dfn[*it])
		{
			Tarjan(*it);
			low[u]=min(low[u],low[*it]);
		}
		else if(vst[*it])
			low[u]=min(low[u],dfn[*it]);
	}
	if(dfn[u]==low[u])
	{
		int t;part++;
		do
		{
			t=s.top();s.pop();vst[t]=0;
			belong[t]=part;
			Size[part]++;
		}
		while(t!=u);
	}
}
void Topsort()
{
	int Max=0;
	queue<int>q;
	for(ri i=1;i<=part;i++)
		if(!Deg[i])q.push(i),List[i]=Size[i];
	while(!q.empty())
	{
		int now=q.front();q.pop();
		vector<int>::iterator it;
		for(it=b[now].begin();it!=b[now].end();++it)
		{
			Deg[*it]--;
			List[*it]=max(List[*it],List[now]+Size[*it]);
			if(!Deg[*it])q.push(*it);
		}
	}
	for(ri i=1;i<=part;i++)Max=max(Max,List[i]);
	printf("%d\n",Max);
}
int main()
{
	int size=40<<20;
	__asm__ ("movq %0,%%rsp\n"::"r"((char*)malloc(size)+size));
	n=GetInt(),m=GetInt();
	for(ri i=1;i<=m;i++)
	{
		int u=GetInt(),v=GetInt();
		a[u].push_back(v);
	}
	for(ri i=1;i<=n;i++)
		if(!dfn[i])Tarjan(i);
	for(ri u=1;u<=n;u++)
	{
		vector<int>::iterator it;
		for(it=a[u].begin();it!=a[u].end();++it)
		{
			if(belong[u]!=belong[*it])
			{
				b[belong[u]].push_back(belong[*it]);
				Deg[belong[*it]]++;
			}
		}
	}
	Topsort();
	exit(0);
	return 0;
}
