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
const int MAXN=100005;
int t,last;
ll n,m,q,ret,f[MAXN];
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
		int num=0,bj=1;
		char c=getchar();
		while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
		while(isdigit(c))num=num*10+c-'0',c=getchar();
		return num*bj;
	}
	inline const ll getll()
	{
		ll num=0,bj=1;
		char c=getchar();
		while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
		while(isdigit(c))num=num*10+c-'0',c=getchar();
		return num*bj;
	}
};
using namespace FastIO;
int main()
{
	t=getint();
	while(t--)
	{
		n=getll(),m=getll(),q=getll(),ret=0,last=0;
		memset(f,-1,sizeof(f));
		f[0]=0;
		while(true)
		{
			if(f[(last+m)%n]!=-1)break;
			f[(last+m)%n]=f[last]+m;
			last=(last+m)%n;
		}
		for(ri i=0;i<n;i++)
			if(f[i]!=-1&&f[i]<q)ret+=(q-f[i])/n+1;
		printf("%lld\n",q-ret+1);
	}
	return 0;
}

