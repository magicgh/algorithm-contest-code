#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<vector>
#define ri register int
using namespace std;
const int MAXN=2500;
const int INF=0x7fffffff;
struct node{int x,y,c;};
vector<node>edge;
vector<int>g[MAXN];
int lev[MAXN],gap[MAXN],cur[MAXN];
int n,m,S,T,income;
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+c-'0',c=getchar();
	return num*bj;
}
inline void addedge(int x,int y,int c)
{
	edge.push_back({x,y,c});
	edge.push_back({y,x,0});
	g[x].push_back(edge.size()-2);
	g[y].push_back({edge.size()-1});
}
int DFS(int now,int f)
{
	if(now==T)return f;
	int delta,ret=0;
	for(ri& i=cur[now];i<g[now].size();i++)
	{
		node& next=edge[g[now][i]];
		if(next.c>0&&lev[next.x]==lev[next.y]+1)
		{
			delta=DFS(next.y,min(next.c,f));
			ret+=delta,f-=delta;
			edge[g[now][i]].c-=delta,edge[g[now][i]^1].c+=delta;
			if(!f||lev[S]==T)return ret;
		}
	}
	if(!(--gap[lev[now]]))lev[S]=T;
	gap[++lev[now]]++;
	return ret;
}
int SAP()
{
	int ans=0;gap[0]=T+1;
	while(lev[S]<T)memset(cur,0,sizeof(cur)),ans+=DFS(S,INF);
	return ans;
}
int main()
{
	n=getint(),m=getint();
	S=0,T=n+m+1;
	for(ri i=1;i<=n;i++)
	{
		int money=getint(),round=getint();
		addedge(S,i,money);income+=money;
		for(ri j=1;j<=round;j++)
		{
			int machine=getint(),cost=getint();
			addedge(i,machine+n,cost);
		}
	}
	for(ri i=1;i<=m;i++)addedge(i+n,T,getint());
	printf("%d",income-SAP());
	return 0;
}
