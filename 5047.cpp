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
const double eps=1e-5;
int n,k;
ll C[MAXN];
struct Num{double s;int id;};
double List[MAXN],Arr[MAXN];
ll Min=1e18,Max;
Num P[MAXN];
inline bool cmp(const Num &a,const Num &b){return a.s<b.s;}
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
inline int lowbit(int x){return x&(-x);}
inline void Add(int pos,int val)
{
	for(ri i=pos;i<=n+1;i+=lowbit(i))C[i]+=val;
}
inline ll Query(int pos)
{
	ll ret=0;
	for(ri i=pos;i>=1;i-=lowbit(i))ret+=C[i];
	return ret;
}
inline bool Check(double Limit)
{
	memset(C,0,sizeof(C));
	ll ret=0;
	P[1]=(Num){0,1};
	for(ri i=1;i<=n;i++)
		Arr[i]=List[i]-Limit;
	for(ri i=2;i<=n+1;i++)
		P[i]=(Num){P[i-1].s+Arr[i-1],i};
	sort(P+1,P+n+2,cmp);
	for(ri i=1;i<=n+1;i++)
	{
		Add(P[i].id,1);
		ret+=i-Query(P[i].id);
	}
	return ret>=k;
}
double Binary()
{
	double l=(double)Min,r=(double)Max;
	while(l+eps<r)
	{
		double mid=(l+r)/2;
		if(Check(mid))r=mid;
		else l=mid;
	}
	return l;
}
int main()
{
	n=getint(),k=getint();
	for(ri i=1;i<=n;i++)
	{
		ll x=getll();
		List[i]=x;
		Min=min(Min,x);
		Max=max(Max,x);
	}
	printf("%.4lf",Binary());
	return 0;
}

