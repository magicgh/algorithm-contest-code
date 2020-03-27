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
const int MAXN=305;
const int INF=0x7fffffff;
struct node{int x,y,c;};
vector<node>edge;
vector<int>g[MAXN];
int ind[MAXN],outd[MAXN],gap[MAXN],lev[MAXN];
int n,m,t,S,T,check,sum;
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+c-'0',c=getchar();
	return num*bj;
}
inline void Init()
{
	edge.clear();
	check=0,sum=0;
	for(ri i=0;i<=300;i++)g[i].clear(),gap[i]=lev[i]=ind[i]=outd[i]=0;
}
inline void AddEdge(int x,int y,int c)
{
	edge.push_back({x,y,c});
	edge.push_back({y,x,0});
	g[x].push_back(edge.size()-2);
	g[y].push_back(edge.size()-1);
}
inline int DFS(int now,int f)
{
	if(now==T)return f;
	int delta,ret=0;
	for(ri i=0;i<g[now].size();i++)
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
inline bool MaxFlow()
{
	int Ans=0;
	gap[0]=T+1;
	while(lev[S]<T+1)Ans+=DFS(S,INF);
	return Ans==sum;
}
int main()
{
	t=getint();
	while(t--)
	{
		Init();
		n=getint(),m=getint();
		S=0,T=n+1;
		for(ri i=1;i<=m;i++)
		{
			int x=getint(),y=getint(),s=getint();
			outd[x]++,ind[y]++;
			if(!s)AddEdge(x,y,1);
		}
		for(ri i=1;i<=n;i++)
		{
			int k=ind[i]-outd[i];
			if(k&1){check=1;break;}
			if(outd[i]>ind[i])AddEdge(S,i,(-k)>>1),sum+=(-k)>>1;
			if(ind[i]>outd[i])AddEdge(i,T,k>>1);
		}
		if(check){printf("impossible\n");continue;}
		if(MaxFlow())printf("possible\n");
		else printf("impossible\n");
	}
	return 0;
}