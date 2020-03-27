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
const int MAXN=100005;
struct point{ll x,y;};
int n,m;
ll a[MAXN],ax,ay,bx,by;;
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline ll Dist(const point &p1,const point &p2){return abs(p1.x-p2.x)+abs(p1.y-p2.y);}
inline ll Binary(const point &p1,const point &p2)
{	
	int l=1,r=n;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(a[mid]<p1.x)l=mid+1;
		if(a[mid]>p2.x)r=mid-1;
		if(a[mid]>=p1.x&&a[mid]<=p2.x)return Dist(p1,p2);
	}
	point p3=(point){a[l],0};
	point p4=(point){a[r],0};
	ll lans=Dist(p1,p3)+Dist(p2,p3);
	ll rans=Dist(p1,p4)+Dist(p2,p4);
	return min(lans,rans);
}
int main()
{
	n=getint();
	for(ri i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	m=getint();
	for(ri i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld%lld",&ax,&ay,&bx,&by);
		point p1=(point){ax,ay},p2=(point){bx,by};	
		if(ax>bx)swap(p1,p2);
		if(p1.y*p2.y>0)printf("%lld\n",(ll)Dist(p1,p2));
		else printf("%lld\n",Binary(p1,p2));
	}	
	return 0;
}

