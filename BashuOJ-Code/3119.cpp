#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define ri register int
#define ll long long
using namespace std;
int n,m;
ll ans,a[205][205],f[205][505][205],g[205][505][205],sum[205][205];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline ll getll()
{
	ll num=0;int bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
int main()
{
	n=getint(),m=getint();
	for(ri i=1;i<=n;i++)
	for(ri j=1;j<=n-i+1;j++)a[i+j-1][i]=getll();
	memset(f,-1,sizeof(f));memset(g,-1,sizeof(g));
	for(ri i=1;i<=n;i++)g[i][0][0]=f[i][0][0]=0,f[i][1][1]=a[i][1];
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=i;j++)sum[i][j]=sum[i][j-1]+a[i][j];
	for(ri i=1;i<=n;i++)
	for(ri j=0;j<=m;j++)
	for(ri k=min(i,j);k>=0;k--)//这里用倒推 
	{
		if(!k)f[i][j][0]=g[i-1][j][0];//没敲
		if(g[i-1][j-k][k-1]!=-1)
			f[i][j][k]=g[i-1][j-k][k-1]+sum[i][k];
		g[i][j][k]=max(g[i][j][k+1],f[i][j][k]);
		if(j==m)ans=max(f[i][j][k],ans);//敲完了 
	}
	printf("%lld",ans);
	return 0;
}