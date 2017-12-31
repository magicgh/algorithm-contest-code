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
const int MAXN=200005;
ll n,a[MAXN];
inline const int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline const ll GetLL()
{
	ll num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline bool Check(ll Limit,ll tot)
{
	ll cnt=0;
	for(ri i=1,j=1;i<n;i++)
	{
		while(j<n&&a[j+1]-a[i]<Limit)j++;
		cnt+=(j-i);
	}
	return cnt<tot;
}
ll Binary(ll tot)
{
	ll l=0,r=a[n]-a[1],ret=0;
	while(l<=r)
	{
		ll mid=(l+r)>>1;
		if(Check(mid,tot))ret=mid,l=mid+1;
		else r=mid-1;
	}
	return ret;
}
int main()
{
	n=GetLL();
	for(ri i=1;i<=n;i++)a[i]=GetLL();
	sort(a+1,a+n+1);
	if((n*(n-1)/2)&1)printf("%lld\n",Binary((n*(n-1)/4)));
	else printf("%lld\n",(Binary((n*(n-1)/4))+Binary((n*(n-1)/4)+1))/2);
	return 0;
}


