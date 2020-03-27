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
struct num{int a,b;}a[500505];
int n,cnt,c[500505];
inline bool cmp(const num &a,const num &b)
{
	return (a.a==b.a&&a.b>b.b)||(a.a<b.a);
}
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+c-'0',c=getchar();
	return num*bj;
}
int binary(int l,int r,int x)
{
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(x>=c[mid])l=mid+1;
		else r=mid-1;
	}
	return l;
}
inline void DP()
{
	int ans=0,len=0;
	for(ri i=1;i<=n;i++)
	{
		if(a[i].b>=c[len]){c[++len]=a[i].b;continue;}
		int pos=upper_bound(c+1,c+len+1,a[i].b)-c;
		c[pos]=a[i].b;
	}
	printf("%d\n",len);
}
int main()
{
	n=getint();
	for(ri i=1;i<=n;i++)
	{
		int x=getint();
		if(i-x<0)continue;
		a[++cnt].a=x,a[cnt].b=i-a[cnt].a;//->a存num[i],->b存i-num[i],满足j<i,a[j]<a[i]
	}
	n=cnt;sort(a+1,a+n+1,cmp);
	DP();
	return 0;
}
