#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<vector>
#define ri register int
#define ll long long
using namespace std;
const int MAXN=400005;
int n,m,L[MAXN],R[MAXN];
bool bj[MAXN];
ll sum[MAXN],Ans;
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline void Pushup(int x)
{
	sum[x]=sum[x<<1]+sum[x<<1|1];
	bj[x]=bj[x<<1]&bj[x<<1|1];
}
inline void Build(int d,int l,int r)
{
	L[d]=l,R[d]=r;
	if(l==r)
	{
		scanf("%lld",&sum[d]);
		if(sum[d]==0||sum[d]==1)bj[d]=1;
		return;
	}

	int mid=(l+r)>>1;
	Build(d<<1,l,mid);
	Build(d<<1|1,mid+1,r);
	Pushup(d);
}
inline void Modify(int d,int l,int r)
{
	if(bj[d])return;
    int mid=(L[d]+R[d])>>1;
    if(L[d]==R[d])
    {
        sum[d]=(ll)(sqrt(sum[d]));
        if(sum[d]==0||sum[d]==1)bj[d]=1;
        return;
    }
    if(l<=mid)Modify(d<<1,l,r);
    if(r>mid)Modify(d<<1|1,l,r);
    Pushup(d);
}
inline ll Query(int d,int l,int r)
{
    int mid=(L[d]+R[d])>>1;
    if(L[d]==l&&R[d]==r)return sum[d];
    if(r<=mid)return Query(d<<1,l,r);
    else if(l>mid)return Query(d<<1|1,l,r);
    else return Query(d<<1,l,mid)+Query(d<<1|1,mid+1,r);
}

int main()
{
	n=getint();
	Build(1,1,n);
	m=getint();
	for(ri i=1;i<=m;i++)
	{
		int k=getint(),l=getint(),r=getint();
		if(l>r) swap(l,r);
		if(k==0)Modify(1,l,r);
		if(k==1)printf("%lld\n",Query(1,l,r));	
	}
	return 0;
}