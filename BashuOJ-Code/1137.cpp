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
const int MAXN=1000005;
int t;
bool vst[MAXN];
long long ans,n,m,p,prime[MAXN];
void Pretreatment()
{
	for(int i=2;i<MAXN;i++)
	{
		if(!vst[i])prime[++prime[0]]=i;
		for(int j=1;j<=prime[0]&&i*prime[j]<MAXN;j++)
		{
			vst[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		}
	}
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
inline long long Div(long long n,long long num)
{
	long long ans=0;
	while(n)
	{
		ans+=n/num;
		n/=num;
	}
	return ans;
}
int main()
{
	Pretreatment();
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&n,&m,&p);
		ans=1;
		for(int i=1;i<prime[0]&&prime[i]<=n;i++)
		{
			long long x=Div(n,prime[i]);
			long long y=Div(m,prime[i]);
			long long z=Div(n-m,prime[i]);
			x=x-(y+z);
			ans*=Pow(prime[i],x,p);
			ans%=p;
		}
		printf("%lld\n",ans);
	}	
	return 0;
}

