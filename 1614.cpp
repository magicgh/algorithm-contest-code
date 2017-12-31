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
const int MAXN=300005;
const ll INF=1e18;
struct node{int to;ll val;};
int n;
ll f1[MAXN],f2[MAXN],g1[MAXN],g2[MAXN];
ll Ansf[MAXN],Ansg[MAXN];
bool Leaf[MAXN];
vector<node>a[MAXN];
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
void Tree_DP(int u,int fa)
{
	g1[u]=g2[u]=INF;
	vector<node>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(it->to==fa)continue;
		Tree_DP(it->to,u);
		if(g1[it->to]+it->val>=f1[u])
		{
			f2[u]=f1[u];
			f1[u]=g1[it->to]+it->val;
		}
		else if(g1[it->to]+it->val>f2[u])
			f2[u]=g1[it->to]+it->val;
		if(f1[it->to]+it->val<=g1[u])
		{
			g2[u]=g1[u];
			g1[u]=f1[it->to]+it->val;
		}
		else if(f1[it->to]+it->val<g2[u])
			g2[u]=f1[it->to]+it->val;
	}
	if(g1[u]==INF)
		g1[u]=g2[u]=0,Leaf[u]=1;
}
void DFS(int u,int fa)
{
	Ansf[u]=f1[u],Ansg[u]=g1[u];
	vector<node>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(it->to==fa)continue;
		ll fx=f1[u],gx=g1[u],fy=f1[it->to],gy=g1[it->to],fy2=f2[it->to],gy2=g2[it->to];
		if(g1[it->to]+it->val==f1[u])f1[u]=f2[u];
		if(f1[it->to]+it->val==g1[u])g1[u]=g2[u];
		if(Leaf[it->to])g1[it->to]=g2[it->to]=INF;
		if(f1[u]+it->val<=g1[it->to])
		{
			g2[it->to]=g1[it->to];
			g1[it->to]=f1[u]+it->val;
		}
		else if(f1[u]+it->val<g2[it->to])
			g2[it->to]=f1[u]+it->val;
		if(g1[u]+it->val>=f1[it->to])
		{
			f2[it->to]=f1[it->to];
			f1[it->to]=g1[u]+it->val;
		}
		else if(g1[u]+it->val>f2[it->to])
			f2[it->to]=g1[u]+it->val;
		DFS(it->to,u);
		f1[u]=fx,g1[u]=gx,f1[it->to]=fy,g1[it->to]=gy,f2[it->to]=fy2,g2[it->to]=gy2;
	}
}
int main()
{
	n=getint();
	for(ri i=1;i<n;i++)
	{
		int u=getint(),v=getint();ll w=getint();
		a[u].push_back((node){v,w});
		a[v].push_back((node){u,w});
	}
	Tree_DP(1,0);
	DFS(1,0);
	for(int i=1;i<=n;i++)
		printf("%lld\n",Ansf[i]);
	return 0;
}


