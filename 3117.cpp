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
struct node{int to,val,gold;};
vector<node>a[MAXN];
int prt[MAXN],dist[MAXN],cost[MAXN],gold[MAXN];
bool ext[MAXN];
int n,m1,m2;
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline int getfa(int u)
{
	if(prt[u]==u)return u;
	return prt[u]=getfa(prt[u]);
}
void SPFA(int v0)
{
	queue<int>q;
	for(ri i=1;i<=n;i++)dist[i]=INF;
	q.push(v0),dist[v0]=0,cost[v0]=gold[v0],ext[v0]=1;
	while(!q.empty())
	{
		int now=q.front();q.pop(),ext[now]=0;
		vector<node>::iterator it;
		for(it=a[now].begin();it!=a[now].end();++it)
		{
			if((dist[now]+it->val<dist[it->to])||(dist[now]+it->val==dist[it->to]&&cost[it->to]<cost[now]+gold[it->to]+it->gold))
			{
				dist[it->to]=dist[now]+it->val;
				cost[it->to]=cost[now]+gold[it->to]+it->gold;
				if(!ext[it->to])
				{
					q.push(it->to);
					ext[it->to]=1;
				}
			}
		}
	}
}
int main()
{
	n=getint(),m1=getint(),m2=getint();
	for(ri i=1;i<=n;i++)prt[i]=i;
	for(ri i=1;i<=m2;i++)
	{
		int f1=getfa(getint()),f2=getfa(getint()),w=getint();
		if(f1!=f2)
		{
			prt[f2]=f1;
			gold[f1]+=gold[f2];
		}
		gold[f1]+=w;
	}
	for(ri i=1;i<=m1;i++)
	{
		int f1=getfa(getint()),f2=getfa(getint()),w=getint(),t=getint();
		if(f1!=f2)
			a[f1].push_back((node){f2,t,w});
	}
	SPFA(getfa(1));
	printf("%d %d\n",dist[getfa(n)],cost[getfa(n)]);
	return 0;
}
