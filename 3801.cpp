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
const ll Mod=1000000007ll;
const int MAXN=405;
int d,N;
ll C[MAXN][MAXN],f[MAXN][MAXN];
namespace FastIO
{
    const ll L=1<<15;
    char buffer[L],*S,*T;
    inline char getchar()
	{
        if(S==T){T=(S=buffer)+fread(buffer,1,L,stdin);if(S==T)return EOF;}
		return *S++;
    }
    inline const int getint()
	{
		ri num=0,bj=1;
		register char c=getchar();
		while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
		while(isdigit(c))num=num*10+c-'0',c=getchar();
		return num*bj;
	}
	inline const ll getll()
	{
		ll num=0;int bj=1;
		char c=getchar();
		while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
		while(isdigit(c))num=num*10+c-'0',c=getchar();
		return num*bj;
	}
	inline void putint(int x)
	{
	     if(x<0)putchar('-'),x=-x;
	     if(x>9)putint(x/10);
	     putchar(x%10+'0');
	}
	inline void putll(ll x)
	{
	     if(x<0)putchar('-'),x=-x;
	     if(x>9)putint(x/10);
	     putchar(x%10+'0');
	}
};
using namespace FastIO;
inline void Init()
{
	C[0][0]=1ll;
	for(ri i=1;i<=400;i++)
	{
		C[i][0]=C[i][i]=1ll;
		for(ri j=1;j<i;j++)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%Mod;
	}
}
int main()
{
	Init();
	d=getint(),N=getint();
	if(N==0)putchar('1'),putchar('\n');
	else if(d==1)putll(C[N<<1][N]),putchar('\n');
	else if(d==2)
	{
		ll Ans=0;
		for(ri i=1;i<=N-1;i++)
			Ans=(Ans+C[N][i]*C[N][i]%Mod)%Mod;
		Ans=(C[N<<1][N]%Mod*(Ans+2)%Mod)%Mod;
		putll(Ans),putchar('\n');
	}
	else 
	{
		for(ri i=0;i<=d;i++)f[i][0]=1;
		for(ri i=1;i<=d;i++)
			for(ri j=1;j<=N;j++)
				for(ri k=0;k<=j;k++)
					f[i][j]=(f[i][j]+f[i-1][k]*C[(N-k)<<1][(j-k)<<1]%Mod*C[(j-k)<<1][j-k]%Mod)%Mod; 
		putll(f[d][N]),putchar('\n');
	}
	return 0;	
}
