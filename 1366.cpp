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
const double eps=1e-8;
int t;
double H,h,D;
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')	bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline double Calc(double x){return (D*h-H*x)/(D-x)+x;}
double Ternary(double l,double r)
{
	while(l+eps<r)
	{
		double mid=l+(r-l)/3.0;
		double mmid=r-(r-l)/3.0;
		if(Calc(mid)>Calc(mmid))r=mmid;
		else l=mid;
	}
	return l;
}
int main()
{
	t=getint();
	while(t--)
	{
		scanf("%lf%lf%lf",&H,&h,&D);
		printf("%.3lf\n",Calc(Ternary(0.0,h/H*D)));
	}
	return 0;
}
