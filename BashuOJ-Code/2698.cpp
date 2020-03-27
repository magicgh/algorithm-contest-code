#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<deque>
using namespace std;
const int MAXN=5005;
const int INF=0x7fffffff;
struct node{int x,y,c,w;};
vector<node>Edge;
vector<int>G[MAXN];
node cache[MAXN];
int N,M,K,S,T;
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
struct MaxFlow
{
	int Ans,gap[MAXN],lev[MAXN];
	int DFS(int now,int f)
	{
		if(now==T)return f;
		int ret=0,delta;
		for(int i=0;i<G[now].size();i++)
		{
			node& next=Edge[G[now][i]];
			if(next.c>0&&lev[next.x]==lev[next.y]+1)
			{
				delta=DFS(next.y,min(f,next.c));
				f-=delta;ret+=delta;
				Edge[G[now][i]].c-=delta,Edge[G[now][i]^1].c+=delta;
				if(!f||lev[S]==T)return ret;
			}
		}
		if(!--(gap[lev[now]]))lev[S]=T;
		gap[++lev[now]]++;
		return ret;
	}
	int main()
	{
		gap[0]=N;
		while(lev[S]<N)Ans+=DFS(S,INF);
		return Ans;
	}
};
MaxFlow SAP;
struct CostFlow
{
	int Ans,dist[MAXN],prt[MAXN],prtG[MAXN];
	bool ext[MAXN];
	bool SPFA()
	{
		deque<int>q; 
		for(int i=0;i<=N;i++)dist[i]=INF,ext[i]=0,prt[i]=0,prtG[i]=0;
		q.push_front(S);dist[S]=0;ext[S]=1;
		while(!q.empty())
		{
			int now=q.front();q.pop_front();ext[now]=0;
			for(int i=0;i<G[now].size();i++)
			{
				node& next=Edge[G[now][i]];
				if(next.c&&dist[next.y]>dist[next.x]+next.w)
				{
					dist[next.y]=dist[next.x]+next.w;
					prt[next.y]=next.x;prtG[next.y]=G[now][i];
					if(!ext[next.y])
					{
						ext[next.y]=1;
						if(!q.empty()&&dist[q.front()]>dist[next.y])q.push_front(next.y);
						else q.push_back(next.y);
					}
				}
			}
		}
		return dist[T]<INF;
	}
	inline void Adjust()
	{
		int delta=INF;
		for(int i=T;i!=S;i=prt[i])delta=min(delta,Edge[prtG[i]].c);
		for(int i=T;i!=S;i=prt[i])
		{
			Edge[prtG[i]].c-=delta;	
			Edge[prtG[i]^1].c+=delta;
		}
		Ans+=delta*dist[T];
	}
	int main()
	{
		while(SPFA())Adjust();
		return Ans;
	}
};
CostFlow SCF;
int main()
{
	N=GetInt();M=GetInt();K=GetInt();
	S=1,T=N;
	for(int i=1;i<=M;i++)
	{
		cache[i]=((node){GetInt(),GetInt(),GetInt(),GetInt()});
		AddEdge(cache[i].x,cache[i].y,cache[i].c,0);
	}
	printf("%d ",SAP.main());
	for(int i=1;i<=M;i++)AddEdge(cache[i].x,cache[i].y,INF,cache[i].w);//随便流 
	S=0;AddEdge(S,1,K,0);//限制源点最多再流K的值 
	printf("%d\n",SCF.main());
   return 0;
}
