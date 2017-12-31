#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define ri register int
#define ll long long
using namespace std;
int T;
ll n,Min;
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline ll getll()
{
	ll num=0;int bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline ll gcd(ll a,ll b){return (!b)?a:gcd(b,a%b);}
inline ll Multi(ll a,ll b,ll Mod)
{
	ll ret=0,base=a;
	while(b)
	{
		if(b&1)ret=(ret+base)%Mod;
		base=(base+base)%Mod;
		b>>=1;
	}
	return ret;
}
inline ll Pow(ll a,ll b,ll Mod)
{
	ll ret=1,base=a;
	while(b)
	{
		if(b&1)ret=Multi(ret,base,Mod)%Mod;
		base=Multi(base,base,Mod)%Mod;
		b>>=1;
	}
	return ret;
}
inline ll Sec_Det(ll a,ll n)
{
	ll d=n-1,cnt=0;//d为偶数 
	while(!(d&1))d>>=1,cnt++;//直到d为奇数 
	ll x=Pow(a,d,n);
	if(x==1||x==n-1)return 0;
	for(ll i=1;i<=cnt;i++)
	{
		x=Multi(x,x,n);
		if(x==n-1)return 0;
	}
	return 1;
}
inline bool Miller_Rabin(ll n)
{
	if(n==2)return 1;
	if(n==1||!(n&1))return 0;
	for(ri i=1;i<=5;i++)
	{
		ll a=(ll)(rand()%(n-1)+1);
		if(Sec_Det(a,n))return 0; 
	}
	return 1;
}
inline ll Pollard_Rho(ll n,int c)
{
	ll x,y,d,k=2;
	x=rand()%(n-1)+1,y=x;
	for(ll i=1;;i++)
	{
		x=(Multi(x,x,n)+c)%n;
		d=gcd(y-x,n);
		if(1<d&&d<n)return d;
		if(y==x)return n;//找到循环,x选择失败
		if(i==k)y=x,k<<=1;//优化 
	}
} 
inline void FindFac(ll n,int k)
{
	if(n==1)return;
	if(Miller_Rabin(n))
	{
		Min=n<Min?n:Min;
		return;
	}
	ll p=n;
	while(p>=n)p=Pollard_Rho(p,k--);
	FindFac(p,k);
	FindFac(n/p,k);
}
int main()
{
	srand(time(NULL));
	T=getint();
	while(T--)
	{
		Min=n=getll();
		if(Miller_Rabin(n))printf("Prime\n");
		else 
		{
			FindFac(n,10007);
			printf("%lld\n",Min);
		}
	}
	return 0;
}