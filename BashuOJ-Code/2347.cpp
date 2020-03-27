#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
const int MAXN=405;
const int INF=0x7fffffff;
struct node{int x,y,c;};
vector<node>edge;
vector<int>g[MAXN]; 
int pig[MAXN],last[MAXN];
int N,M;
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
	int S,T,Ans;
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
		for(int i=0;i<g[now].size();i++)
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
		S=1,T=N+M+2; 
		gap[0]=N+M+2;
		while(lev[S]<T)Ans+=DFS(S,INF);
		printf("%d",Ans);
	}
};
SAP S;
int main(){
	N=GetInt();M=GetInt();
	for(int i=1;i<=M;i++)S.AddEdge(1,i+1,1);
	for(int i=1;i<=N;i++)
	{
		int x;
		while(scanf("%d",&x),x!=0)S.AddEdge(x+1,M+i+1,1);
	}
	for(int i=1;i<=N;i++)S.AddEdge(M+i+1,N+M+2,1);
	S.main();
	return 0;
}