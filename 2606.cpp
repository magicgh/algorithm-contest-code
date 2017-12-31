#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<list>
#include<climits>
using namespace std;
int k,n,m,dist[1005]={0},prt[1005]={0},dist1[1005]={0};
bool vst[1005]={0};
struct path
{
	int to,value;
};
struct node
{
	int value,key;
};
bool operator <(node a,node b)
{
	return a.value>b.value;
}
list<path>a[1005];
list<path>b[1005];
priority_queue<node>q;
inline void Dijkstra(int v0)
{
	list<path>::iterator i;
	for(int i=1;i<=n;i++)dist[i]=0x7fffffff;
	dist[v0]=0;prt[v0]=v0;
	q.push((node){dist[v0],v0});
	while(!q.empty())
	{
		node now=q.top();
		q.pop();
		if(!vst[now.key])
		{
		vst[now.key]=1;
		for(i=a[now.key].begin();i!=a[now.key].end();++i)
		{
			if(!vst[i->to]&&dist[i->to]>dist[now.key]+i->value)
			{
				dist[i->to]=dist[now.key]+i->value;
				q.push((node){dist[i->to],i->to});
				prt[i->to]=now.key;
			}
		}
		}
	}
}
inline void Dijkstra_1(int v0)
{
	list<path>::iterator i;
	for(int i=1;i<=n;i++)dist1[i]=0x7fffffff;
	dist1[v0]=0;prt[v0]=v0;
	q.push((node){dist1[v0],v0});
	while(!q.empty())
	{
		node now=q.top();
		q.pop();
		if(!vst[now.key])
		{
		vst[now.key]=1;
		for(i=b[now.key].begin();i!=b[now.key].end();++i)
		{
			if(!vst[i->to]&&dist1[i->to]>dist1[now.key]+i->value)
			{
				dist1[i->to]=dist1[now.key]+i->value;
				q.push((node){dist1[i->to],i->to});
				prt[i->to]=now.key;
			}
		}
		}
	}
}
int main()
{
cin>>n>>m>>k;
int x,y,z,s,t,Max=INT_MIN;
for(int i=1;i<=m;i++)
{
	cin>>x>>y>>z;
	a[x].push_back((path){y,z});
	b[y].push_back((path){x,z});
}
Dijkstra(k);
memset(vst,0,sizeof(vst));
memset(prt,0,sizeof(prt));
Dijkstra_1(k);
for(int i=1;i<=n;i++)Max=max(Max,dist[i]+dist1[i]);
cout<<Max;
return 0;
}