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
const ll Mod=1000003ll;
const int MAXN=1000005;
struct Point{ll x,y;};
ll n,m,p,Fac[MAXN],f[MAXN];
Point List[MAXN];
int tot;
inline const ll getll()
{
	ll num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline bool cmp(const Point &a,const Point &b)
{
	return (a.x==b.x&&a.y<b.y)||(a.x<b.x);
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
inline ll C(ll n,ll m)
{
	if(n<m)return 0;
	return Fac[n]*Pow(Fac[m]*Fac[n-m]%Mod,Mod-2)%Mod;
}
inline ll Lucas(ll n,ll m)
{
	if(m==0)return 1;
	return Lucas(n/Mod,m/Mod)%Mod*C(n%Mod,m%Mod)%Mod;
}
int main()
{
	n=getll(),m=getll(),p=getll();
	for(ri i=1;i<=p;i++)
	{
		ll x=getll(),y=getll();
		List[++tot]=(Point){x,y};
	}
	List[++tot]=(Point){n+1,m+1};
	Fac[0]=1;
	for(ri i=1;i<=1000003;i++)
		Fac[i]=Fac[i-1]*i%Mod;
	sort(List+1,List+tot+1,cmp);
	for(ri i=1;i<=tot;i++)
	{
		f[i]=Lucas(List[i].y-1,List[i].x-1);
		for(ri j=1;j<i;j++)
		{
			if(List[i].x>List[j].x&&List[i].y>List[j].y)
				f[i]=(f[i]-f[j]*Lucas(List[i].y-List[j].y-1,List[i].x-List[j].x-1)%Mod+Mod)%Mod;
		}
	}
	printf("%lld\n",f[tot]);
	return 0;
}

