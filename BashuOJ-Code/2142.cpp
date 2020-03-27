#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#define ri register int
#define ll long long
using namespace std;
const int MAXN=10005;
const double INF=1e18;
struct Point{double x,y;};
Point p[MAXN];
double Minx=INF,Miny=INF;
int Stack[MAXN];
int n,k,top;
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline double Cross(const Point &a,const Point &b,const Point &c)
{
	return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}
inline double Sqr(double x){return x*x;}
inline double Dist( Point a, Point b)
{
	return sqrt(Sqr(a.x-b.x)+Sqr(a.y-b.y));
}
inline bool cmp(const Point &a,const Point &b)
{
	double tmp=Cross(p[1],a,b);
	if(tmp>0)return 1;
	else if(tmp==0)return Dist(p[1],a)<Dist(p[1],b);
	else return 0;
}
int main()
{
	n=GetInt();
	for(ri i=1;i<=n;i++)
	{
		scanf("%lf %lf",&p[i].x,&p[i].y);
		if((p[i].y<Miny)||(p[i].y==Miny&&p[i].x<Minx))
			Minx=p[i].x,Miny=p[i].y,k=i;
	}
	swap(p[1],p[k]);
	sort(p+2,p+n+1,cmp);
	Stack[1]=1,Stack[2]=2,top=2;
	for(ri i=3;i<=n;i++)
	{
		while(top>1&&Cross(p[Stack[top-1]],p[Stack[top]],p[i])<=0)top--;
		Stack[++top]=i;
	}
	double ret=0;
	Stack[++top]=Stack[1];
	for(ri i=2;i<=top;i++)
		ret+=Dist(p[Stack[i-1]],p[Stack[i]]);
	printf("%.2lf",ret);
	return 0;
}