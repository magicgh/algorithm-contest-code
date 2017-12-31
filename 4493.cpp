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
const int INF=0x7fffffff/2;
struct List{int h,num,tall;};
List a[MAXN];
int n,Ans[MAXN];
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline bool cmp(const List &a,const List &b){return a.h<b.h;}
struct Segment
{
	int L[MAXN<<2],R[MAXN<<2],sum[MAXN<<2];
	inline void Build(int d,int l,int r)
	{
		if(l==r){sum[d]=1;return;}
		int mid=(l+r)>>1;
		Build(d<<1,l,mid);
		Build(d<<1|1,mid+1,r);
		sum[d]=sum[d<<1]+sum[d<<1|1];
	}
	inline void Modify(int d,int l,int r,int pos)
	{
		if(pos<l||pos>r)return;
		if(l==r&&l==pos){sum[d]--;return;}
		int mid=(l+r)>>1;
		Modify(d<<1,l,mid,pos);
		Modify(d<<1|1,mid+1,r,pos);
		sum[d]=sum[d<<1]+sum[d<<1|1];
	}
	inline int Find(int d,int l,int r,int pos)
	{
		if(l==r)return l;
		int mid=(l+r)>>1;
		if(pos<=sum[d<<1])return Find(d<<1,l,mid,pos);
		else return Find(d<<1|1,mid+1,r,pos-sum[d<<1]);
	}
};
Segment tr;
int main()
{
	n=getint();
	for(ri i=1;i<=n;i++)
	{
		int h=getint(),num=getint();
		a[i]=(List){h,num};
	}
	sort(a+1,a+n+1,cmp);
	for(ri i=1;i<=n;i++)
	{
		if(n-i<a[i].num)
		{
			printf("impossible\n");
			return 0;
		}
		a[i].tall=n-i;
	}
	tr.Build(1,1,n);
	for(ri i=1;i<=n;i++)
	{
		int Front=tr.Find(1,1,n,a[i].num+1);
		int Back=tr.Find(1,1,n,a[i].tall-a[i].num+1);
		Ans[(Front<Back)?Front:Back]=a[i].h;
		tr.Modify(1,1,n,(Front<Back)?Front:Back);
	}
	for(ri i=1;i<=n;i++)printf("%d ",Ans[i]);
	return 0;
}


