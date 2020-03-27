#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define ri register int
using namespace std;
const int MAXN=505;
const int INF=0x7fffffff;
struct node{int x,y,c;};
vector<node>edge;
vector<int>g[MAXN]; 
int N,A,B,S,T;
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+c-'0',c=getchar();
	return num*bj;
}
struct SAP
{
	int Ans;
	int lev[MAXN],gap[MAXN];
	inline void AddEdge(int x,int y,int c)
	{
		edge.push_back({x,y,c});
		edge.push_back({y,x,0});
		g[x].push_back(edge.size()-2);
		g[y].push_back(edge.size()-1);
	}
	int DFS(int now,int f)
	{
		if(now==T)return f;
		int ret=0,delta;
		for(unsigned ri i=0;i<g[now].size();i++)
		{
			node& next=edge[g[now][i]];
			if(next.c>0&&lev[next.x]==lev[next.y]+1)
			{
				delta=DFS(next.y,min(f,next.c));
				edge[g[now][i]].c-=delta;
				edge[g[now][i]^1].c+=delta;
				ret+=delta;f-=delta;
				if(!f||lev[S]==T)return ret;
			}
		}
		if(!(--gap[lev[now]]))lev[S]=T;
		gap[++lev[now]]++;
		return ret;
	}
	void main()
	{
		gap[0]=T+1;
		while(lev[S]<T)Ans+=DFS(S,INF);
		printf("%d",Ans);
	}
};
SAP MaxFlow;
int main(){
	N=GetInt(),A=GetInt(),B=GetInt(),S=0,T=2*N+A+B+1;
	for(ri i=1;i<=A;i++)MaxFlow.AddEdge(S,2*N+i,1);
	for(ri i=1;i<=B;i++)MaxFlow.AddEdge(2*N+A+i,T,1);
	for(ri i=1;i<=N;i++)MaxFlow.AddEdge(i,N+i,1);
	for(int i=1;i<=N;i++)
	{
		int n=GetInt(),m=GetInt();
		for(ri j=1;j<=n;j++)
		{
			int t=GetInt();
			MaxFlow.AddEdge(2*N+t,i,1);
		}
		for(ri j=1;j<=m;j++)
		{
			int t=GetInt();
			MaxFlow.AddEdge(N+i,2*N+A+t,1);
		}
	}
	MaxFlow.main();
	return 0;
}