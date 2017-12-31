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
}a[105];
int n;
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
	int x,y,w,i,sum=0,ans=0;
	for(i=1;i<=n;i++)
		{
		 	x=getint(),y=getint(),w=getint();
			a[i]=(point){x,y,w};
			sum+=w;
		} 
	sort(a+1,a+n+1,cmp_x);
	for(i=1;i<=n;i++)
	{
		ans+=a[i].w;
		if(ans>sum/2)break;
	}
	printf("%d ",a[i].x);ans=0;
	sort(a+1,a+n+1,cmp_y);
	for(i=1;i<=n;i++)
	{
		ans+=a[i].w;
		if(ans>sum/2)break;
	}
	printf("%d",a[i].y);
	return 0;
}

