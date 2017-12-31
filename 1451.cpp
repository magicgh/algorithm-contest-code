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
const double Pi=3.1415926535;
double x,y,l,d;
inline double Calc(double alpha){return (-x+l*sin(alpha)+d/cos(alpha))/tan(alpha);}
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
	while(~scanf("%lf%lf%lf%lf",&y,&x,&l,&d))
		printf(Calc(Ternary(Pi/10,Pi/4))<=y?"yes\n":"no\n");
	return 0;
}