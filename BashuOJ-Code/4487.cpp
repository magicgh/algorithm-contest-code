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
const int MAXN=255;
const int MAXM=10005;
const int INF=0x7fffffff/4;
struct node{int to,val;};
struct Query{int s,t;};
struct heap
{
	int u,id,dist;
	bool operator <(const heap &rhs)
	const {return dist>rhs.dist;}
};
vector<node>a[MAXN];
Query q[MAXM];
int n,m,k,Ans[MAXN][MAXN],dist[MAXN][2],City[MAXN],map[MAXN][MAXN];
bool vst[MAXN][2];
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
void Dijsktra(int p)
{
	priority_queue<heap>q;
	for(ri i=1;i<=n;i++)dist[i][0]=dist[i][1]=INF,vst[i][0]=vst[i][1]=0;
	dist[p][0]=0,q.push((heap){p,0,dist[p][0]});
	while(!q.empty())
	{
		heap now=q.top();q.pop();
		if(vst[now.u][now.id])continue;
		vst[now.u][now.id]=1;
		vector<node>::iterator it;
		for(it=a[now.u].begin();it!=a[now.u].end();++it)
		{
			if(City[it->to]>=City[p])//最大变次大
			{
				if(now.id==0&&dist[it->to][1]>dist[now.u][0]+it->val)
				{
					dist[it->to][1]=dist[now.u][0]+it->val;
					q.push((heap){it->to,1,dist[it->to][1]});
				}
			}
			if(City[it->to]<=City[p])
			{
				if(dist[it->to][now.id]>dist[now.u][now.id]+it->val)
				{
					dist[it->to][now.id]=dist[now.u][now.id]+it->val;
					q.push((heap){it->to,now.id,dist[it->to][now.id]});
				}	
			}	
		}
	}
}
int main()
{
	n=getint(),m=getint(),k=getint();
	for(ri i=1;i<=n;i++)City[i]=getint();
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=n;j++)map[i][j]=INF;
	for(ri i=1;i<=m;i++)
	{
		int u=getint(),v=getint(),w=getint();
		if(u==v)continue;
		map[u][v]=map[v][u]=min(map[u][v],w);	
	}
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=n;j++)
			if(map[i][j]!=INF)a[i].push_back((node){j,map[i][j]});
	for(ri i=1;i<=k;i++)
	{
		int u=getint(),v=getint();
		q[i]=(Query){u,v};
	}
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=n;j++)Ans[i][j]=INF;
	for(ri p=1;p<=n;p++)
	{
		Dijsktra(p);
		for(ri i=1;i<=n;i++)
			for(ri j=1;j<=n;j++)
				Ans[i][j]=min(Ans[i][j],min(dist[i][0]+dist[j][1]+City[p],dist[i][1]+dist[j][0]+City[p]));
	}
	for(ri i=1;i<=k;i++)
		printf("%d\n",Ans[q[i].s][q[i].t]); 
	return 0;
}

