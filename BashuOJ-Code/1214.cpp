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
const int MAXN=200005;
const double eps=1e-5;
struct Pack{ll x,y,s;};
ll sum;
Pack a[MAXN];
int n;
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
inline bool Check(double Limit)
{
	double t,last=0;
	for(ri i=1;i<=n;i++)
	{
		t=(double)a[i].s/Limit;
		if(last+t>a[i].y)return 0;
		else if(last+t<a[i].x)last=a[i].x;
		else last+=t;
	}
	return 1;
}
double Binary()
{
	double l=0,r=(double)sum;
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
	n=GetInt();
	for(ri i=1;i<=n;i++)
	{
		ll x=GetLL(),y=GetLL(),s=GetLL();
		a[i]=(Pack){x,y,s};
		sum+=s;
	}
	printf("%.2lf",Binary());
	return 0;
}

