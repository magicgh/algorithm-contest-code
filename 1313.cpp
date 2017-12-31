#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
const int MAXN=205;
const int INF=0x7fffffff;
struct node{int x,y,c;};
vector<node>edge;
vector<int>g[MAXN]; 
int N;
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+c-'0',c=getchar();
	return num*bj;
}
struct Dinic
{
	int S,T,Ans;
	int lev[MAXN];
	inline void AddEdge(int x,int y,int c)
	{
		edge.push_back({x,y,c});
		edge.push_back({y,x,0});
		g[x].push_back(edge.size()-2);
		g[y].push_back(edge.size()-1);
	}
	bool BFS()
	{
		memset(lev,0,sizeof(lev));
		queue<int>q;
		q.push(S);
		lev[S]=1;
		while(!q.empty())
		{
			int now=q.front();q.pop();
			if(now==T)return true;
			for(int i=0;i<g[now].size();i++)
			{
				node& next=edge[g[now][i]];
				if(!lev[next.y]&&next.c>0)
				{
					q.push(next.y);
					lev[next.y]=lev[now]+1;
				}
			}
		}
	    return false;
	}
	int DFS(int now,int f)
	{
		if(now==T)return f;
		int ret=0,delta;
		for(int i=0;i<g[now].size();i++)
		{
			node& next=edge[g[now][i]];
			if(next.c>0&&lev[next.y]==lev[next.x]+1)
			{
				delta=DFS(next.y,min(f,next.c));
				edge[g[now][i]].c-=delta;
				edge[g[now][i]^1].c+=delta;
				ret+=delta;f-=delta;
				if(!f)return ret;
			}
		}
		return ret;
	}
	void main()
	{
		S=1,T=N; 
		while(BFS())Ans+=DFS(S,INF);
		printf("%d",Ans);
	}
};
Dinic DC;
int main(){
	N=GetInt();
	for(int i=1;i<=N;i++)
	for(int j=1;j<=N;j++)
	{
		int x=GetInt();
		if(x)DC.AddEdge(i,j,x);
	}
	DC.main();
	return 0;
}