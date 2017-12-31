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
int n,m,l[200005],r[200005],cnt[200005];
long long S,w[200005],v[200005],sum[200005],Max=-1e20,Min=1e20;
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline long long getll()
{
	long long num=0;
	int bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline long long Check(int k)
{
	long long ans=0;
	for(ri i=1;i<=n;i++)
	{
		cnt[i]=cnt[i-1],sum[i]=sum[i-1];
		if(w[i]>=k)cnt[i]+=1,sum[i]+=v[i];
	}
	for(ri i=1;i<=m;i++)ans+=(cnt[r[i]]-cnt[l[i]-1])*(sum[r[i]]-sum[l[i]-1]);
	return ans;
}
long long Binary()
{
	long long l=Min,r=Max;
	while(l<=r)
	{
		long long mid=(l+r)>>1;
		if(Check(mid)<S)r=mid-1;
		else l=mid+1;
	}
	return min(abs(Check(l)-S),abs(Check(r)-S));	 
}
int main()	
{
	n=getint(),m=getint(),S=getll();
	for(ri i=1;i<=n;i++)w[i]=getll(),v[i]=getll(),Min=min(Min,w[i]),Max=max(Max,w[i]);
	for(ri i=1;i<=m;i++)l[i]=getint(),r[i]=getint();
	printf("%lld",Binary());
	return 0;
}

