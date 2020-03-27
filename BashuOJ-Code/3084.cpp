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
const int MAXN=55;
const int INF=0x7fffffff/2;
int n,m;
ll f[MAXN][MAXN];
bool g[40][MAXN][MAXN];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
int main()
{
	n=getint(),m=getint();
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=n;j++)f[i][j]=INF;
	for(ri i=1;i<=m;i++)
	{
		int x=getint(),y=getint();
		g[0][x][y]=1,f[x][y]=1;
	}
	for(ri t=1;t<=35;t++)
		for(ri k=1;k<=n;k++)
			for(ri i=1;i<=n;i++)
				for(ri j=1;j<=n;j++)
				{
					g[t][i][j]=(g[t][i][j]||(g[t-1][i][k]&&g[t-1][k][j]));
					if(g[t][i][j])f[i][j]=1; 
				}
	for(ri k=1;k<=n;k++)
			for(ri i=1;i<=n;i++)
				for(ri j=1;j<=n;j++)
					if(f[i][k]!=INF&&f[j][k]!=INF)f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	printf("%lld",f[1][n]);
	return 0;
}

