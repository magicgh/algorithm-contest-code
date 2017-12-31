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
ll a[100005],r[100005];
ll k,a1,a2,r1,r2;
inline ll Exgcd(ll a,ll b,ll &d,ll &x,ll &y)
{
	ll t;
	if(b==0)d=a,x=1,y=0;
	else
	{
		Exgcd(b,a%b,d,x,y);
		t=x,x=y,y=t-(a/b)*y;
	}
}
inline ll CRT()
{
	ll d,x,y;
	a1=a[1],r1=r[1];
	for(ri i=2;i<=k;i++)
	{
		a2=a[i],r2=r[i];
		Exgcd(a1,a2,d,x,y);
		if((r2-r1)%d!=0){return -1;}
		x=(((r2-r1)/d*x%(a2/d)+(a2/d)))%(a2/d);
		r1+=a1*x,a1*=a2/d;
	}
	return r1; 
}
int main()
{
	while(~scanf("%lld",&k))
	{
		for(ri i=1;i<=k;i++)scanf("%lld%lld",&a[i],&r[i]);
		printf("%lld\n",CRT());
	}
	return 0;
}

