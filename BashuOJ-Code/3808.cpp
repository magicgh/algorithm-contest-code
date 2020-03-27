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
const double eps=1e-8;
struct Point{double x,r;};
struct Segment{double x,y;};
Segment b[10]; 
Point a[10];
double h,x0;
inline bool cmp(Segment a,Segment b){return (a.x==b.x&&a.y>b.y)||(a.x<b.x);}
inline double Sqr(const double &a){return a*a;}
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline bool Check(double Limit)
{
	for(ri i=1;i<=7;i++)
	{
		double R=a[i].r+Limit,len;
		if(h<=R)len=sqrt(Sqr(R)-Sqr(h));
		else len=0;
		b[i]=(Segment){a[i].x-len,a[i].x+len};
	}
	sort(b+1,b+8,cmp);//区间覆盖贪心
	double Max=b[1].y;
	if(b[1].x>0)return 0;
	for(ri i=2;i<=7;i++)
	 	if(Max>=b[i].x&&Max<=b[i].y)Max=b[i].y;
	return (Max+eps>=x0);
}
void Binary()
{
	double l=0.0,r=10000.0;
	while(fabs(l-r)>eps)
	{
		double mid=(l+r)/2.0;
		if(Check(mid))r=mid;
		else l=mid;
	}
	printf("%.2lf",l);
}
int main()
{
	scanf("%lf%lf",&h,&x0);
	for(ri i=1;i<=7;i++)
		scanf("%lf%lf",&a[i].x,&a[i].r);
	Binary();
	return 0;
}

