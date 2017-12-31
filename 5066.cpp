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
const int MAXN=6005;
const ll INF=1e18;
struct Point{int x,y;};
struct node{int to;ll val;};
Point P[MAXN];
ll Ans,dist[MAXN];
int n,m,k,prt[MAXN];
bool vst[MAXN];
vector<node>a[MAXN];
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline ll Sqr(ll x){return x*x;}
inline ll Getdist(int a,int b)
{
	if(a>k||b>k)return Sqr((ll)(P[a].y-P[b].y));
	else return Sqr((ll)(P[a].x-P[b].x))+Sqr((ll)(P[a].y-P[b].y));
}
void Prim()
{
	for(ri i=0;i<=k+2;i++)dist[i]=INF;
	dist[k+1]=0;
	for(ri i=1;i<=k+2;i++)
	{
		int pos=0;
		for(ri j=1;j<=k+2;j++)
			if(!vst[j]&&dist[pos]>dist[j])pos=j;
		vst[pos]=1;
		for(ri j=1;j<=k+2;j++)
		{
			ll w=Getdist(pos,j);
			if(!vst[j]&&dist[j]>w)
			{
				dist[j]=w;
				prt[j]=pos;
			}
		}
	}
}
inline void Build()
{
	for(ri i=1;i<=k+2;i++)
	{
		if(prt[i])
		{
			ll w=Getdist(prt[i],i);
			a[prt[i]].push_back((node){i,w});
			a[i].push_back((node){prt[i],w});
		}
	}
}
void DFS(int u,int fa,ll Max)
{
	if(u==k+2)
	{
		Ans=max(Ans,Max);
		return;
	}
	for(auto &it:a[u])
	{
		if(it.to==fa)continue;
		DFS(it.to,u,max(Max,it.val));
	}
}
int main()
{
	n=getint(),m=getint(),k=getint();
	for(ri i=1;i<=k;i++)
	{
		int x=getint(),y=getint();
		P[i]=(Point){x,y};
	}
	P[k+1]=(Point){0,0},P[k+2]=(Point){0,m};
	Prim();
	Build();
	DFS(k+1,0,0);
	printf("%.8lf\n",sqrt(Ans)/2);
	return 0;
}


