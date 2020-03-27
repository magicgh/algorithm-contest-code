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
const int MAXN=1505;
struct Point
{
	double x,y,k;
	Point(double x=0,double y=0):x(x),y(y){};
	Point operator -(Point a)
	const{return Point(x-a.x,y-a.y);} 
};
Point H[MAXN],P[MAXN];
ll A,B,n;
double Ans;
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline bool cmp(const Point &a,const Point &b){return a.k<b.k;}
inline double Azimuth(const Point &a){return atan2(a.y,a.x);}
inline double Cross(const Point &a,const Point &b){return a.x*b.y-a.y*b.x;}
inline ll Calc(int x)
{
	ll cnt=0,tot=(n-1)*(n-2)*(n-3)/6;
	int top=0;
	for(ri i=1;i<=n;i++)
	{
		if(i!=x)P[++top]=H[i];
		else P[0]=H[i];
	}
	for(ri i=1;i<=top;i++)
		P[i].k=Azimuth(P[i]-P[0]);	
	sort(P+1,P+top+1,cmp);//极角排序
	for(int i=1,j=2;i<=top;i++,cnt--)//双指针 
	{
		while(Cross((P[i]-P[0]),(P[j]-P[0]))>=0)
		{
			j=j%top+1,cnt++;
			if(i==j)break;
		}
		tot-=cnt*(cnt-1)/2;
	} 
	return tot;
}
int main()
{
	scanf("%lld",&n);
	if(n==3){printf("3.000000\n");return 0;}//对于三个点构成的三角形可以互相覆盖 
	for(ri i=1;i<=n;i++)
		scanf("%lf%lf",&H[i].x,&H[i].y);
	for(int i=1;i<=n;i++)B+=Calc(i);
	A=n*(n-1)*(n-2)*(n-3)/24-B;
	printf("%.6lf\n",(double)(2*A+B)/(double)(n*(n-1)*(n-2)/6)+3);	
	return 0;
}

