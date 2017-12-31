#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define uint long long
#define ri register uint
using namespace std;
struct land{uint x,y;}a[50005],b[50005];
uint n,f[50005],q[50005],l,r,cnt;
inline bool cmp(const land &a,const land &b){return (a.x==b.x&&a.y>b.y)||a.x<b.x;}
inline double slope(uint k,uint j){return double(f[j]-f[k])/double(a[k+1].y-a[j+1].y);}
inline uint getuint()
{
	uint num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void DP()
{
	l=1,r=1;
	for(ri i=1;i<=cnt;i++)
	{
		while(l<r&&slope(q[l],q[l+1])<a[i].x)l++;
		f[i]=f[q[l]]+a[i].x*a[q[l]+1].y;
		while(l<r&&slope(q[r-1],q[r])>slope(q[r],i))r--;
		q[++r]=i;
	}
}
int main()
{
	n=getuint();
	for(ri i=1;i<=n;i++)
		b[i]=(land){getuint(),getuint()};
	sort(b+1,b+n+1,cmp);
	for(ri i=1;i<=n;i++)
	{
		while(cnt&&a[cnt].y<=b[i].y)cnt--;
		a[++cnt]=b[i];
	}
	DP();
	printf("%lld",f[cnt]);
	return 0;
}

