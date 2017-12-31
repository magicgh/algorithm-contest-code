#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<deque>
using namespace std;
const int MAXN=160801;
const int INF=0x7fffffff;
struct node{int to,val;};
vector<node>a[MAXN];
int M,N,S,T;
int map[405][405];
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+c-'0',c=getchar();
	return num*bj; 
}
void Init()
{
	for(int i=0;i<=N*N;i++)a[i].clear();
}
inline void Link(int i,int j)
{
	int Num=(i-1)*(N-1)+j,R=Num+1,D=Num+N-1;
	if(j<N-1)a[Num].push_back({R,map[i][j+1]}),a[R].push_back({Num,map[i][j+1]});
	if(i<N-1)a[Num].push_back({D,map[i+1][j]}),a[D].push_back({Num,map[i+1][j]});
}
struct SPFA
{
	int dist[MAXN];
	bool ext[MAXN];
	bool Core(int v0)
	{
		deque<int>q;
		for(int i=1;i<=T+1;i++)dist[i]=INF;
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
		memset(ext,0,sizeof(ext));
		Core(S);
		printf("%d\n",dist[T]);
	}
};
SPFA ShortPath;
int main()
{
	M=GetInt();
	for(int k=1;k<=M;k++)
	{
		N=GetInt();Init();
		for(int i=1;i<=N;i++)
			for(int j=1;j<=N;j++)map[i][j]=GetInt();
		S=0,T=(N-1)*(N-1)+1; 
		for(int i=1;i<=N-1;i++)
			for(int j=1;j<=N-1;j++)Link(i,j);
		for(int i=1;i<=N-1;i++)
		{
			a[S].push_back({i,map[1][i]});
			a[S].push_back({i*(N-1),map[i][N]});
			a[(i-1)*(N-1)+1].push_back({T,map[i][1]});
			a[(N-2)*(N-1)+i].push_back({T,map[N][i]});
		}
		ShortPath.main();
	}
	return 0;
}
