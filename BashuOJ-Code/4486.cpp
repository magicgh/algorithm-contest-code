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
const int MAXN=110005;
const int INF=0x7fffffff/2;
struct node{int to,val;};
vector<node>a[MAXN];
struct heap
{
	int u,dist;
	bool operator <(const heap &rhs)
	const{return dist>rhs.dist;}
};
int n,T,delta,Max,num;
int dist[MAXN],vst[MAXN];
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
void Dijkstra(int v0)
{
	priority_queue<heap>q;
	for(ri i=1;i<=Max;i++)dist[i]=INF;
	dist[v0]=0;q.push((heap){v0,dist[v0]});
	while(!q.empty())
	{
		heap now=q.top();q.pop();
		if(vst[now.u])continue;
		vst[now.u]=1;
		vector<node>::iterator it;
		for(it=a[now.u].begin();it!=a[now.u].end();++it)
		{
			if(dist[now.u]+it->val<dist[it->to]&&(!vst[it->to]))
			{
				dist[it->to]=dist[now.u]+it->val;
				q.push((heap){it->to,dist[it->to]});
			}
		}
	}
}
void BuildGraph()
{
	T=n+1,Max=0;
	num=getint();
	if(num<0)
	{
		a[1].push_back((node){2,0});
		delta=-num;
		//第一个为负数,强行转为0 
	}
	else a[1].push_back((node){num+2,0});
	Max=max(Max,num+2);
	for(ri i=2;i<=n;i++)
	{
		num=getint();
		if(num>=0)a[i].push_back((node){num+i+1,0});
		Max=max(Max,num+i+1);
		a[i].push_back((node){i+1,1});
		a[i+1].push_back((node){i,1});
	}
	for(ri i=Max;i>T;i--)
		a[i].push_back((node){i-1,1});
}
int main()
{
	n=getint();
	BuildGraph();
	Dijkstra(1);
	printf("%d\n",dist[T]+delta);
	return 0;
}


