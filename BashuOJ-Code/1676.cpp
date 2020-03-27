#include<cstdio>
#include<cmath>
#include<algorithm>
#define ri register int
using namespace std;
struct node{int x,y;}a[1005];
double f[1005][1005],ans=1e100;int n;
inline bool cmp(const node &a,const node &b){return a.x<b.x;}
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline double dis(node a,node b){return sqrt((double)(a.x-b.x)*(a.x-b.x)+(double)(a.y-b.y)*(a.y-b.y));}
int main()
{
	n=getint();
	for(ri i=1;i<=n;i++)a[i].x=getint(),a[i].y=getint();
	sort(a+1,a+n+1,cmp);
	for(ri i=0;i<=n;i++)
		for(ri j=0;j<=n;j++)f[i][j]=1e100;
	f[2][1]=dis(a[2],a[1]);
	for(ri i=3;i<=n;i++)
	{
		for(ri j=1;j<=i-2;j++)f[i][j]=f[i-1][j]+dis(a[i-1],a[i]);
		for(ri j=1;j<=i-2;j++)f[i][i-1]=min(f[i][i-1],f[i-1][j]+dis(a[j],a[i]));
	}
	for(ri i=1;i<=n;i++)ans=min(ans,f[n][i]+dis(a[n],a[i]));
	printf("%.2lf",ans);
	return 0;
}

