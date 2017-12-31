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
const ll Mod=1000000007ll;
ll t,p;
inline ll getll ()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline ll Pow(ll a,ll b)
{
	ll ret=1,base=a;
	while(b)
	{
		if(b&1)ret=(ret%Mod*base%Mod)%Mod;
		base=(base%Mod*base%Mod)%Mod;
		b>>=1;
	}
	return ret%Mod;
}
inline ll C(ll m,ll n)
{
	if(n<m)return 0;
	ll Up=1,Down=1;
	for(ll i=1;i<=n-m;i++)Down=(Down%Mod*i%Mod)%Mod;
	for(ll i=m+1;i<=n;i++)Up=(Up%Mod*i%Mod)%Mod;
	return (Up*Pow(Down,Mod-2))%Mod;
}
int main()
{
	t=getll(),p=abs(getll());
	
	printf("%lld\n",(C(t+p,2*t)*Pow(Pow(4,t),Mod-2))%Mod);
	return 0;
}

