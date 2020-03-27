#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<deque>
using namespace std;
const int MAXN=505;
const int INF=0x7fffffff;
struct node{int x,y,c,w;};
vector<node>Edge;
vector<int>G[MAXN];
int N,M,S,T,Ans;
int dist[MAXN],prt[MAXN],prtEdge[MAXN];
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
		memset(ext,0,sizeof(ext));
		memset(prt,0,sizeof(prt));
		for(int i=1;i<=N;i++)dist[i]=INF;
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
int main(){
	N=GetInt();
	S=1,T=N;
	while(true)
	{
		int x=GetInt(),y=GetInt(),c=GetInt(),w=GetInt();
		if(x==0&&y==0&&c==0&&w==0)break;
		AddEdge(x,y,c,w);
	}
	while(SPFA(S,T))Adjust();
	printf("%d",Ans);
	return 0;
}