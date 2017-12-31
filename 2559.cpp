#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<deque>
using namespace std;
const int MAXN=205;
const int INF=0x7fffffff;
struct node{int x,y,c,w;};
vector<node>Edge;
vector<int>G[MAXN];
int N,S,T,Ans;
double M;
int dist[MAXN],prt[MAXN],prtEdge[MAXN],a[MAXN];
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
inline void BuildGraph()
{
	S=0,T=2*N+1;
	for(int i=1;i<=N;i++)
	{
		if(a[i]-M>0)AddEdge(S,i,a[i]-M,0);
		else AddEdge(i+N,T,M-a[i],0);
	}
	for(int i=1;i<=N;i++)
	{
		AddEdge(i,(i+N)%N+1,INF,1);
		AddEdge(i,(N-2+i)%N+1,INF,1);
		AddEdge(i,(i+N)%N+1+N,INF,1);
		AddEdge(i,(N-2+i)%N+1+N,INF,1);
	}
}
inline bool SPFA()
{
		deque<int>q;
		memset(ext,0,sizeof(ext));
		memset(prt,0,sizeof(prt));
		for(int i=S;i<=T;i++)dist[i]=INF;
		q.push_front(S);dist[S]=0;ext[S]=1;
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
	for(int i=1;i<=N;i++)M+=a[i]=GetInt();M/=double(N);
	BuildGraph();
	while(SPFA())Adjust();
	printf("%d",Ans);
	return 0;
}