#include<cstdio>
#include<deque>
#include<list>
#include<iostream>
using namespace std;
int N,M;
struct node
{
	int to,val;
};
struct SPFA
{
	list<node>a[10005];
	int dist[10005],used[10005];
	bool ext[10005];			
	void AddEdge(int x,int y,int z)
	{
		a[x].push_back((node){y,z});
		return;
	}
	bool spfa(int v0)
	{
		deque<int>q;
		list<node>::iterator next;
		for(int i=1;i<=N;i++)dist[i]=-0x7fffffff;
		q.push_back(v0);dist[v0]=0;ext[v0]=1;
		while(!q.empty())
		{
			int now=q.front();
			q.pop_front();
			ext[now]=0;
			for(next=a[now].begin();next!=a[now].end();++next)
			{
				if(dist[next->to]<dist[now]+next->val)
				{
					dist[next->to]=dist[now]+next->val;
					if(!ext[next->to])
					{
						if(++used[next->to]>=N)return 0;
						if(!q.empty()&&dist[q.front()]<dist[next->to])q.push_front(next->to);
						else q.push_back(next->to);
					}
				}                                                                                      
			}
		}
		return 1;
	}
};
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(bj==-1||c=='-')?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
SPFA Path;
int main()
{
	N=GetInt();
	M=GetInt();
	int u,v,w;
	if(M==0){printf("-1");return 0;}
	for(int i=1;i<=M;i++)
	{
		u=GetInt();
		v=GetInt();
		w=GetInt();
		Path.AddEdge(u,v,w);
	}
	if(Path.spfa(1))
	printf("%d",Path.dist[N]==-0x7fffffff?-1:Path.dist[N]);
	else printf("-1");
	return 0;
}