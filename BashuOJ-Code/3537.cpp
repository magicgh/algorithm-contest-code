#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define ri register int
#define ll long long
using namespace std;
int n,m,f[105][105],a[105];
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
int main()
{
	n=getint(),m=getint();
	for(ri i=1;i<=n;i++)a[i]=getint();
	f[0][0]=1;
	for(ri i=1;i<=n;i++)
		for(ri j=0;j<=m;j++)
			for(ri k=0;k<=a[i]&&k<=j;k++)
				f[i][j]=(f[i][j]+f[i-1][j-k])%1000007;
	printf("%d\n",f[n][m]%1000007);
	return 0;
}


