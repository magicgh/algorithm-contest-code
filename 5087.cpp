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
const double eps=1e-8;
int n,m;
ll x[MAXN],y[MAXN];
inline const int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline const ll GetLL()
{
	ll num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline bool Check(int pos,ll x0,ll y0)
{
	double k=(double)(-y[pos])/(double)(x[pos]),b=(double)y[pos];
	double X=(double)x0,Y=(double)y0;
	if(k*X+b+eps<=Y)return 1;
	else return 0;
}
inline int Binary(ll x0,ll y0)
{
	int l=1,r=n,Ans=0;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(Check(mid,x0,y0))Ans=mid,l=mid+1;
		else r=mid-1;
	}
	return Ans;
}
int main()
{
	n=GetInt();
	for(ri i=1;i<=n;i++)x[i]=GetLL();
	for(ri i=1;i<=n;i++)y[i]=GetLL();
	sort(x+1,x+n+1);
	sort(y+1,y+n+1);
	m=GetInt();
	for(ri i=1;i<=m;i++)
	{
		ll x0=GetLL(),y0=GetLL();
		printf("%d\n",Binary(x0,y0));
	}
	return 0;
}

