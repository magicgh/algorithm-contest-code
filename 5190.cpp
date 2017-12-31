#include<iostream>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<queue>
#include<stack>
#define ri register int
#define ll long long
using namespace std;
const int MAXN=105;
const int MAXQ=100005;
const int INF=0x7fffffff/2;
const int Log=18;
int N,M,C,T;
int p[MAXN],c[MAXN],g[MAXN][MAXN][20],f[MAXN][2],w[MAXN][MAXN],dp[MAXN][MAXN*MAXN];
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(bj==-1||c=='-')?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline int Binary(int s,int q,int d)
{
	int l=0,r=q;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(dp[s][mid]>=d)r=mid-1;
		else l=mid+1;
	}
	return l;
}
int main()
{
	N=GetInt(),M=GetInt(),C=GetInt(),T=GetInt();
	for(ri i=1;i<=N;i++)
		p[i]=GetInt(),c[i]=min(C,GetInt());
	for(ri k=0;k<=Log;k++)
		for(ri i=1;i<=N;i++)
			for(ri j=1;j<=N;j++)
				if(i!=j)g[i][j][k]=-INF;
	for(ri i=1;i<=M;i++)
	{
		int u=GetInt(),v=GetInt(),w=GetInt();
		g[u][v][0]=max(w,g[u][v][0]);
	}
	for(ri k=1;k<=Log;k++)
		for(ri p=1;p<=N;p++)
			for(ri i=1;i<=N;i++)
				for(ri j=1;j<=N;j++)
						g[i][j][k]=max(g[i][j][k],g[i][p][k-1]+g[p][j][k-1]);
	for(ri i=1;i<=N;i++)
	{
		for(ri j=1;j<=N;j++)
			if(i!=j)f[j][0]=f[j][1]=-INF;
			else f[j][0]=f[j][1]=0;
		int now=0;
		for(ri k=Log;k>=0;k--)
		{
			if(!(c[i]&(1<<k)))continue;
			for(ri j=1;j<=N;j++)
				for(ri p=1;p<=N;p++)
					f[j][now^1]=max(f[j][now^1],f[p][now]+g[p][j][k]);
			now^=1;
		}
		for(ri j=1;j<=N;j++)w[i][j]=f[j][now];
	}
	for(ri k=0;k<=N*N;k++)
		for(ri i=1;i<=N;i++)
			if(k>=p[i])
				for(ri j=1;j<=N;j++)
					dp[i][k]=max(dp[i][k],dp[j][k-p[i]]+w[i][j]);
	for(ri i=1;i<=T;i++)
	{
		int s=GetInt(),q=GetInt(),d=GetInt();
		if(dp[s][q]<d)printf("-1\n");
		else printf("%d\n",q-Binary(s,q,d));
	}
	return 0;
}
