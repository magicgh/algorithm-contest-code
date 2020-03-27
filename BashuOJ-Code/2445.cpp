#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<deque>
using namespace std;
const int MAXN=2005;
const int INF=0x7fffffff;
struct node{int x,y,c,w;};
vector<node>Edge;
vector<int>G[MAXN];
int n,p,m,f,s,t,S,T;
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
struct CostFlow
{
	int Ans,dist[MAXN],prt[MAXN],prtG[MAXN];
	bool ext[MAXN];
	bool SPFA()
	{
		deque<int>q; 
		for(int i=0;i<=T;i++)dist[i]=INF,ext[i]=0,prt[i]=0,prtG[i]=0;
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
	n=GetInt();p=GetInt();
	m=GetInt();f=GetInt();
	t=GetInt();s=GetInt();
	S=0,T=2*n+1;
	//拆点为干净餐巾和脏餐巾 
	for(int i=1;i<=n;i++)
	{
		int x=GetInt();
		AddEdge(S,i,x,0);//每天所需的脏餐巾
		AddEdge(S,i+n,INF,p);//每天所购买的餐巾
		if(i+m+n<=2*n)AddEdge(i,i+m+n,INF,f);//每天快洗的餐巾 
		if(i+t+n<=2*n)AddEdge(i,i+t+n,INF,s);//每天慢洗的餐巾
		AddEdge(i+n,T,x,0);//每天所用的干净餐巾
		if(i+1<=n)AddEdge(i,i+1,INF,0);//延期送洗的脏餐巾 
	}
	printf("%d",SCF.main());
   return 0;
}