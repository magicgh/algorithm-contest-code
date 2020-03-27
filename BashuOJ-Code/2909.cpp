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
const int INF=0x7fffffff;
struct map{int x,y,val;}a[2505];
int n;
long long f[2505];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline bool cmp(const map &x,const map &y){return x.val>y.val;}
inline long long calc(int i,int j)
{
	return (abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y))*(abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y));
}
int main()
{
	n=getint();
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=n;j++)a[(i-1)*n+j]=(map){i,j,getint()};
	sort(a+1,a+n*n+1,cmp);
	for(ri i=2;i<=n*n;i++)
		for(ri j=1;j<i;j++)f[i]=max(f[i],f[j]+calc(i,j));
		printf("%lld",f[n*n]);
	return 0;
}
