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
vector<int>a[MAXN];
int n,m;
ll List[MAXN];
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
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
struct SegTree
{
	int L[MAXN<<2],R[MAXN<<2];ll sum[MAXN<<2],Max[MAXN<<2];
	inline void Pushup(int d)
	{
		sum[d]=sum[d<<1]+sum[d<<1|1];
		Max[d]=max(Max[d<<1],Max[d<<1|1]);
	}
	inline void Build(int d,int l,int r)
	{
		L[d]=l,R[d]=r,sum[d]=Max[d]=0;
		if(l==r)return;
		int mid=(l+r)>>1;
		Build(d<<1,l,mid);
		Build(d<<1|1,mid+1,r);
		Pushup(d);	
	}
	inline void Modify(int d,int p,ll v)
	{
		if(L[d]>p||R[d]<p)return;
		if(L[d]==R[d]){sum[d]=Max[d]=v;return;}
		Modify(d<<1,p,v);
		Modify(d<<1|1,p,v);
		Pushup(d);	
	}
	inline void Mod(int d,int l,int r,ll mod)
	{
		if(L[d]>r||R[d]<l)return;
		if(l<=L[d]&&R[d]<=r)
		{
			if(Max[d]<mod)return;
			if(L[d]==R[d]){sum[d]%=mod,Max[d]%=mod;return;}
		}
		Mod(d<<1,l,r,mod);
		Mod(d<<1|1,l,r,mod);
		Pushup(d);
	}
	inline ll Query(int d,int l,int r)
	{
		if(L[d]>r||R[d]<l)return 0;
		if(l<=L[d]&&R[d]<=r)return sum[d];
		return Query(d<<1,l,r)+Query(d<<1|1,l,r);
	}
};
SegTree tr;
int main()
{
	n=getint(),m=getint();
	for(ri i=1;i<=n;i++)List[i]=getll();
	tr.Build(1,1,n);
	for(ri i=1;i<=n;i++)tr.Modify(1,i,List[i]);
	for(ri i=1;i<=m;i++)
	{
		int op=getint();
		if(op==1)
		{
			int l=getint(),r=getint();
			printf("%lld\n",tr.Query(1,l,r));
		}
		if(op==2)
		{
			int l=getint(),r=getint(),mod=getint();
			tr.Mod(1,l,r,mod);
		}
		if(op==3)
		{
			int k=getint(),y=getint();
			tr.Modify(1,k,y);
		}
	}
	return 0;
}


