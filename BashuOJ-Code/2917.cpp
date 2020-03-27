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
using namespace std;
const int MAXN=1005;
int n,m,r,c,ans=-0x7fffffff,a[MAXN][MAXN];
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
	n=getint(),m=getint(),r=getint(),c=getint();
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=m;j++)
		{
			int x=getint();
			a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+x;
		}
	for(ri i=r;i<=n;i++)
		for(ri j=c;j<=m;j++)
		{
			int tmp=a[i][j]-a[i-r][j]-a[i][j-c]+a[i-r][j-c];
			ans=max(ans,tmp);
		}
		printf("%d",ans);
	return 0;	
}

