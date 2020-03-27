#include<cstdio>
#include<deque>
#include<vector>
#include<iostream>
using namespace std;
const int INF=0x7fffffff;
int N,A,B,C,ans=0x7fffffff,id;
struct node{int to,val;};
vector<node>a[20005];
void AddEdge(int x,int y,int z){a[x].push_back((node){y,z}),a[y].push_back((node){x,z});}
struct SPFA
{
	int dist[20005],used[20005];
	bool ext[20005];			
	bool spfa(int v0)
	{
		deque<int>q;
		vector<node>::iterator next;
		for(int i=1;i<=N;i++)dist[i]=INF;
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
						else q.push_back(next->to);
						ext[next->to]=1;
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
SPFA Path1,Path2,Path3;
int main()
{
	N=GetInt(),A=GetInt(),B=GetInt(),C=GetInt();
	int u,v,w;
	for(int i=1;i<=N-1;i++)
	{
		u=GetInt();
		v=GetInt();
		w=GetInt();
		AddEdge(u,v,w);
	}
	Path1.spfa(A);
	Path2.spfa(B);
	Path3.spfa(C);
	for(int i=1;i<=N;i++)
	{
		if(ans>Path1.dist[i]+Path2.dist[i]+Path3.dist[i])
		{
			ans=Path1.dist[i]+Path2.dist[i]+Path3.dist[i];
			id=i;
		}
	}
	printf("%d\n%d",id,ans);
	return 0;
	
}