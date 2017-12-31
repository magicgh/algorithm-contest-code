#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<list>
using namespace std;
int n,m,dist[505]={0},prt[505]={0};
bool vst[505]={0};
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
list<path>a[505];
priority_queue<node>q;
inline void DFS(int u)
{
	if(prt[u]==u)
	{
		cout<<prt[u]<<' ';
		return;
	}
	DFS(prt[u]);
	cout<<u<<' ';
}
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
int main()
{
cin>>n>>m;
int x,y,z,s,t;
for(int i=1;i<=m;i++)
{
	cin>>x>>y>>z;
	a[x].push_back((path){y,z});
}
cin>>s>>t;
Dijkstra(s);
cout<<dist[t]<<endl;
DFS(t);
return 0;
}
