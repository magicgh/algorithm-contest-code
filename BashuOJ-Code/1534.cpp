#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=85;
const int INF=0x7fffffff;
struct node{int x,y,c,f,a;};
int N,M,s,t,S,T,Sum;
vector<node>edge;
vector<int>g[MAXN];
int deg[MAXN];
void Init()
{
	Sum=0;
	edge.clear();
	for(int i=0;i<=MAXN-1;i++)deg[i]=0,g[i].clear();
}
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+c-'0',c=getchar();
	return num*bj;
}
inline int geti()
{
	int num=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='+')return s;
		if(c=='-')return t;
		c=getchar();
	}
	while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+c-'0',c=getchar();
	return num;
}
inline void AddEdge(int x,int y,int u,int d,int a)
{
	edge.push_back({x,y,u-d,0,a});
	edge.push_back({y,x,0,0,a});
	g[x].push_back(edge.size()-2);
	g[y].push_back(edge.size()-1);
}
struct MaxFlow
{
	int lev[MAXN],gap[MAXN];
	void Init()
	{
		memset(lev,0,sizeof(lev));
		memset(gap,0,sizeof(gap));
	}
	int DFS(int now,int f,int a)
	{
		if(now==T)return f;
		int ret=0,delta;
		for(int i=0;i<g[now].size();i++)
		{
			node& next=edge[g[now][i]];
			if(next.f<next.c&&lev[next.x]==lev[next.y]+1&&(next.a|a))
			{
				delta=DFS(next.y,min(next.c-next.f,f),a);
				ret+=delta,f-=delta;
				edge[g[now][i]].f+=delta,edge[g[now][i]^1].f-=delta; 
				if(!f||lev[S]==N+4)return ret;
			}
		}
		if(!(--gap[lev[now]]))lev[S]=N+4;
		gap[++lev[now]]++;
		return ret;
	}
	void main()
	{
		int ans=0;
		Init();gap[0]=T;
		while(lev[S]<N+4)ans+=DFS(S,INF,1);
		if(ans!=Sum){printf("impossible\n");return;}
		Init();gap[0]=N+4;
		S=t,T=s;
		ans=edge[edge.size()-2].f;
		while(lev[S]<N+4)ans-=DFS(S,INF,0);
		printf("%d\n",ans);
	}
};
MaxFlow SAP;
int main()
{
	while(scanf("%d%d",&N,&M))
	{
		if(!N&&!M)break;
		Init();
		s=N+1,t=s+1,S=t+1,T=S+1;
		for(int i=1;i<=M;i++)
		{
			int x=geti(),y=geti(),z=getint();
			AddEdge(x,y,INF,z,1);deg[x]-=z,deg[y]+=z;
		}
		for(int i=1;i<=t;i++)
		{
			if(deg[i]>0)AddEdge(S,i,deg[i],0,0),Sum+=deg[i];
			if(deg[i]<0)AddEdge(i,T,-deg[i],0,0);
		}
		AddEdge(t,s,INF,0,0);
		SAP.main();
	}
	return 0;
}
