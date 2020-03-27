#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<complex>
#define ri register int
using namespace std;
const int MAXN=300005;
const int Mod=998244353;
long long base[MAXN],x,y,g=3;
int n,N;
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
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
	long long &operator[](int pos){return num[pos];}
	inline void NTT(int M,int bj)
	{
		int i,j,k,m;
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
Number a,b,c;
int main()
{
	n=getint();
	for(ri i=0;i<n;i++)
	{
		scanf("%lld%lld",&x,&y);	
		a[n-i-1]=x,b[i]=y;
	}
	for(N=1;N<2*n;N<<=1);	
	a.NTT(N,1),b.NTT(N,1);
	for(ri i=0;i<N;i++)c[i]=a[i]*b[i];
	c.NTT(N,-1);
	for(ri i=n-1;i>=0;i--)printf("%lld\n",c[i]);
	return 0;
}	