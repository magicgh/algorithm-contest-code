#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define ri register int
#define ll long long
using namespace std;
const int MAXN=205;
const int INF=0x7fffffff/2;
struct heap
{
	int key,val;
	bool operator <(const heap &rhs)
	const {return val>rhs.val;};
};
struct node{int to,val;};
vector<node>a[MAXN];
vector<int>b[MAXN];
priority_queue<heap>q;
int N,M,S;
int dist[MAXN],prt[MAXN],Deg[MAXN];
double P[MAXN][MAXN],f[MAXN][MAXN],g[MAXN][MAXN];
bool vst[MAXN];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline void Dijkstra(int v0)
{
	for(int i=1;i<=N;i++)dist[i]=INF;
	dist[v0]=prt[v0]=0;
	q.push((heap){v0,dist[v0]});
	while(!q.empty())
	{
		heap now=q.top();
		q.pop();
		if(!vst[now.key])
		{
			vst[now.key]=1;
			vector<node>::iterator it;
			for(it=a[now.key].begin();it!=a[now.key].end();++it)
			{
				if(!vst[it->to]&&dist[it->to]>dist[now.key]+it->val)
				{
					prt[it->to]=now.key;
					dist[it->to]=dist[now.key]+it->val;
					q.push((heap){it->to,dist[it->to]});
				}
			}
		}
	}
}
void Build()
{
	for(ri i=1;i<=N;i++)
		if(prt[i])b[prt[i]].push_back(i),Deg[prt[i]]++;
	for(ri i=1;i<=N;i++)
		if(!Deg[i])
			for(ri j=1;j<=S;j++)f[i][j]=P[i][j];
}
void Tree_DP(int u)
{
	vector<int>::iterator it;
	for(it=b[u].begin();it!=b[u].end();++it)
	{
		Tree_DP(*it);
		for(ri j=S;j>=0;j--)
			for(ri k=0;k<=j;k++)
				g[u][j]=max(g[u][j],g[u][j-k]+f[*it][k]/(double)Deg[u]);
		for(ri j=S;j>=0;j--)
			for(ri k=0;k<=j;k++)
				f[u][j]=max(f[u][j],g[u][j-k]*(1.0-P[u][k])+P[u][k]);
	}
}
int main()
{
	N=getint(),M=getint();
	for(ri i=1;i<=M;i++)
	{
		int u=getint(),v=getint(),w=getint();
		a[u].push_back((node){v,w});
		a[v].push_back((node){u,w});
	}
	S=getint();
	for(ri i=1;i<=N;i++)
		for(ri j=1;j<=S;j++)scanf("%lf",&P[i][j]);
	Dijkstra(1);
	Build();
	Tree_DP(1);
	printf("%.4lf",f[1][S]);
	return 0;
}

