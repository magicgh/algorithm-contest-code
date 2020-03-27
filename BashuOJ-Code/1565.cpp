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
const int MAXN=100005;
const ll INF=1e18;
int n,k;
ll l,r,a[MAXN];
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline const ll getll()
{
	ll num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline bool Check(ll Limit)
{
	ll sum=Limit;
	int cnt=1;
	for(ri i=1;i<=n;i++)
	{
		if(sum<a[i])cnt++,sum=Limit;
		sum-=a[i];
	}
	return cnt<=k; 
}
ll Binary()
{
	while(l<=r)
	{
		ll mid=(l+r)>>1;
		if(Check(mid))r=mid-1;
		else l=mid+1;
	}
	return l;
}
int main()
{
	n=getint(),k=getint();
	for(ri i=1;i<=n;i++)a[i]=getll(),l=max(l,a[i]),r+=a[i];
	printf("%lld\n",Binary());
	return 0;
}


