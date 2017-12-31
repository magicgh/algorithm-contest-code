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
const int MAXN=55;
const int INF=0x7fffffff;
int n,m;
ll N,Ans=INF,Max,h[MAXN][MAXN],f[MAXN][MAXN][5005];
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline const ll getll()
{
	ll num=0;int bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
int main()
{
	n=getint(),m=getint(),N=n+m-1;
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=m;j++)
			h[i][j]=getll(),Max=max(Max,h[i][j]); 
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=m;j++)
			for(ri sum=0;sum<=N*Max;sum++)
				f[i][j][sum]=INF;
	f[1][1][h[1][1]]=(N-1)*h[1][1]*h[1][1];
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=m;j++)
			for(ri sum=0;sum<=N*Max;sum++)
			{
				if(f[i][j][sum]==INF)continue;
				f[i+1][j][sum+h[i+1][j]]=min(f[i+1][j][sum+h[i+1][j]],f[i][j][sum]+(N-1)*h[i+1][j]*h[i+1][j]-2*sum*h[i+1][j]);
				f[i][j+1][sum+h[i][j+1]]=min(f[i][j+1][sum+h[i][j+1]],f[i][j][sum]+(N-1)*h[i][j+1]*h[i][j+1]-2*sum*h[i][j+1]);
			}
	for(ri sum=0;sum<=(n+m-1)*Max;sum++) 
		Ans=min(Ans,f[n][m][sum]);
	printf("%lld\n",Ans);
	return 0;
}


