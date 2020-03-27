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
ll n,m,l,A,B,C;
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline ll Pow(ll a,ll b,ll p)
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
int main()
{
	ll d,x,y;
	scanf("%lld%lld%lld",&n,&m,&l);
	A=Pow(2,m,n+1)%(n+1),B=n+1,C=l;
	Exgcd(A,B,d,x,y);
	if(C%d!=0){printf("-1\n");return 0;}
	x=((C/d)*x%(B/d)+(B/d))%(B/d);
	printf("%lld\n",x);
	return 0;
}	
