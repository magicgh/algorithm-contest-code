#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
struct point
{
	int x,y,num;
}p[100005];
int n,d[100005][4],dist[100005],ans=0x7fffffff;
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
	for(int i=1;i<=n;i++)
	{
		int x=getint(),y=getint();
		p[i]=(point){x,y,i};
	}
	sort(p+1,p+n+1,cmp_x);
	for(int i=1;i<=n;i++)d[i][0]=d[i-1][0]+i*(p[i].x-p[i-1].x);
	for(int i=n;i>=1;i--)d[i][1]=d[i+1][1]+(n-i+1)*(p[i+1].x-p[i].x);
	for(int i=1;i<=n;i++)dist[p[i].num]+=d[i][0]+d[i][1];
	sort(p+1,p+n+1,cmp_y);
	for(int i=1;i<=n;i++)d[i][2]=d[i-1][2]+i*(p[i].y-p[i-1].y);
	for(int i=n;i>=1;i--)d[i][3]=d[i+1][3]+(n-i+1)*(p[i+1].y-p[i].y);
	for(int i=1;i<=n;i++)
		ans=min(ans,dist[p[i].num]+d[i][2]+d[i][3]);
	printf("%d",ans);
	return 0;
}

