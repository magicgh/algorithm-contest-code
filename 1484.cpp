#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
long long num[1000005]={0};
long long f(long long l,long long r,long long x)
{
	long long mid;
	while(l<r)
	{
		mid=(l+r)/2;
		if(x<=num[mid])r=mid;
		else l=mid+1;
	}
	if(num[l]==x)return l;
	else return -1;
}
int main(){
	long long n,m;
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++)scanf("%lld",&num[i]);
	for(long long i=1;i<=m;i++)
	{
		long long x;
		scanf("%lld",&x);
		printf("%lld\n",f(1,n,x));
	}
	return 0;
}
