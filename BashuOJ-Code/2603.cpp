#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<vector>
using namespace std;
struct point
{
	int x,y,w;
}a[50005];
int n,sum;
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+c-'0',c=getchar();
	return num*bj;
}
inline bool cmp_x(const point &a,const point &b){return a.x<b.x;}
inline bool cmp_y(const point &a,const point &b){return a.y<b.y;}
int main()
{
	n=getint();
	for(int i=1;i<=n;i++)a[i].w=getint(),sum+=a[i].w;
	for(int i=1;i<=n;i++)a[i].x=getint(),a[i].y=getint();
	int ans=0,i,ax=0,ay=0; 
	sort(a+1,a+n+1,cmp_x);
	for(i=1;i<=n;i++)
	{
		ans+=a[i].w;
		if(ans>sum/2)break;
	}
	ax=a[i].x;
	sort(a+1,a+n+1,cmp_y);ans=0;
	for(i=1;i<=n;i++)
	{
		ans+=a[i].w;
		if(ans>sum/2)break;
	}
	ay=a[i].y;
	double answer=0;
	for(i=1;i<=n;i++)
		answer+=a[i].w*(abs(ax-a[i].x)+abs(ay-a[i].y));
	printf("%.2f",answer);
	return 0;
}

