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
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
int n,k,f[10001][1001];	
int main()
{
	n=getint(),k=getint();
	f[0][0]=1;
	for(ri i=1;i<=k;i++)
	for(ri j=i;j<=n;j++)//以划分为阶段 
		f[j][i]=(f[j-1][i-1]+f[j-i][i])%10003;
	printf("%d",f[n][k]);
	return 0;
}

