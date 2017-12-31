#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define ri register int
#define ll long long
using namespace std;
const int MAXM=100005;
struct Segment{ll l,r;};
Segment a[MAXM],Tmp[MAXM];
ll n,x,m;
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
inline bool cmp(const Segment &a,const Segment &b)
{
	return (a.l==b.l&&a.r<b.r)||(a.l<b.l);
}
inline bool Check(int Limit)
{
	memcpy(a,Tmp,sizeof(Tmp));
	sort(a+1,a+Limit+1,cmp);
	ll pos=0,sum=0,cnt=0;
	for(ri i=1;i<=Limit;i++)
	{
		if(a[i].l<=pos+1)pos=max(pos,a[i].r);
		else
		{
			if(x==0)return 0;
			sum+=(cnt=(a[i].l-pos-1)/x+((a[i].l-pos-1)%x>0));
			pos=max(pos+cnt*x,a[i].r);
			if(sum>Limit)return 0;
		}
		if(pos>=n)return 1;
	}
	if(pos<n)sum+=(n-pos)/x+((n-pos)%x>0);
	if(sum>Limit)return 0;
	else return 1;
}
int Binary()
{
	ll l=0,r=m,Ans=-1;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(Check(mid))Ans=mid,r=mid-1;
		else l=mid+1;
	}
	return Ans;
}
int main()
{
	n=getll(),m=getll(),x=getll();
	for(ri i=1;i<=m;i++)
	{
		ll l=getll(),r=getll();
		Tmp[i]=a[i]=(Segment){l,r};
	}
	int ret=Binary();
	if(ret==-1)printf("Poor Douer!\n");
	else printf("%lld\n",ret);
	return 0;
}