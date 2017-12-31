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
#define C(n,m) C[n][m]
using namespace std;
const ll Mod=998244353ll;
const int MAXN=2005;
int N;
ll d[3],F[MAXN]={1},f[MAXN][MAXN],C[MAXN][MAXN];
inline const int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
void Init()
{
	for(ri i=1;i<=N;i++)
	{
		C[i][0]=C[i][i]=1;
		for(ri j=1;j<i;j++)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%Mod;
	}
}
inline ll DP(ll n,ll m)
{
	if(f[n][m])return f[n][m];
	if(n>=2&&m>=1)f[n][m]=(f[n][m]+DP(n-2,m-1)*C(n,2)%Mod)%Mod;
	if(m>=2)f[n][m]=(f[n][m]+DP(n,m-2)*C(n,1)%Mod*C(m-1,1)%Mod)%Mod;
	if(m>=3)f[n][m]=(f[n][m]+DP(n+2,m-3)*C(m-1,2)%Mod)%Mod;
	return f[n][m];
}
int main()
{
	N=GetInt();
	Init();
	for(ri i=1;i<=N;i++)d[GetInt()]++;
	if(d[1]&1)return printf("0\n"),0;
	f[0][0]=1;
	for(ri i=1;i<=N;i++)f[i][0]=f[i-2][0]*(i-1)%Mod;
	printf("%lld\n",DP(d[1],d[2]));
	return 0;
}

