#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<deque>
#include<stack>
#include<vector>
#define ri register int
#define ll long long
using namespace std;
const int MAXN=200005;
const int MAXM=1000005;
const int INF=0x7fffffff/2;
struct node{int to,val;};
struct path{int x,y,z;};
vector<node>a[MAXN];
vector<int>b[MAXN];
stack<int>s;
path Edge[MAXM];
int n,m,cnt,part,dist[MAXN];
int dfn[MAXN],low[MAXN],Belong[MAXN];
bool ext[MAXN],Ins[MAXN];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void SPFA(int v0)
{
	deque<int>q;
	for(ri i=1;i<=n;i++)dist[i]=INF,ext[i]=0;
	q.push_back(v0),dist[v0]=0,ext[v0]=1;
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
}
void Tarjan(int u)
{
	dfn[u]=low[u]=++cnt;
	s.push(u);Ins[u]=1;
	vector<int>::iterator it;
	for(it=b[u].begin();it!=b[u].end();++it)
	{
		if(!dfn[*it])
		{
			Tarjan(*it);
			low[u]=min(low[u],low[*it]);
		}
		else if(Ins[u])low[u]=min(low[u],dfn[*it]);
	}
	int t;
	if(dfn[u]==low[u])
	{
		part++;
		do
		{
			t=s.top();s.pop();Ins[t]=0;
			Belong[t]=part;
		}while(t!=u);
	}
}
int main()
{
	n=getint(),m=getint();
	for(ri i=1;i<=m;i++)
	{
		int x=getint(),y=getint(),z=getint();
		Edge[i]=(path){x,y,z};
		b[x].push_back(y);
	}
	for(ri i=1;i<=n;i++)if(!dfn[i])Tarjan(i);
	for(ri i=1;i<=m;i++)
	{	
		if(Belong[Edge[i].x]==Belong[Edge[i].y])
			a[Edge[i].x].push_back((node){Edge[i].y,0});
		else a[Edge[i].x].push_back((node){Edge[i].y,Edge[i].z});
	}
	SPFA(1);
	printf("%d\n",dist[n]);
	return 0;
}