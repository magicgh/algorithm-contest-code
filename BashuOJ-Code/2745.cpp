#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<climits>
#define ri register int
#define ll long long
using namespace std;
const int MAXN=100005;
const ll INF=LLONG_MAX/2;
struct node{int to;ll val;};
vector<node>a[MAXN];
ll c[MAXN],f[MAXN],Size[MAXN],Min=INF;
int n,prt[MAXN];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline ll getll()
{
	ll num=0;int bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void DFSx1(int u)
{
	Size[u]=c[u];
	vector<node>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(it->to==prt[u])continue;
		prt[it->to]=u,DFSx1(it->to);
		Size[u]+=Size[it->to];
		f[1]+=Size[it->to]*it->val;	
	}
}
void DFSx2(int u)
{
	vector<node>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(it->to==prt[u])continue;
		f[it->to]=f[u]-Size[it->to]*it->val+(Size[1]-Size[it->to])*it->val;
		DFSx2(it->to);
	}
}
int main()
{
	n=getint();
	for(ri i=1;i<=n;i++)c[i]=getll();
	for(ri i=1;i<n;i++)
	{
		int u=getint(),v=getint();ll w=getll();
		a[u].push_back((node){v,w});
		a[v].push_back((node){u,w});
	}
	DFSx1(1),DFSx2(1);
	for(ri i=1;i<=n;i++)Min=min(Min,f[i]);
	printf("%lld",Min);
	return 0;
}
