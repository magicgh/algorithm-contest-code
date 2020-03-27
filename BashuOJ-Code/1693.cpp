#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<vector>
#define ri register int 
using namespace std;
const int MAXN=105;
int n;
double a[MAXN][MAXN],Ans[MAXN];
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+c-'0',c=getchar();
	return num*bj;
}
inline void Gauss(int x)
{
	double Max=fabs(a[x][x]);
	int pos=x;
	for(ri i=x+1;i<=n;i++)
		if(fabs(a[i][x])>Max)
			Max=fabs(a[i][x]),pos=i;
	if(pos!=x)
	{
		for(ri i=x;i<=n+1;i++)
			swap(a[x][i],a[pos][i]);
	}
	for(ri i=x+1;i<=n;i++)
	{
		double t=a[i][x]/a[x][x];
		for(ri j=x;j<=n+1;j++)
			a[i][j]-=t*a[x][j];
	}				
} 
int main()
{
	n=GetInt();
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=n+1;j++)
			scanf("%lf",&a[i][j]);
	for(ri i=1;i<=n;i++)Gauss(i);
	for(ri i=n;i>=1;i--)
	{
		for(ri j=n;j>i;j--) 
			a[i][n+1]-=a[i][j]*Ans[j];
		Ans[i]=a[i][n+1]/a[i][i];
	}
	for(ri i=1;i<=n;i++)printf("%d ",(int)(Ans[i]+0.5));
	return 0;
}

