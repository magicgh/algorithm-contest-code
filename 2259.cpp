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
#define ll long long
using namespace std;
const int MAXN=5005;
int n,t,Ans=-0x7fffffff;
int s[MAXN],b[MAXN],f[MAXN][MAXN];
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
	n=getint(),t=getint();
	for(ri i=1;i<=n;i++)s[i]=getint();
	for(ri i=1;i<=n;i++)b[i]=getint();
	for(ri i=1;i<=n;i++)
		for(ri j=0;j<=i;j++)//前i个箭头累计踩中j个的最高分数 
            f[i][j]=(j>0)?max(f[i-1][j]-s[i],f[i-1][j-1]+s[i]+(j%t==0)*b[i]):f[i-1][j]-s[i];
	for(ri i=0;i<=n;i++)Ans=max(Ans,f[n][i]);
	printf("%d",Ans);
	return 0;
}

