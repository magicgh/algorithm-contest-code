#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
const int MAXN=305;
const int INF=0x7fffffff;
struct node{int x,y,c;};
vector<node>Edge;
vector<int>G[MAXN];
int K,N,M,Check,Ans,S,T;
int Deg[MAXN],lev[MAXN],gap[MAXN];
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline void AddEdge(int x,int y,int c)
{
	Edge.push_back({x,y,c});
	Edge.push_back({y,x,0});
	G[x].push_back(Edge.size()-2);
	G[y].push_back(Edge.size()-1);
}
int DFS(int now,int f)
{
	if(now==T)return f;
	int ret=0,delta;
	for(int i=0;i<G[now].size();i++)
	{
		node& next=Edge[G[now][i]];
		if(next.c>0&&lev[next.x]==lev[next.y]+1)
		{
			delta=DFS(next.y,min(next.c,f));
			ret+=delta;f-=delta;
			Edge[G[now][i]].c-=delta;Edge[G[now][i]^1].c+=delta;
			if(!f||lev[S]==T)return ret;
		}
	}
	if(!(--gap[lev[now]]))lev[S]=T;
	gap[++lev[now]]++;
	return ret;
}
int main(){
	K=GetInt();
	while(K--)
	{
		N=GetInt(),M=GetInt();
		memset(Deg,0,sizeof(Deg));
		memset(lev,0,sizeof(lev));
		memset(gap,0,sizeof(gap));
		Edge.clear();Check=0;Ans=0;
		for(int i=0;i<=N+1;i++)G[i].clear();
		for(int i=1;i<=M;i++)
		{
			int x=GetInt(),y=GetInt(),d=GetInt(),u=GetInt();
			Deg[x]-=d,Deg[y]+=d;AddEdge(x,y,u-d);
		}
		S=0,T=N+1;
		for(int i=1;i<=N;i++)
		{
			if(Deg[i]>0)AddEdge(S,i,Deg[i]),Check+=Deg[i];//流入补充 
			else AddEdge(i,T,-Deg[i]);//流出补充 
		}
		gap[0]=T+1;
		while(lev[S]<T)Ans+=DFS(S,INF);//流量守恒 
		if(Ans==Check)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
