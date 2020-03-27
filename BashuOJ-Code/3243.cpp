#include<cstdio>
#define ri register int
using namespace std;
const int MAXN=1005;
const int Mod=10000	;
int n,m,f[MAXN][MAXN];
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
	n=getint(),m=getint(),f[1][0]=1;
	for(ri i=2;i<=n;i++)
		for(ri j=0;j<=m;j++)
			f[i][j]=(f[i][j-1]+f[i-1][j]-((j-i<0)?0:f[i-1][j-i])+Mod)%Mod;
		printf("%d",f[n][m]);	
	return 0;
}
