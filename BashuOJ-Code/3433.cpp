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
const int MAXN=100500;
const double PI=3.141592653589793238462643383279502884197169399375105;
struct credit{double x,y,theta;};
struct Point{double x,y;};
Point q[MAXN];	
credit card[MAXN];
int dx[5]={0,-1,-1,1,1},dy[5]={0,-1,1,-1,1},Ans[MAXN],s[MAXN]={0,1,2};;
double a,b,r;
int n,qcnt; 
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline double LineLen (const Point &a,const Point &b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
inline double Cross(const Point &a,const Point &b,const Point &c){return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);}
inline void ConvexHullLen(Point a[])
{
	double len=0;	
	Ans[++Ans[0]]=Ans[1];
	for(int i=2;i<=Ans[0];i++)
		len+=LineLen(a[Ans[i]],a[Ans[i-1]]);
	printf("%.2lf",len+2*PI*r);	
}
inline void GrahamScan(Point a[])
{
	s[0]=0,s[1]=1,s[2]=2; 
	int top=2;
	for(int i=3;i<=qcnt;i++)
	{
		while(top>1&&Cross(a[s[top-1]],a[s[top]],a[i])<=0)top--;
		s[++top]=i;
	}
	for(int i=1;i<=top;i++)Ans[++Ans[0]]=s[i];
	memset(s,0,sizeof(s));
	s[1]=qcnt,s[2]=qcnt-1,top=2;
	for(int i=qcnt-2;i>=1;i--)
	{
		while(top>1&&Cross(a[s[top-1]],a[s[top]],a[i])<=0)top--;
		s[++top]=i;
	}
	for(int i=2;i<top;i++)Ans[++Ans[0]]=s[i];
	ConvexHullLen(a);
}
inline bool cmp(const Point &a,const Point &b)
{
	return (a.y<b.y)||(a.y==b.y&&a.x<b.x); 
}
int main()
{
	n=getint();
	scanf("%lf%lf%lf",&a,&b,&r);
	a-=2*r,b-=2*r;
	for(ri i=1;i<=n;i++)
	{
		scanf("%lf%lf%lf",&card[i].x,&card[i].y,&card[i].theta);
		for(ri j=1;j<=4;j++)
		{
			double yy=a/2,xx=b/2;
			double sx=card[i].x+dx[j]*xx,sy=card[i].y+dy[j]*yy;
			double nx=(sx-card[i].x)*cos(card[i].theta)-(sy-card[i].y)*sin(card[i].theta)+card[i].x;
			double ny=(sx-card[i].x)*sin(card[i].theta)+(sy-card[i].y)*cos(card[i].theta)+card[i].y;
			q[++qcnt]=(Point){nx,ny};
		}
	}
	sort(q+1,q+qcnt+1,cmp);
	GrahamScan(q);
	return 0;
}

