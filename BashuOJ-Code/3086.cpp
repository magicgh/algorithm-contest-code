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
const int MAXN=100005;
int n,Ans;
double a,b,d;
struct Point{double x,y,z;};
Point p[MAXN];
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline bool cmp(const Point &a,const Point &b){return a.z<b.z;}
int main()
{
	scanf("%lf%lf%lf%d",&a,&b,&d,&n);
	for(ri i=1;i<=n;i++)
	{
		scanf("%lf%lf",&p[i].x,&p[i].y);
		p[i].z=a*p[i].x+b*p[i].y;
	}
	d=d*sqrt(a*a+b*b);
	sort(p+1,p+n+1,cmp);
	int l=0,r=1;
	while(r+1<=n)
	{
		l++;
		while(p[r+1].z-p[l].z<=d*2&&r+1<=n)r++;
		Ans=max(Ans,r-l+1);
	}
	printf("%d\n",Ans);
	return 0;
}


