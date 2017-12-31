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
const double eps=1e-10;
int n,t;
double a[10005],b[10005],c[10005];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline double max(const double &x,const double &y){return x>y?x:y;}
inline double Calc(double x)
{
	double ans=-1e100;
	for(ri i=1;i<=n;i++)ans=max(ans,a[i]*x*x+b[i]*x+c[i]);
	return ans;
}
double Ternary(double l,double r)
{
	while(l+eps<r)
	{
		double mid=l+(r-l)/3.0;
		double mmid=r-(r-l)/3.0;
		if(Calc(mid)<Calc(mmid))r=mmid;
		else l=mid;
	}
	return l;
}
int main()
{
	t=getint();
	while(t--)
	{
		n=getint();
		for(ri i=1;i<=n;i++)scanf("%lf%lf%lf",&a[i],&b[i],&c[i]);
		printf("%.4lf\n",Calc(Ternary(0.0,1000.0)));
	}
	return 0;
}

