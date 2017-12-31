#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#include<iomanip>
#include<queue>
#include<set>
#include<vector>
#define ri register int
using namespace std;
const int MAXN=1005;
const double INF=1e18;
struct Point{int x,y;};
Point p[MAXN];
double f[MAXN][MAXN];
int n,b1,b2;
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline double Sqr(double x)
{
	return x*x;
}
inline double GetDist(const Point &a,const Point &b)
{
	return sqrt(Sqr((double)(a.x-b.x))+Sqr((double)(a.y-b.y)));
}
int main()
{
	n=GetInt(),b1=GetInt()+1,b2=GetInt()+1;
	for(ri i=1;i<=n;i++)
	{
		int u=GetInt(),v=GetInt();
		p[i]=(Point){u,v};
	}
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=n;j++)f[i][j]=INF;
	f[1][1]=0;
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=n;j++)
		{
			int k=max(i,j);
			if(k==n)
			{
				if(i!=n&&i!=b2)
					f[n][n]=min(f[n][n],f[i][j]+GetDist(p[i],p[n]));
				if(j!=n&&j!=b1)
					f[n][n]=min(f[n][n],f[i][j]+GetDist(p[j],p[n]));
			}
			else
			{
				k++;
				if(i!=b2)f[k][j]=min(f[k][j],f[i][j]+GetDist(p[k],p[i]));
				if(j!=b1)f[i][k]=min(f[i][k],f[i][j]+GetDist(p[k],p[j]));
			}
		}
	printf("%.2lf",f[n][n]);
	return 0;
}

