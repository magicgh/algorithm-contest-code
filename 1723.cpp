#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
const int MAXN=505;
const int INF=0x7fffffff;
struct node{int x,y,c,f,a;};//c容量 f流量 
int N,M,s,t,S,T,sum;
vector<node>edge;
vector<int>g[MAXN];
int deg[MAXN],indeg[MAXN],outdeg[MAXN];
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(bj==-1||c=='-')?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
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
			//next.f<next.c 流量守恒		
			if(next.f<next.c&&lev[next.x]==lev[next.y]+1&&(next.a|a))//位运算判断关于S,T的边 
			{
				delta=DFS(next.y,min(next.c-next.f,f),a);//剩余流 
				ret+=delta,f-=delta;
				edge[g[now][i]].f+=delta,edge[g[now][i]^1].f-=delta;//加流 
				if(!f||lev[S]==N+2)return ret;
			}
		}
		if(!(--gap[lev[now]]))lev[S]=N+2;
		gap[++lev[now]]++;
		return ret;
	}
	int main()
	{
		int ans=0;
		gap[0]=N+2;
		while(lev[S]<N+2)ans+=DFS(S,INF,1);
		if(ans!=sum)return -1;
		Init();gap[0]=N+2;
		S=s,T=t;
		ans=edge[edge.size()-2].f;//原t->s的流 (可行流) 
		while(lev[S]<N+2)ans+=DFS(S,INF,0);//最大流-可行流 
		return ans;
	}
};
MaxFlow SAP;
int main()
{
	N=GetInt(),M=GetInt();
	s=1,t=N;
	for(int i=1;i<=M;i++)
	{
		int x=GetInt(),y=GetInt(),d=GetInt(),u=GetInt();
		AddEdge(x,y,u,d,1);deg[x]-=d,deg[y]+=d;
		indeg[y]++;outdeg[x]++;
	}
	S=t+1,T=S+1;
	for(int i=1;i<=N;i++)
	{
		if(deg[i]>0)AddEdge(S,i,deg[i],0,0),sum+=deg[i];
		if(deg[i]<0)AddEdge(i,T,-deg[i],0,0);
	}
	AddEdge(t,s,INF,0,0);
	printf("%d",SAP.main());
}