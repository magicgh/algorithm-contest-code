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
const int MAXN=2005;
struct node{int to,val;};
vector<node>a[MAXN];
ll f[MAXN][MAXN];
int n,k,Size[MAXN];
inline int min(const int &a,const int &b){return a<b?a:b;}
inline int max(const int &a,const int &b){return a>b?a:b;}
inline ll max(const ll &a,const ll &b){return a>b?a:b;}
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void DFS(int u,int fa)
{
	Size[u]=1;
	vector<node>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(it->to==fa)continue;
		DFS(it->to,u);
		Size[u]+=Size[it->to];
	}
}
void Tree_DP(int u,int fa)
{
	f[u][0]=f[u][1]=0;
	vector<node>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(it->to==fa)continue;
		Tree_DP(it->to,u);
		for(ri j=min(k,Size[u]);j>=0;j--)
			for(ri t=max(0,j-Size[u]);t<=min(Size[it->to],j);t++)
				f[u][j]=max(f[u][j],f[u][j-t]+f[it->to][t]+(ll)it->val*(ll)((k-t)*t+(n-k-Size[it->to]+t)*(Size[it->to]-t)));
	}
}
int main()
{
	n=getint(),k=getint();
	memset(f,-0x3f,sizeof(f));
	for(ri i=1;i<n;i++)
	{
		int u=getint(),v=getint(),w=getint();
		a[u].push_back((node){v,w});
		a[v].push_back((node){u,w});
	}
	DFS(1,0);
	Tree_DP(1,0);
	printf("%lld",f[1][k]);
	return 0;
}
