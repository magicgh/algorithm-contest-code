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
const int MAXN=200005;
int n,m,a[MAXN];
ll Min[MAXN],Max[MAXN],C[MAXN],Ans1,Ans2;
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline ll getll()
{
	ll num=0;int bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline int lowbit(int x){return x&(-x);}
inline void Add(int pos,int val)
{
	for(ri i=pos;i<=m;i+=lowbit(i))C[i]+=val;
}
inline ll Query(int pos)
{
	ll Ans=0;
	for(ri i=pos;i>0;i-=lowbit(i))Ans+=C[i];
	return Ans;
}
int main()
{
	n=getint();
	for(ri i=1;i<=n;i++)a[i]=getint(),m=max(m,a[i]);
	for(ri i=1;i<=n;i++)
	{
		Min[i]=Query(a[i]-1);
		Add(a[i],1);
	}
	memset(C,0,sizeof(C));
	for(ri i=n;i>=1;i--)
	{
		Max[i]=Query(m)-Query(a[i]);
		Add(a[i],1);
	}
	for(ri i=1;i<=n;i++)Ans1+=Min[i]*Max[i];
	for(ri i=1;i<=n;i++)Ans2+=Max[i]*(Max[i]-1)/2;
	printf("%lld",Ans2-Ans1);
	return 0;
}