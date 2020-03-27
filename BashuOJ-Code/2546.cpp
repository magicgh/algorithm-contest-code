#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
const int MAXN=1005;
const int INF=0x7fffffff;
struct node{int x,y,c;};
vector<node>edge;
vector<int>g[MAXN]; 
int N,M,S,T,Max=-INF,sum;
int at[MAXN];
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+c-'0',c=getchar();
	return num*bj;
}
inline void AddEdge(int x,int y,int c)
{
	edge.push_back({x,y,c});
	edge.push_back({y,x,0});
	g[x].push_back(edge.size()-2);
	g[y].push_back(edge.size()-1);
}
struct SAP
{
	int lev[MAXN],gap[MAXN];
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
		int Ans=0;
		gap[0]=T+1;
		while(lev[S]<T)Ans+=DFS(S,INF);
		printf("%d\n",Ans==sum?1:0);
	}
};
SAP st;
int main(){
	N=GetInt();M=GetInt();S=0,T=N+M+1;
	for(int i=1;i<=N;i++)
	{
		int x=GetInt();sum+=x;
		AddEdge(S,i,x);Max=max(Max,x);
	}
	if(Max>M){printf("0\n");return 0;}
	for(int i=1;i<=M;i++)
	{
		int x=GetInt();
		AddEdge(i+N,T,x);
	}
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++)
		AddEdge(i,j+N,1);
	st.main();
	return 0;
}