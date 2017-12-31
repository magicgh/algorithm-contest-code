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
struct monkey{int b,d;}a[105];
int n,m,d,f[105][105],ans;
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
	n=getint(),d=getint(),m=getint();
	for(ri i=1;i<=n;i++)a[i]=(monkey){getint(),getint()};
	ans=f[1][0]=a[1].b;
	for(ri i=2;i<=n;i++)
		for(ri j=0;j<=min(m,i);j++)
			for(ri k=1;k<i;k++)
			{
				if(f[k][j-1]&&a[i].d-a[k].d<=d)f[i][j]=max(f[i][j],f[k][j-1]+a[i].b);
				ans=max(ans,f[i][j]);
			}
	printf("%d\n",ans);
	return 0;
}
