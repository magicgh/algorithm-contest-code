#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define ri register int
#define ll long long
using namespace std;
const int MAXN=10005;
const int INF=0x7fffffff/2;
int N,M,K,S,T,cnt,delta,Ans=INF;
int dist[MAXN][15];
bool vst[MAXN][15];
priority_queue<int>q;
struct node{int to,val;};
struct heap
{
	int u,dist,cnt;
	bool operator <(const heap &rhs)
	const{return dist>rhs.dist;} 
};
vector<node>a[MAXN];
inline const int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
void Dijsktra(int v0)
{
	priority_queue<heap>q;
	for(ri i=0;i<=N;i++)
		for(ri j=0;j<=10;j++)
			dist[i][j]=INF;
	dist[v0][0]=0,q.push((heap){v0,dist[v0][0],0});
	while(!q.empty())
	{
		heap now=q.top();q.pop();
		if(vst[now.u][now.cnt])continue;
		vst[now.u][now.cnt]=1;
		vector<node>::iterator it;
		for(it=a[now.u].begin();it!=a[now.u].end();++it)
		{
			if((!vst[it->to][now.cnt])&&dist[now.u][now.cnt]+it->val<dist[it->to][now.cnt])
			{
				dist[it->to][now.cnt]=dist[now.u][now.cnt]+it->val;
				q.push((heap){it->to,dist[it->to][now.cnt],now.cnt});
			}
			if(now.cnt+1<=K&&(!vst[it->to][now.cnt+1])&&dist[it->to][now.cnt+1]>dist[now.u][now.cnt])
			{
				dist[it->to][now.cnt+1]=dist[now.u][now.cnt];
				q.push((heap){it->to,dist[it->to][now.cnt+1],now.cnt+1});
			}
		}
	}
}
int main()
{
	N=GetInt(),M=GetInt(),K=GetInt(),S=GetInt(),T=GetInt();
	for(ri i=1;i<=M;i++)
	{
		int u=GetInt(),v=GetInt(),w=GetInt();
		a[u].push_back((node){v,w});
		a[v].push_back((node){u,w});
	}
	Dijsktra(S);
	for(ri i=0;i<=K;i++)
		Ans=min(Ans,dist[T][i]);
	printf("%d\n",Ans);
	return 0;
}


