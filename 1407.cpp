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
const int MAXN=105;
const int INF=0x7fffffff/2;
int n,m,k;
int map[MAXN][MAXN],s1[MAXN],s2[MAXN],g[MAXN][MAXN][MAXN]; 
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
void Solve()
{
	for(ri i=1;i<=n;i++)
		s1[i]=s1[i-1]+map[i][1],s2[i]=s2[i-1]+map[i][2];
	for(ri cnt=1;cnt<=k;cnt++)
		for(ri i=1;i<=n;i++)
			for(ri j=1;j<=n;j++)
			{
				g[cnt][i][j]=max(g[cnt][i-1][j],g[cnt][i][j-1]);
				for(ri x=0;x<i;x++)
					g[cnt][i][j]=max(g[cnt][i][j],g[cnt-1][x][j]+s1[i]-s1[x]);
				for(ri x=0;x<j;x++)
					g[cnt][i][j]=max(g[cnt][i][j],g[cnt-1][i][x]+s2[j]-s2[x]);
				if(i==j)
					for(ri x=0;x<i;x++)
						g[cnt][i][j]=max(g[cnt][i][j],g[cnt-1][x][x]+s1[i]-s1[x]+s2[j]-s2[x]);	
			}
	printf("%d\n",g[k][n][n]);
}
int main()
{
	n=getint(),m=getint(),k=getint();
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=m;j++)
			map[i][j]=getint();
	Solve();
	return 0;
}


