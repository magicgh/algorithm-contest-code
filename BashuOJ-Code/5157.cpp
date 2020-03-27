#include<iostream>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<vector>
#include<stack>
#define ri register int
#define rll register long long
#define ll long long
using namespace std;
const int MAXN=1005;
const ll INF=1e18;
struct Maxinum{int pos;ll val;};
Maxinum Max[MAXN][2];
int n,m; 
ll h[MAXN][MAXN],f[MAXN][MAXN],g[MAXN][MAXN];
namespace FastIO
{
	const int L=1<<15;
	char buf[L],*S,*T;
	inline char getchar()
	{
		if(S==T)
		{
			T=(S=buf)+fread(buf,1,L,stdin);
			if(S==T)return EOF;
		}
		return *S++;
	}
	inline const int GetInt()
	{
		rll num=0,bj=1;
		register char c=getchar();
		while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
		while(isdigit(c))num=num*10+c-'0',c=getchar();
		return num*bj;
	}
	inline const ll GetLL()
	{
		ll num=0,bj=1;
		register char c=getchar();
		while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
		while(isdigit(c))num=num*10+c-'0',c=getchar();
		return num*bj;
	}
	inline void PutLL(ll x)
	{
	     if(x<0)putchar('-'),x=-x;
	     if(x>9)PutLL(x/10);
	     putchar(x%10+'0');
	}
};
using FastIO::GetInt;
using FastIO::GetLL;
using FastIO::PutLL;
void DP()
{
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=i;j++)
			f[i][j]=max(f[i-1][j],f[i-1][j-1])+h[i][j];
	for(ri i=n;i>=1;i--)
		for(ri j=1;j<=i;j++)
			g[i][j]=max(g[i+1][j],g[i+1][j+1])+h[i][j];
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=i;j++)
		{
			ll val=f[i][j]+g[i][j]-h[i][j];
			if(val>Max[i][1].val)
			{
				Max[i][2]=Max[i][1];
				Max[i][1]=(Maxinum){j,val};
				
			}
			else if(val>Max[i][2].val)
				Max[i][2]=(Maxinum){j,val};
		}
}
int main()
{
	n=GetInt(),m=GetInt();
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=i;j++)
			h[i][j]=GetLL();
	DP();
	for(ri i=1;i<=m;i++)
	{
		int u=GetInt(),v=GetInt();
		if(u==1&&v==1)putchar('-'),putchar('1'),putchar('\n');
		else if(Max[u][1].pos==v)PutLL(Max[u][2].val),putchar('\n');
		else PutLL(Max[u][1].val),putchar('\n');
	}
	return 0;
}