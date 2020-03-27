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
using namespace std;
const int MAXN=40005;
const long long Mod=950009857;
long long n,m,tmp,k,base[MAXN],g=7;
inline long long Pow(long long a,long long b)
{
	long long ret=1,base=a;
	while(b)
	{
		if(b&1)ret=(ret*base)%Mod;
		base=(base*base)%Mod;
		b>>=1;
	}
	return ret;	
}
struct Number
{
	long long num[MAXN];
	long long &operator[](long long  pos){return num[pos];}
	inline void NTT(long long M,long long bj)
	{
		long long  i,j,k,m;
		long long t0,t1;
		for(i=0;i<M;i++)
		{
			for(j=0,k=i,m=1;m<M;m<<=1,j=((j<<1)|(k&1)),k>>=1);
			if(i<j)swap(num[i],num[j]);
		}
		base[0]=1;
		for(m=1;m<M;m<<=1)
		{
			t0=Pow(g,Mod-1+(Mod-1)*bj/(m<<1));
			for(i=1;i<m;i++)base[i]=base[i-1]*t0%Mod;
			for(k=0;k<M;k+=(m<<1))
				for(i=k;i<k+m;i++)
					t0=num[i]%Mod,t1=base[i-k]*num[i+m]%Mod,num[i]=(t0+t1)%Mod,num[i+m]=(t0-t1+Mod)%Mod;
		}
		if(bj==1)return;
		t0=Pow(M,Mod-2);
		for(i=0;i<M;i++)num[i]=num[i]*t0%Mod;
	}
};
Number A,B;
struct Poly
{
	long long num[MAXN],n;
	long long &operator[](long long  pos){return num[pos];}
	Poly(){memset(num,0,sizeof(num));n=0;}
	Poly operator *(Poly t)
	{
		long long N;
		Poly c;c.n=n;
		for(N=1;N<=(2*n);N<<=1);
		for(long long i=0;i<N;i++)A[i]=B[i]=0;
		for(long long i=0;i<n;i++)A[i]=num[i],B[i]=t.num[i];
		A.NTT(N,1),B.NTT(N,1);
		for(long long i=0;i<N;i++)A[i]=A[i]*B[i]%Mod;
		A.NTT(N,-1);
		for(long long i=0;i<n;i++)c.num[i]=A[i];
		return c;
	}
};
Poly a,b;
inline Poly Pow(Poly &base,long long x)
{
	Poly ret=base;x--;
	while(x)
	{
		if(x&1)ret=ret*base;
		base=base*base;
		x>>=1;
	}
	return ret;	
}
int main()
{
	scanf("%lld%lld%lld",&n,&m,&k);
	for(long long i=0;i<n;i++)scanf("%lld",&a[i]);
	for(long long i=0;i<m;i++)scanf("%lld",&tmp),b[tmp]++;
	a.n=b.n=n;
	if(k>0)a=a*Pow(b,k);
	for(ri i=0;i<n;i++)printf("%lld ",a[i]);
	return 0;
}

