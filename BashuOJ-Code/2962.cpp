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
const int Mod=1e9+7;
ll f[105][305][105],g[105][305][105];
int T,N,K,P;
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
	for(ri i=1;i<=300;i++)f[1][i][0]=i,g[1][i][0]=1;
		for(ri i=2;i<=100;i++)
			for(ri j=1;j<=300;j++)
				for(ri k=0;k<=100;k++)
				{
					if(k>=1)g[i][j][k]=(g[i-1][j][k]*j%Mod+f[i-1][j-1][k-1]%Mod)%Mod;
					else g[i][j][k]=(g[i-1][j][k]*j%Mod)%Mod;
					f[i][j][k]=(f[i][j-1][k]+g[i][j][k])%Mod;
				}
	T=getint();
	while(T--)
	{
		N=getint(),K=getint(),P=getint();
		printf("%lld\n",f[N][K][P]);
	}
	return 0;
}

