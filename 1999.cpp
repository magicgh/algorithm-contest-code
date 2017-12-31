#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<queue>
#include<list>
#include<climits>
using namespace std;
struct node
{
	double value;
	int key;
};
bool operator < (node a,node b)
{
	return a.value>b.value;
}
priority_queue<node>q;
struct fare
{
int to;
double cost;
};
list<fare>a[2005];
int n,m;
double dist[2005];
int prt[2005],vst[2005];
inline void Dijkstra(int v0)
{
	list<fare>::iterator i;
	for(int i=1;i<=n;i++)dist[i]=INT_MAX;
	dist[v0]=100,prt[v0]=v0;
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
				if(!vst[i->to]&&double(dist[now.key]/(1-i->cost))<dist[i->to])
				{
					dist[i->to]=double(dist[now.key]/(1-i->cost));
					q.push((node){dist[i->to],i->to});
					prt[i->to]=now.key;
				}
			}
		}
	}
	return;
}
inline int GetInt()
{
	int num=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num;
}
int main(){
	memset(dist,0,sizeof(dist));
	memset(prt,0,sizeof(prt));
	memset(vst,0,sizeof(vst));
	n=GetInt();
	m=GetInt();
	int x,y,z;
	for(int i=1;i<=m;i++)
	{
		x=GetInt();
		y=GetInt();
		z=GetInt();
		a[x].push_back((fare){y,z/100.00000000});
		a[y].push_back((fare){x,z/100.00000000});
	}
	int s,t;
	s=GetInt();
	t=GetInt();
	Dijkstra(s);
	printf("%.8f",dist[t]);
	return 0;
}
