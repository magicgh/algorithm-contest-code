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
const int INF=0x7fffffff/2;
int map[MAXN][MAXN],s[MAXN][MAXN],tmp[MAXN][MAXN];
int Max1[MAXN],Min1[MAXN],Max2[MAXN],Min2[MAXN];
int n,m,Ans;
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
int DP()
{
	int Max,Min,ret=-INF;
	Max1[0]=Max2[n+1]=-INF;
	Min1[0]=Min2[n+1]=INF;
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=m;j++)s[i][j]=s[i-1][j]+map[i][j];
	for(ri k=1;k<=n;k++)
	{
		Max1[k]=-INF,Min1[k]=INF;
		for(ri i=1;i<=k;i++)
		{
			Max=-INF,Min=INF;
			for(ri j=1;j<=m;j++)
			{
				Max=max(Max,0)+s[k][j]-s[i-1][j];
				Min=min(Min,0)+s[k][j]-s[i-1][j];
				Max1[k]=max(Max1[k],Max);
				Min1[k]=min(Min1[k],Min);
			}
		}
		Max1[k]=max(Max1[k],Max1[k-1]);
		Min1[k]=min(Min1[k],Min1[k-1]);
	}
	for(ri k=n;k>1;k--)
	{
		Max2[k]=-INF,Min2[k]=INF;
		for(ri i=n;i>=k;i--)
		{
			Max=-INF,Min=INF;
			for(ri j=1;j<=m;j++)
			{
				Max=max(Max,0)+s[i][j]-s[k-1][j];
				Min=min(Min,0)+s[i][j]-s[k-1][j];
				Max2[k]=max(Max2[k],Max);
				Min2[k]=min(Min2[k],Min);
			}
		}
		Max2[k]=max(Max2[k],Max2[k+1]);
		Min2[k]=min(Min2[k],Min2[k+1]);
		ret=max(ret,max(Max1[k-1]*Max2[k],Min1[k-1]*Min2[k]));
	}
	return ret;
}
void Solve()
{
	Ans=DP();
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=m;j++)
			tmp[j][i]=map[i][j];
	swap(n,m);
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=m;j++)
			map[i][j]=tmp[i][j];
	Ans=max(Ans,DP());
	printf("%d\n",Ans);
}
int main()
{
	n=getint(),m=getint();
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=m;j++)
			map[i][j]=getint();
	Solve();
	return 0;
}


