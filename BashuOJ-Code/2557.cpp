#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<deque>
using namespace std;
const int MAXN=155;
const int INF=0x7fffffff;
struct node{int x,y,c,w;};
vector<node>Edge;
vector<int>G[MAXN];
int N,M,S,T,Ans;
int dist[MAXN],prt[MAXN],prtEdge[MAXN];
int a[MAXN],b[MAXN],c[MAXN][MAXN];
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
inline void BuildGraph(int k)
{
	S=0,T=M+N+1;
	for(int i=1;i<=M;i++)AddEdge(S,i,a[i],0);
	for(int i=1;i<=N;i++)AddEdge(i+M,T,b[i],0);
	for(int i=1;i<=M;i++)
		for(int j=1;j<=N;j++)AddEdge(i,j+M,INF,k*c[i][j]);
}
void Init()
{
	Ans=0;
	Edge.clear();
	for(int i=0;i<=M+N+1;i++)G[i].clear();
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
	M=GetInt(),N=GetInt();
	for(int i=1;i<=M;i++)a[i]=GetInt();
	for(int i=1;i<=N;i++)b[i]=GetInt();
	for(int i=1;i<=M;i++)
		for(int j=1;j<=N;j++)c[i][j]=GetInt();
	BuildGraph(1);
	while(SPFA())Adjust();
	printf("%d\n",Ans);
	Init();
	BuildGraph(-1);
	while(SPFA())Adjust();
	printf("%d",-Ans);
	return 0;
}