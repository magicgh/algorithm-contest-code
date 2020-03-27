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
const ll Mod=998244353ll;
ll n,s,d;
inline const ll getll()
{
	ll num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline ll Pow(ll a,ll b)
{
	ll ret=1,base=a;
	while(b)
	{
		if(b&1)ret=(ret*base)%Mod;
		base=(base*base)%Mod;
		b>>=1;
	}
	return ret%Mod;
}
int main()
{
	n=getll(),s=getll()%Mod,d=getll()%Mod;
	printf("%lld\n",((s*Pow(2,n%(Mod-1)))%Mod+(n%Mod*d%Mod*Pow(2,(n-1)%(Mod-1))%Mod))%Mod);
	return 0;
}


