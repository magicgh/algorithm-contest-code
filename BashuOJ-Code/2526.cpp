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
stack<int>s;
int N,M,cnt,part,ret;
int dfn[MAXN],low[MAXN],Belong[MAXN],Deg[MAXN];
inline const int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
void Tarjan(int u,int fa)
{
	dfn[u]=low[u]=++cnt;
	s.push(u);
	vector<int>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(*it==fa)continue;
		if(!dfn[*it])
		{
			Tarjan(*it,u);
			low[u]=min(low[u],low[*it]);
		}
		else low[u]=min(low[u],dfn[*it]);
	}
	int t;
	if(dfn[u]==low[u])
	{
		part++;
		do
		{
			t=s.top();s.pop();
			Belong[t]=part;
		}
		while(t!=u);
	}
	
}	
int main()
{
	N=GetInt(),M=GetInt();
	for(ri i=1;i<=M;i++)
	{
		int u=GetInt(),v=GetInt();
		a[u].push_back(v);
		a[v].push_back(u);
	}
	Tarjan(1,0);
	for(ri u=1;u<=N;u++)
	{
		vector<int>::iterator it;
		for(it=a[u].begin();it!=a[u].end();++it)
			if(Belong[u]!=Belong[*it])Deg[Belong[u]]++;
	}
	for(ri i=1;i<=part;i++)
		if(Deg[i]==1)ret++;
	printf("%d\n",(ret+1)>>1); 
	return 0;
}


