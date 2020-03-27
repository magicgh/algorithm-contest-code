#include<iostream>
#include<cstdio>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<queue>
#include<stack>
#define ri register int
#define ll long long
using namespace std;
const int MAXN=200005;
int n,m,q,Log,ret;
int w[MAXN],dep[MAXN],p[MAXN][20],Point[MAXN];
vector<int>a[MAXN];
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}

void DFS(int u,int fa,int depth)
{
	int x=fa;dep[u]=depth;
	for(ri i=Log;i>=0;i--)
		if(p[x][i]&&w[p[x][i]]<=w[u])x=p[x][i];
	if(w[x]>w[u])p[u][0]=fa;
	else p[u][0]=p[x][0];
	for(ri i=1;i<=Log;i++)
		if(p[u][i-1])p[u][i]=p[p[u][i-1]][i-1];
	vector<int>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(*it==fa)continue;
		DFS(*it,u,depth+1);
	}
}
int main()
{
	m=n=GetInt(),q=GetInt(),Log=log2(n+q);
	for(ri i=1;i<=n;i++)w[i]=GetInt();
	for(ri i=1;i<n;i++)
	{
		int u=GetInt(),v=GetInt();
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for(ri i=1;i<=q;i++)
	{
		int u=GetInt(),v=GetInt(),c=GetInt();
		Point[i]=v,w[++m]=c;
		a[u].push_back(m);
		a[m].push_back(u);
	}
	DFS(1,0,1);
	for(ri i=1;i<=q;i++)
	{
		int u=i+n,v=Point[i];ret=0;
		for(ri j=Log;j>=0;j--)
		{
			if(dep[p[u][j]]>=dep[v])
				ret+=(1<<j),u=p[u][j];
		}
		printf("%d\n",ret);
	}
	return 0;
}