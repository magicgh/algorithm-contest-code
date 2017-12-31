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
const ll INF=1e18;
const int MAXN=100005;
const int MAXM=200005;
struct Path{int x,y;ll z;}; 
int N,M,tot;
ll K,Max,Min[MAXN],Ans[MAXM];
int prt[MAXN],Size[MAXN];
Path Edge[MAXM];
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline const ll getll()
{
	ll num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline bool cmp(const Path &a,const Path &b){return a.z>b.z;}
inline int getfa(int u)
{
	if(prt[u]==u)return u;
	else return prt[u]=getfa(prt[u]);
}
void Kruskal()
{
	sort(Edge+1,Edge+M+1,cmp);
	for(ri i=1;i<=N;i++)prt[i]=i,Size[i]=1,Min[i]=INF;
	for(ri i=1;i<=M;i++)
	{
		int f1=getfa(Edge[i].x),f2=getfa(Edge[i].y);
		if(f1!=f2)
		{
			if(Edge[i].z<=Min[f1]&&Edge[i].z<=Min[f2])
				Ans[i]+=Size[f1]*Size[f2];
			prt[f2]=f1;
			Size[f1]+=Size[f2];
			Min[f1]=min(Min[f1],min(Min[f2],Edge[i].z));
			if(++tot==N-1)break;
		}
	}
}
void ST1()
{
	for(ri i=1;i<=M;i++)
	{
		int u=getint(),v=getint();
		ll w=getll();
		if(u!=v)Max=max(Max,w);
	}
	printf("%lld\n",Max);
}
void ST2()
{
	for(ri i=1;i<=M;i++)
	{
		int u=getint(),v=getint();
		ll w=getll();
		Edge[i]=(Path){u,v,w};
	}
	Kruskal();
	for(ri i=1;i<=M;i++)
	{
		if(K-Ans[i]<=0){printf("%lld\n",Edge[i].z);return;}
		else K-=Ans[i];
	}
}
int main()
{
	N=getint(),M=getint(),K=getll();
	if(K==1)ST1();
	else ST2();
	return 0;
}

