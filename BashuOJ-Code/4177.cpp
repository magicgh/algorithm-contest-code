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
const int MAXN=10005;
const int Mod=10007;
int C[10005][105];
int n,m,a[MAXN],ans=1,sum;
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void Init()
{
	C[0][0]=1;
	for(ri i=1;i<=10000;i++)
	{
		C[i][0]=C[i][i]=1;
		for(ri j=1;j<=min(i-1,100);j++)C[i][j]=(C[i-1][j]+C[i-1][j-1])%Mod;
	}
}
int main()
{
	Init();
	n=getint(),m=getint();
	for(ri i=1;i<=m;i++)
	{
		int x=getint();
		ans=(ans%Mod*C[n-sum][x]%Mod)%Mod;
		sum+=x;
	}
	printf("%d",ans);
	return 0;
}

