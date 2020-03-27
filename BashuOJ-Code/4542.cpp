#include<cstdio>
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;
const ll p=10007;
ll n,m;int t;
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
inline ll C(ll n,ll m)
{
	ll sum1=1,sum2=1;
	for(int i=n-m+1;i<=n;++i)sum1=(sum1*i)%p;
	for(int i=1;i<=m;i++)sum2=(sum2*i)%p;
	return sum1*Pow(sum2,p-2,p)%p;
}
inline ll Lucas(ll n,ll m){return (!m)?1:(C(n%p,m%p)*Lucas(n/p,m/p))%p;}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&m);
		printf("%lld\n",Lucas(n,m));
	}
	return 0;
}