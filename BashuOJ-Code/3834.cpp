#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<deque> 
using namespace std;
const int MAXN=20005005;
const int INF=0x7fffffff;
struct node{int to,val;};
vector<node>a[MAXN];
int map[3][1005][1005],num[3][1005][1005];
int N,M,S,T;
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+c-'0',c=getchar();
	return num*bj; 
}
inline void AddEdgeD(int x,int y,int z)
{
	a[x].push_back({y,z});
	a[y].push_back({x,z});
}
inline void AddEdge(int x,int y,int z){a[x].push_back({y,z});}
void BuildGraph()
{
	for(int i=1;i<=M-1;i++)AddEdge(S,num[1][1][i],map[0][1][i]);
	for(int i=2;i<=N-1;i++)
		for(int j=1;j<=M-1;j++)AddEdgeD(num[0][i-1][j],num[1][i][j],map[0][i][j]);
	for(int j=1;j<=M-1;j++)AddEdge(num[0][N-1][j],T,map[0][N][j]);
	for(int i=1;i<=N-1;i++)
	{
		AddEdge(num[0][i][1],T,map[1][i][1]);
		for(int j=2;j<=M-1;j++)
		{
			AddEdgeD(num[1][i][j-1],num[0][i][j],map[1][i][j]);
		}
		AddEdge(S,num[1][i][M-1],map[1][i][M]);
	}
	for(int i=1;i<=N-1;i++)
		for(int j=1;j<=M-1;j++)AddEdgeD(num[0][i][j],num[1][i][j],map[2][i][j]);
}
struct SPFA
{
	int dist[2000005];
	bool ext[2000005];
	bool Core(int v0)
	{
		deque<int>q;
		for(int i=0;i<=T;i++)dist[i]=INF;
		q.push_front(v0);dist[v0]=0;ext[v0]=1;
		while(!q.empty())
		{
			int now=q.front();q.pop_front();ext[now]=0;
			vector<node>::iterator it;
			for(it=a[now].begin();it!=a[now].end();++it)
			{
				if(dist[it->to]>dist[now]+it->val)
				{
					dist[it->to]=dist[now]+it->val;
					if(!ext[it->to])
					{
						if(!q.empty()&&dist[q.front()]>dist[it->to])q.push_front(it->to);
						else q.push_back(it->to);
						ext[it->to]=1;
					}
				}
			}
		}
	return 1;
	}
	void main()
	{
		Core(S);
		printf("%d\n",dist[T]);
	}
};
SPFA ShortPath;
int main()
{
	N=GetInt();M=GetInt();
	S=0,T=(N-1)*(M-1)*2+1;
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M-1;j++)map[0][i][j]=GetInt();
	for(int i=1;i<=N-1;i++)
		for(int j=1;j<=M;j++)map[1][i][j]=GetInt();
	for(int i=1;i<=N-1;i++)
		for(int j=1;j<=M-1;j++)map[2][i][j]=GetInt();
		int cnt=0;
	for(int i=1;i<=N-1;i++)
		for(int j=1;j<=M-1;j++)num[0][i][j]=++cnt,num[1][i][j]=++cnt;
	BuildGraph();
	ShortPath.main();
	return 0;
}
