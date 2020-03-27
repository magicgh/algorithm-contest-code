#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<vector>
#include<stack>
#define ri register int
#define ll long long
//#define ENABLE_FASTIO
using namespace std;
const int MAXN=100005;
const ll Mod=998244353ll; 
ll n,k,bit;
ll Ans,kpow[MAXN]={1ll},f[MAXN];
namespace FastIO
{
	const int L=1<<15;
	char buf[L],*S,*T;
	#ifdef ENABLE_FASTIO
	inline char getchar()
	{
		if(S==T)
		{
			T=(S=buf)+fread(buf,1,L,stdin);
			if(S==T)return EOF;
		}
		return *S++;
	} 
	#endif
	inline const int GetInt()
	{
		register int num=0,bj=1;
		register char c=getchar();
		while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
		while(isdigit(c))num=num*10+c-'0',c=getchar();
		return num*bj;
	}
	inline const ll GetLL()
	{
		register ll num=0,bj=1;
		register char c=getchar();
		while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
		while(isdigit(c))num=num*10+c-'0',c=getchar();
		return num*bj;
	}
	inline double GetDouble()    
	{  
		register double num=0,bits=0.1,bj=1.0; 
	    register char c=getchar();
	    bool dec=0;  
	    while(c!='-'&&c!='.'&&!isdigit(c))c=getchar(); 
		if(c=='-')bj=-1;
	    else if(c=='.')dec=1;
	    else num=c-'0';  
	    while((!dec),c=getchar(),isdigit(c))num=num*10+c-'0'; 
	    if(c!='.')return num*bj;
		else while(c=getchar(),isdigit(c))
			num+=bits*(c-'0'),bits*=0.1;  
	    return num*bj;  
	}  
	inline void GetString(char *s)
	{
		register char c=getchar();
		while(!(33<=c&&c<=126))c=getchar();
		while(33<=c&&c<=126)*s++=c,c=getchar();
		*s=0;
	}
	inline void PutInt(int x)
	{
	     if(x<0)putchar('-'),x=-x;
	     if(x>9)PutInt(x/10);
	     putchar(x%10+'0');
	}
	inline void PutLL(ll x)
	{
	     if(x<0)putchar('-'),x=-x;
	     if(x>9)PutLL(x/10);
	     putchar(x%10+'0');
	}
	inline void PutString(char *s)
	{
		int len=strlen(s);
		for(register int i=0;i<len;i++)putchar(s[i]);
	} 
};
using FastIO::GetInt; 
using FastIO::GetLL; 
using FastIO::GetDouble; 
using FastIO::GetString; 
using FastIO::PutInt; 
using FastIO::PutLL; 
using FastIO::PutString; 
inline ll Pow(ll a,ll b)
{
	ll ret=1,base=a;
	while(b)
	{
		if(b&1)ret=ret*base%Mod;
		base=base*base%Mod;
		b>>=1;
	}
	return ret;
}
inline void Init(){for(ll i=1;i<=n;i++)kpow[i]=kpow[i-1]*i%Mod;}
inline ll C(ll n,ll m){if(n<m)return 0;else return kpow[n]*Pow(kpow[m]*kpow[n-m]%Mod,Mod-2)%Mod;}
int main()
{
	n=GetLL(),k=GetLL();
	Init();
	for(ll i=1;i<=n;i++)
	{
		ll x=GetLL(),k=log2(x);bit=max(bit,k);
		for(ll i=0;i<=k;i++)f[i]+=(x&1),x>>=1;
	}
	for(ll i=0;i<=bit;i++)
		for(ll j=1;j<=f[i]&&j<=k;j+=2)
			Ans=(Ans+(C(f[i],j)*C(n-f[i],k-j)%Mod*(1<<i))%Mod)%Mod;
	PutLL(Ans);
	return 0;
}
