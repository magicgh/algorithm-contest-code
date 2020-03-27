#include<iostream>
#include<cstdio>
#include<deque>
#include<vector>
using namespace std;
const int INF=0x7fffffff/2;
const int MAXN=5005;
int N,M;
struct node{int to,val;};
vector<node>a[MAXN];
void AddEdge(const int &x,const int &y,const int &z){a[x].push_back((node){y,z});}
struct SPFA
{
	int dist[MAXN],used[MAXN];
	bool ext[MAXN];			
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
					}
				}                                                                                      
			}
		}
		return 1;
	}
};
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(bj==-1||c=='-')?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
SPFA Path;
int main() __attribute__((optimize("-O2")));
int main()
{
	N=getint(),M=getint();
	for(int i=1;i<=M;i++)
	{
		int u=getint(),v=getint(),w=getint();
		AddEdge(u,v,w);
	}
	Path.spfa(1);
	printf("%d",Path.dist[N]);
	return 0;
	
}