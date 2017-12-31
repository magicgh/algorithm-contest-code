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
const int MAXN=100005;
ll ax,ay,bx,by,p,f[MAXN],ans,ans1,ans2;
inline ll getint()
{
	ll num=0;
	int bj=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{ 
		if(c==EOF)return EOF;
		bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	} 
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void Init()
{
	f[0]=1;
	for(int i=1;i<=100000;i++)f[i]=(f[i-1]*i)%p;
}
ll Pow(ll a,ll b)
{
	ll ret=1,base=a;
	while(b)
	{
		if(b&1)ret=(ret*base)%p;
		base=(base*base)%p;
		b>>=1;
	}
	return ret;
}
ll C(ll n,ll m)
{
	if(m>n)return 0;	
	return f[n]*Pow(f[m]*f[n-m]%p,p-2)%p;
}
ll Lucas(ll n,ll m)
{
	if(m==0)return 1;
	else return Lucas(n/p,m/p)*C(n%p,m%p);
}
int main()
{
	while(~(ax=getint()))
	{
		ans=ans1=ans2=0;
		ay=getint(),bx=getint(),by=getint(),p=getint();
		if(ay>ax&&by>bx&&ay>bx){printf("0\n");continue;}
		if(ay>ax)ax=ay;if(by>bx)by=bx;
		Init();
		for(int i=ay;i<=by;i++)
		{
			if(i>ax)ax=i;
			ans=(ans+Lucas(bx+1,i+1)-Lucas(ax,i+1)+p)%p;
		}
		printf("%lld\n",ans);
	}
	return 0;
}

