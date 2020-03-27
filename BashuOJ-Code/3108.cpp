#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define ri register int
#define ll long long
using namespace std;
ll n,m,LCM=1,sum,s[1005];
inline const ll getll()
{
	ll num=0;int bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline ll gcd(ll a,ll b)
{
	if(b==0)return a;
	return gcd(b,a%b);
}	
inline ll lcm(ll a,ll b)
{
	ll Mul=a*b;
	return Mul/gcd(a,b);
}
inline ll Check(ll mid)
{
	ll cnt=0;
	for(ri i=1;i<=m;i++)
		cnt+=(mid%s[i]==0)+((mid-1)/s[i]+1);
	return cnt>=n;
}
void Binary()
{
	ll l=1,r=1000000ll,Ans=0;int id;
	while(l<=r)
	{
		ll mid=(l+r)>>1;
		if(Check(mid))r=mid-1;
		else l=mid+1;
	}
	for(ri i=1;i<=m;i++)
		Ans+=((l-1)/s[i]+1);
	for(ri i=1;i<=m;i++)
	{
		Ans+=(l%s[i]==0);
		if(Ans==n){id=i;break;}
	}
	printf("%d\n",id);
}
int main()
{
	n=getll(),m=getll();
	for(ri i=1;i<=m;i++)
	{
		s[i]=getll();
		LCM=lcm(LCM,s[i]);
	} 
	for(ri i=1;i<=m;i++)
		sum+=LCM/s[i];
	n%=sum;
	if(n<=m)
	{
		printf("%lld\n",n);
		return 0;
	}
	Binary();
	return 0;
}

