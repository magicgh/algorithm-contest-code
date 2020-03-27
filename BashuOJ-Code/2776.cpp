#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<deque>
using namespace std;
const int MAXN=55;
const int INF=0x7fffffff;
struct node{int x,y,c,w;};
vector<node>Edge;
vector<int>G[MAXN];
int N,M,S,T,K,Ans;
int u[MAXN],d[MAXN],dist[MAXN],prt[MAXN],prtEdge[MAXN];
bool ext[MAXN];
inline void AddEdge(int x,int y,int c,int w)
{
	Edge.push_back({x,y,c,w});
	Edge.push_back({y,x,0,-w});
	G[x].push_back(Edge.size()-2);
	G[y].push_back(Edge.size()-1);
}
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+c-'0',c=getchar();
	return num*bj;
}
inline bool SPFA(int v0,int vn)
{
		deque<int>q;
		for(int i=0;i<=N+1;i++)dist[i]=INF,prt[i]=0,prtEdge[i]=0;
		q.push_front(v0);dist[v0]=0;ext[v0]=1;
		while(!q.empty())
		{
			int now=q.front();
			q.pop_front();
			ext[now]=0;
			for(int i=0;i<G[now].size();i++)
			{
				node& next=Edge[G[now][i]];
				if(next.c&&dist[next.y]>dist[next.x]+next.w)
				{
					dist[next.y]=dist[next.x]+next.w;
					prt[next.y]=next.x;
					prtEdge[next.y]=G[now][i];
					if(!ext[next.y])
					{
						ext[next.y]=1;
						if(!q.empty()&&dist[q.front()]>dist[next.y])q.push_front(next.y);
						else q.push_back(next.y);
					}
				}                                                                                      
			}
		}
		if(dist[T]<INF)return 1;
		else return 0;
}
inline void Adjust()
{
	int delta=INF;
	for(int i=T;i!=S;i=prt[i])delta=min(delta,Edge[prtEdge[i]].c);
	for(int i=T;i!=S;i=prt[i])
	{
		Edge[prtEdge[i]].c-=delta;
		Edge[prtEdge[i]^1].c+=delta;	
	}
	Ans+=dist[T]*delta;
}
int main()
{
	N=GetInt();M=GetInt();K=GetInt();
	S=0,T=N+1;
	for(int i=1;i<=N;i++)u[i]=GetInt();
	for(int i=1;i<=N;i++)d[i]=GetInt();
	for(int i=1;i<=N;i++)
	{ 
	AddEdge(S,i,INF,d[i]);//每月的需求 
	AddEdge(i,T,u[i],0);//当月的销售
	if(i<N)AddEdge(i,i+1,K,M);//剩余的留到下一个月
	} 
	while(SPFA(S,T))Adjust();
	printf("%d",Ans);
   return 0;
}
