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
using namespace std;
int n,k,f[205][205];
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
	n=getint(),k=getint();
	for(ri i=1;i<=k;i++)f[1][i]=1;
	for(ri i=3;i<=n;i+=2)
		for(ri j=2;j<=k;j++)
			for(ri k=1;k<=i-2;k++)f[i][j]=(f[i][j]+f[k][j-1]*f[i-k-1][j-1])%9901;
	printf("%d",(9901+f[n][k]-f[n][k-1])%9901);
	return 0;
}

	