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
using namespace std;
const int Mod=998244353;
const int MAXN=5005;
int f[MAXN][MAXN];
int n,k;
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
	//freopen("t.in","r",stdin);
	//freopen("t.out","w",stdout);
	n=getint(),k=getint();
	for(ri i=1;i<=n;i++)
		f[i][1]=f[i][i]=1;
	for(ri i=1;i<=n;i++)
		for(ri j=2;j<=k&&j<i;j++)
			f[i][j]=(f[i-1][j-1]+f[i-j][j]%Mod)%Mod;
	printf("%d\n",f[n][k]);
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}

