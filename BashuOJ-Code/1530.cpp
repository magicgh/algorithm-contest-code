#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
const int MAXN=4005;
const int INF=0x7fffffff;
struct node{int x,y,c;};
vector<node>Edge;
vector<int>G[MAXN];
bool vst[MAXN];
int cost[MAXN];
int N,M,S,T,Total,Ans,cnt;
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
	Edge.push_back({x,y,c});
	Edge.push_back({y,x,0});
	G[x].push_back(Edge.size()-2);
	G[y].push_back(Edge.size()-1);
}
void DFS(int x)
{
	vst[x]=1;cnt++;
	for(int i=0;i<G[x].size();i++)
	{
		node& next=Edge[G[x][i]];
		if(next.c>0&&!vst[next.y])DFS(next.y);
	}
}
struct SAP
{
	int lev[MAXN],gap[MAXN];
	int DFS(int now,int f)
	{
		if(now==T)return f;
		int delta,ret=0;
		for(int i=0;i<G[now].size();i++)
		{
			node& next=Edge[G[now][i]];
			if(next.c>0&&lev[next.x]==lev[next.y]+1)
			{
			delta=DFS(next.y,min(next.c,f));
			Edge[G[now][i]].c-=delta;
			Edge[G[now][i]^1].c+=delta;
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
	}
};
SAP st;
int main(){
	N=GetInt();
	M=GetInt();
	S=0,T=N+1;
	for(int i=1;i<=N;i++)cost[i]=GetInt();
	for(int i=1;i<=M;i++)
	{
		int x=GetInt(),y=GetInt();
		AddEdge(x,y,INF);
	}
	for(int i=1;i<=N;i++)
	{
		if(cost[i]>=0)AddEdge(S,i,cost[i]),Total+=cost[i];
		else AddEdge(i,T,-cost[i]);
	}
	st.main();
	DFS(S);
	printf("%d %d",cnt-1,Total-Ans);
	return 0;
}
