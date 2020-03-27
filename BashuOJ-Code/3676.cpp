#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#define ri register int
#define ll long long
using namespace std;
int q;
ll p,a,b,x1,t;
map<ll,ll>mmp;
inline long long getll()
{
	long long num=0; 
	int bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline long long Pow(long long a,long long b,long long p)
{
	long long ret=1,base=a;
	while(b)
	{
		if(b&1)ret=(ret*base)%p;
		base=(base*base)%p;
		b>>=1;
	}
	return ret;
}
inline int BSGS(ll a,ll b,ll p)
{
	a%=p;
	if(!a&&!b)return 1; 
	if(!a)return -1;
	ll m=ceil(sqrt(p)),t=1;
	mmp.clear();mmp[1]=m+1;
	for(ll i=1;i<m;i++)
	{
		t=t*a%p;
		if(!mmp[t])mmp[t]=i;
	}
	ll tmp=Pow(a,p-m-1,p);t=1;
	for(ll k=0;k<m;k++)
	{
		ll i=mmp[b*t%p];
		if(i)return ((i==m+1)?k*m:k*m+i);
		t=t*tmp%p;
	}
	return -1;
}
inline void Exgcd(ll a,ll b,ll &d,ll &x,ll &y)
{
	ll t;
	if(b==0)d=a,x=1,y=0;
	else
	{
		Exgcd(b,a%b,d,x,y);
		t=x,x=y,y=t-(a/b)*y;
	}
}
inline void Liner(ll a,ll b,ll c)
{
	ll d,x,y;
	Exgcd(a,b,d,x,y);
	if(c%d!=0)printf("-1\n");c/=d;
	x=x*c%p;if(x<0)x=x+p;//线性不定方程最小正整数解 
	printf("%lld\n",x+1);//n-1
}
inline void Poly()
{
	ll d,x,y,c=Pow(a-1,p-2,p),A=(x1+b*c)%p,C=(b*c+t)%p;
	Exgcd(A,p,d,x,y);//解线性方程  (x1+bc)*a^(n-1)+p*y=bc+t 
	if(C%d!=0){printf("-1\n");return;}C/=d;
	if(x<p)x=p+x%p;//x=a^(n-1),x要大于p 
	ll ans=BSGS(a,x*C%p,p);//用BSGS算n-1
	printf("%lld\n",ans==-1?-1:ans+1);//我们要求的是n 
}
int main()
{
	q=getint();
	while(q--)
	{
		p=getll(),a=getll(),b=getll(),x1=getll(),t=getll();
		if(x1==t)printf("1\n");
		else if(a==0)printf((b==t)?"2\n":"-1\n");
		else if(a==1&&b==0)printf("-1\n");
		else if(a==1&&b!=0)Liner(b,p,(t-x1+p)%p);
		else Poly();
	}
	return 0;
}
