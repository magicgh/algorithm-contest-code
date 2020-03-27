#include<iostream>
#include<cstdio>
#define ri register int
#define ll __int128
using namespace std;
const int MAXN=81;
int n,m,map[MAXN];
ll f[MAXN][MAXN],Ans;
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline void putint(ll x)
{
     if(x<0)putint('-'),x=-x;
     if(x>9)putint(x/10);
     putchar(x%10+'0');
}
void Solve()
{
	for(ri i=1;i<=n;i++)
	{
		for(ri j=1;j<=m;j++)f[j][j]=map[j]=getint();
		for(ri len=2;len<=m;len++)
		{
			for(ri s=1;s+len-1<=m;s++)
			{
				ri t=s+len-1;
				f[s][t]=max((f[s+1][t]<<1)+map[s],(f[s][t-1]<<1)+map[t]);
			}
		}
		Ans+=(f[1][m]<<1);
	}
	putint(Ans);
}
int main()
{
	n=getint(),m=getint();
	Solve();
	return 0;
}
