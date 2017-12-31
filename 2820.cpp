#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define ri register int
#define ll long long
using namespace std;
const int MAXN=1005;
struct Sue{int x,y,v;};
Sue a[MAXN];
int sum[MAXN],w[MAXN][MAXN],f1[MAXN][MAXN],f2[MAXN][MAXN];
int N,x0;
inline bool cmp(const Sue &a,const Sue &b){return a.x<b.x;}
inline const int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
int main()
{
	N=GetInt(),x0=GetInt();
	for(ri i=1;i<=N;i++)a[i].x=GetInt();
	for(ri i=1;i<=N;i++)a[i].y=GetInt();
	for(ri i=1;i<=N;i++)a[i].v=GetInt();
	sort(a+1,a+N+1,cmp);
	for(ri i=1;i<=N;i++)sum[i]=sum[i-1]+a[i].v;
	for(ri i=1;i<=N;i++)
		for(ri j=1;j<=N;j++)
			w[i][j]=sum[N]-abs(sum[j]-sum[i-1]);
	for(ri i=1;i<=N;i++)
		f1[i][i]=f2[i][i]=a[i].y-sum[N]*abs(a[i].x-x0);
	for(ri len=2;len<=N;len++)
	{
		for(ri i=1;i+len-1<=N;i++)
		{
			ri j=i+len-1;
			f1[i][j]=a[i].y+max(f1[i+1][j]-w[i+1][j]*abs(a[i+1].x-a[i].x),f2[i+1][j]-w[i+1][j]*abs(a[j].x-a[i].x));
			f2[i][j]=a[j].y+max(f2[i][j-1]-w[i][j-1]*abs(a[j].x-a[j-1].x),f1[i][j-1]-w[i][j-1]*abs(a[j].x-a[i].x));
		}
	}
	printf("%.3lf",max(f1[1][N],f2[1][N])/1000.000);
	return 0;
}

