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
const int MAXN=305;
const ll INF=1e18;
struct node{int to;ll val;};
int n,T;
ll Ans,w[MAXN],t[MAXN],f[MAXN][MAXN][3],g[MAXN][3];
vector<node>a[MAXN];
inline const int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline const ll GetLL()
{
	ll num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
void Tree_DP(int u,int fa)
{
	for(ri i=0;i<=T;i++)f[u][i][0]=f[u][i][1]=f[u][i][2]=-INF;
	if(t[u]<=T)f[u][t[u]][0]=f[u][t[u]][1]=w[u];
	vector<node>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(it->to==fa)continue;
		Tree_DP(it->to,u);
		if(t[u]<=T)
		{
			memcpy(g,f[u],sizeof(f[u]));
			for(ri i=T;i>=t[u];i--)
				for(ri j=max(t[it->to],it->val);j<=i;j++)
				{
					f[u][i][2]=max(f[u][i][2],g[i-j][1]+f[it->to][j-it->val][1]);
					f[u][i][1]=max(f[u][i][1],g[i-j][0]+f[it->to][j-it->val][1]);
					if(j>=(2*it->val))
					{
						f[u][i][2]=max(f[u][i][2],g[i-j][0]+f[it->to][j-(2*it->val)][2]);
						f[u][i][2]=max(f[u][i][2],g[i-j][2]+f[it->to][j-(2*it->val)][0]);
						f[u][i][1]=max(f[u][i][1],g[i-j][1]+f[it->to][j-(2*it->val)][0]);
						f[u][i][0]=max(f[u][i][0],g[i-j][0]+f[it->to][j-(2*it->val)][0]);
					}
				}
		}
	}
	for(ri i=t[u];i<=T;i++)
		Ans=max(Ans,max(f[u][i][0],max(f[u][i][1],f[u][i][2])));
}
int main()
{
	n=GetInt(),T=GetInt();
	for(ri i=1;i<=n;i++)w[i]=GetLL();
	for(ri i=1;i<=n;i++)t[i]=GetLL();
	for(ri i=1;i<n;i++)
	{
		int u=GetInt(),v=GetInt();
		ll w=GetLL();
		a[u].push_back((node){v,w});
		a[v].push_back((node){u,w});
	}
	Tree_DP(1,0);
	printf("%lld\n",Ans);
	return 0;
}
