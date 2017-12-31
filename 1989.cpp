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
const int MAXN=255;
const int INF=0x7fffffff/2;
int f[MAXN][MAXN],Count[MAXN][MAXN];
int n,m,Ans,Max=-INF;
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
		for(ri j=1;j<=n;j++)
			if(i!=j)f[i][j]=INF;
	for(ri i=1;i<=m;i++)
	{
		int u=getint(),v=getint();
		f[u][v]=f[v][u]=1;
	}
	for(ri k=1;k<=n;k++)
		for(ri i=1;i<=n;i++)
			for(ri j=1;j<=n;j++)
				if(i!=j&&f[i][k]!=INF&&f[k][j]!=INF)f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=n;j++)
			for(ri k=1;k<=n;k++)
				if(f[i][k]==1&&f[i][k]+f[k][j]==f[i][j])Count[i][j]++;
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=n;j++)
		{
			Ans=0;
			for(ri k=1;k<=n;k++)
				if(f[i][k]+f[k][j]==f[i][j])Ans+=Count[k][j];
			Max=max(Max,Ans);
		}
	printf("%d\n",Max);
	return 0;
}

