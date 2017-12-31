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
const int MAXN=2000005;
ll n,Mod,Ans=1,p[MAXN];
bool vst[MAXN];
void Init()
{
	int Limit=2000000;
	for(ri i=2;i<=Limit;i++)
	{
		if(!vst[i])p[++p[0]]=i;
		for(ri j=1;j<=p[0]&&i*p[j]<=Limit;j++)
		{
			vst[i*p[j]]=1;
			if(i%p[j]==0)break;
		}
	}
}
inline ll Div(ll a,ll b)
{
	ll Ans=0;
	while(a)
	{
		Ans+=a/b;
		a/=b;
	}
	return Ans;
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
	return ret;
}
int main()
{
	Init();
	scanf("%lld%lld",&n,&Mod);
	for(int i=1;i<=p[0]&&p[i]<=2*n;i++)
	{
		ll x=Div(2*n,p[i]);
		ll y=Div(n,p[i]);
		ll z=Div(n+1,p[i]);
		x=x-(y+z);
		Ans=(Ans%Mod*Pow(p[i],x)%Mod)%Mod;
	}
	printf("%lld",Ans);
	return 0;
}
