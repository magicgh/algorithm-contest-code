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
const ll Mod=999911659ll;
ll t[5]={0,2,3,4679,35617};
ll Fac[5][35700];
ll n,g,a[10];
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
inline ll Pow(ll a,ll b,ll Mod)
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
inline ll C(ll n,ll m,int id)
{
	if(n<m)return 0;
	return Fac[id][n]*Pow(Fac[id][m]*Fac[id][n-m],t[id]-2,t[id])%t[id];
}
inline ll Lucas(ll n,ll m,int id)
{
	if(m==0)return 1;
	return Lucas(n/t[id],m/t[id],id)%t[id]*C(n%t[id],m%t[id],id)%t[id];
}
inline ll CRT()
{
	ll Mul=1,Ans=0;
	for(ri i=1;i<=4;i++)Mul*=t[i];
	for(ri i=1;i<=4;i++)
	{
		ll m=t[i],M=Mul/m,Inv=Pow(M,m-2,m);
		Ans=(Ans+M*Inv%Mul*a[i]%Mul)%Mul;
	}
	return Ans;
}
int main()
{
	n=getll(),g=getll();
	if(g==Mod){printf("0\n");return 0;}
	g%=Mod;
	for(ri i=1;i<=4;i++)
	{
		Fac[i][0]=1;
		for(ri j=1;j<=t[i];j++)
			Fac[i][j]=Fac[i][j-1]*j%t[i];
	}
	for(ll i=1;i<=sqrt(n);i++)
	{
		if(n%i==0)
		{
			ll j=n/i;
			for(ri k=1;k<=4;k++)
			{
				if(i!=j)a[k]=(a[k]+Lucas(n,i,k)%t[k])%t[k];
				a[k]=(a[k]+Lucas(n,j,k)%t[k])%t[k];
			}
		}
	}
	printf("%lld\n",Pow(g,CRT(),Mod));
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}


