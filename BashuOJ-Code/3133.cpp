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
const int MAXN=2000005;
int n;
ll a[MAXN],s[MAXN],sum;
inline bool Check(int k)
{
	for(ri i=k;i<=n;i++)
		if(s[i]-s[i-k]>=sum)return 1;
	return 0;
}
int Binary()
{
	int l=1,r=n;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(Check(mid))r=mid-1;
		else l=mid+1;
	}
	return l;
}
int main()
{
	scanf("%d%lld",&n,&sum);
	for(ri i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		s[i]=s[i-1]+a[i];
	}
	printf("%d",Binary());
	return 0;
}

