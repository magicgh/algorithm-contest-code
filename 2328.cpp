#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<vector>
#define ri register int
using namespace std;
const int INF=0x7fffffff;
struct Vector{int x,y;}p[105];
int n,f[105][105],ans=-INF;
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+c-'0',c=getchar();
	return num*bj;
}
inline int Cross(const Vector &a,const Vector &b,const Vector &c)
{
	return (a.x-c.x)*(b.y-c.y)-(b.x-c.x)*(a.y-c.y);
}
inline double dist(const Vector &a,const Vector &b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
inline bool cmp(const Vector &a,const Vector &b)
{
	int tmp=Cross(a,b,p[1]);
	if(tmp>0)return 1;
	else if(tmp==0)return dist(p[1],a)<dist(p[1],b);
	else return 0;
}
int main()
{
	n=getint();
	for(ri i=2;i<=n+1;i++)
	{
		int x=getint(),y=getint();
		p[i]=(Vector){x,y};
	}
	p[1]=(Vector){0,0};
	sort(p+2,p+n+2,cmp);//极角排列
	for(ri i=2;i<=n+1;i++)f[i][1]=2;
	for(ri i=3;i<=n+1;i++)
		for(ri j=2;j<=i-1;j++)
			for(ri k=1;k<=i-2;k++)
			{
				if(Cross(p[i],p[k],p[j])>0)f[i][j]=max(f[i][j],f[j][k]+1);
				ans=max(ans,f[i][j]);
			}
	printf("%d",ans);
	return 0;
}

