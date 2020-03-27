#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<vector>
#define ri register int
#define ll long long
using namespace std;
ll n,k,Mod;
inline ll getll()
{
	ll num=0;int bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline ll Pow(ll a,ll b)
{
	ll base=a,ret=1;
	while(b)
	{
		if(b&1)ret=(ret%Mod*base%Mod)%Mod;
		base=(base%Mod*base%Mod)%Mod;
		b>>=1;
	}
	return ret%Mod;
}
int main()
{
	n=getll(),k=getll();
	Mod=k*10;
	printf("%lld\n",((Pow(3,n-1)+1)/2)%k);
	return 0;
}
