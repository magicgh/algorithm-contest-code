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
const int MOD=1000000009;
int n,m;
int f[25][25],g[1000005];
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
	if(n>=21){printf("0\n");return 0;}
	for(ri i=1;i<=n;i++)f[i][1]=f[i][i]=1;
	for(ri i=2;i<=n;i++)
		for(ri j=2;j<i;j++)f[i][j]=f[i-1][j-1]+f[i-1][j];
	g[0]=1;
	int top=m-(1<<(n-1));//(1<<(n-1))为杨辉三角的最小值，大于最小值减少DP范围 
	for(ri i=1;i<=n;i++)
		for(ri j=f[n][i];j<=top;j++)g[j]=(g[j-f[n][i]]+g[j])%MOD;
	printf("%d",g[top]);
	return 0;
}

