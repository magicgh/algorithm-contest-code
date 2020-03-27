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
const int MAXN=200005;
struct node{int x,y,w;};
vector<node>Edge;
vector<int>G[MAXN];
int p,p1[MAXN],p2[MAXN];
int n,k,Maxlen,Diam;
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline void AddEdge(int u,int v,int w)
{
	Edge.push_back((node){u,v,w});
	Edge.push_back((node){v,u,w});
	G[u].push_back(Edge.size()-2);
	G[v].push_back(Edge.size()-1);
}
int Tree_DP(int now,int fa)
{
	int d1=0,d2=0;
	for(int i=0;i<G[now].size();i++)
	{
		node &next=Edge[G[now][i]];
		if(next.y==fa)continue;
		int delta=next.w+Tree_DP(next.y,next.x);
		if(delta>d1)d2=d1,d1=delta,p2[now]=p1[now],p1[now]=G[now][i];
		else if(delta>d2)d2=delta,p2[now]=G[now][i];
	}
	if(Diam<d1+d2)Diam=d1+d2,p=now;
	return d1;
}
int main()
{
	n=getint(),k=getint();
	AddEdge(0,0,0);
	for(ri i=1;i<n;i++)
	{
		int u=getint(),v=getint();
		AddEdge(u,v,1);
	}
	Tree_DP(1,0);Maxlen=((n-1)<<1)-Diam+1;
	if(k==2)
	{
		Diam=0;
		for(int i=p1[p];i;i=p1[Edge[i].y])Edge[i].w=Edge[i^1].w=-1;
		for(int i=p2[p];i;i=p1[Edge[i].y])Edge[i].w=Edge[i^1].w=-1;
		//最长链和次长链的区别仅在一条边的不同 
		Tree_DP(1,0);
		Maxlen=Maxlen-Diam+1;
	}
	printf("%d\n",Maxlen);	
	return 0;
}
