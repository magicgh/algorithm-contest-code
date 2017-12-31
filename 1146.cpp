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
const int MAXN=5005;
vector<int>a[MAXN];
int d,n,Huaji[MAXN],prt[MAXN],f[MAXN][MAXN],g[MAXN];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void DFS(int u)
{
	for(int i=Huaji[u];i<=Huaji[u]+d&&i<=5000;i++)
		f[u][i]=0;
	vector<int>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(prt[u]==*it)continue;
		prt[*it]=u,DFS(*it);
		for(int i=Huaji[u];i<=Huaji[u]+d&&i<=5000;i++)
			f[u][i]+=min(f[*it][i],g[*it]);
	}
	for(int i=Huaji[u];i<=Huaji[u]+d&&i<=5000;i++)
			g[u]=min(f[u][i]+1,g[u]);
}
int main()
{
	d=getint(),n=getint();
	memset(f,0x3f,sizeof(f));
	memset(g,0x3f,sizeof(g));
	for(ri i=1;i<=n;i++)Huaji[i]=getint();
	for(ri i=1;i<n;i++)
	{
		int u=getint(),v=getint();
		a[u].push_back(v);
		a[v].push_back(u);
	}
	DFS(1);
	printf("%d",g[1]);
	return 0;
}

