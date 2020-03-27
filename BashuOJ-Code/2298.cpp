#include<cstdio>
#include<deque>
#include<vector>
#include<iostream>
using namespace std;
int N,M;
struct node{int to,val;};
struct SPFA
{
	vector<node>a[100005];
	int dist[100005],used[100005];
	bool ext[100005];			
	inline void AddEdge(int x,int y,int z)
	{
		a[x].push_back((node){y,z});
		return;
	}
	bool spfa(int v0)
	{
		deque<int>q;
		vector<node>::iterator next;
		for(int i=1;i<=N;i++)dist[i]=0x7fffffff;
		q.push_back(v0);dist[v0]=0;ext[v0]=1;
		while(!q.empty())
		{
			int now=q.front();
			q.pop_front();
			ext[now]=0;
			for(next=a[now].begin();next!=a[now].end();++next)
			{
				if(dist[next->to]>dist[now]+next->val)
				{
					dist[next->to]=dist[now]+next->val;
					if(!ext[next->to])
					{
						if(++used[next->to]>=N)return 0;
						if(!q.empty()&&dist[q.front()]>dist[next->to])q.push_front(next->to);
						else q.push_back(next->to),ext[next->to]=1;
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
	int u,v;
	for(int i=1;i<=M;i++)
	{
		u=GetInt();
		v=GetInt();
		Path.AddEdge(u,v,1);
	}
	Path.spfa(1);
	printf("%d",Path.dist[N]+1);
	return 0;
	
}