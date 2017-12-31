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
const int MAXN=205;
ll Ans,f[MAXN][MAXN],g[MAXN],F[MAXN];
ll n,m,p,q;
inline const ll getll()
{
	ll num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
struct Matrix
{
	static const int SIZE=MAXN;
	int n,m;
	ll a[SIZE][SIZE];
	ll *operator[](int x){return a[x];}
	Matrix(int n,int m)
	{
		this->n=n,this->m=m;
		memset(a,0,sizeof(a));
	}
	inline void Unit(){for(ri i=1;i<=200;i++)a[i][i]=1ll;}
	Matrix operator *(Matrix &b)
	const
	{
		Matrix c(n,b.m);
		for(ri i=1;i<=n;i++)
			for(ri j=1;j<=b.m;j++)
				for(ri k=1;k<=m;k++)c[i][j]=(c[i][j]+a[i][k]*b[k][j]%Mod)%Mod;
		return c;
	}
	void operator *=(Matrix &b){*this=*this*b;}
	Matrix operator ^(int b)
	const
	{
		Matrix ret(n,m),base=*this;ret.Unit();
		while(b)
		{
			if(b&1)ret*=base;
			base*=base;
			b>>=1;
		}
		return ret;
	}
};
Matrix A(1,100),B(100,100);
inline ll Pow(ll a,ll b)
{
	ll ret=1,base=a;
	while(b)
	{
		if(b&1)ret=(ret*base)%Mod;
		base=(base*base)%Mod;
		b>>=1;
	}
	return ret;
}
inline ll C(int n,int m)
{
	if(n<m)return 0;
	return F[n]*Pow(F[m]*F[n-m]%Mod,Mod-2)%Mod;
}
int main()
{
	n=getll(),m=getll(),p=getll(),q=getll();
	F[0]=1;
	for(ri i=1;i<=200;i++)F[i]=F[i-1]*i%Mod;
	f[0][0]=1;
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=p&&j<=i;j++)
			f[i][j]=((f[i-1][j-1]*(p-(j-1)))%Mod+f[i-1][j]*j%Mod)%Mod;
	for(ri i=1;i<=p;i++)
	{
		A[1][i]=f[n][i];
		g[i]=f[n][i]*Pow(C(p,i),Mod-2)%Mod;
	}
	for(ll i=1;i<=p;i++)
		for(ll j=1;j<=p;j++)
		{
			for(ll x=max(max(i,j),q);x<=min(p,i+j);x++)
				B[i][j]=(B[i][j]+C(i,i+j-x)*C(p-i,x-i)%Mod)%Mod;
			B[i][j]=(B[i][j]*g[j])%Mod;
		}
	B=B^(m-1);
	A*=B;
	for(ri i=1;i<=p;i++)Ans=(Ans+A[1][i])%Mod;
	printf("%lld\n",Ans);
	return 0;
}

