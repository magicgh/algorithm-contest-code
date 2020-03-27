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
const double eps=1e-8;
const int INF=0x7fffffff/2;
struct Point{double x,y;};
int T,n,m;
int f[(1<<18)+5],g[20][20];
Point p[20];
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline bool Check(const double &x){return fabs(x)<=eps;}
int main()
{
	T=getint();
	while(T--)
	{
		n=getint(),m=getint();
		for(ri i=1;i<=n;i++)
			scanf("%lf%lf",&p[i].x,&p[i].y);
		for(ri i=1;i<n;i++)
			for(ri j=i+1;j<=n;j++)
			{
				g[i][j]=0;
				if(Check(p[i].x-p[j].x))continue;
				double a=(p[i].y/p[i].x-p[j].y/p[j].x)/(p[i].x-p[j].x);
				double b=p[i].y/p[i].x-a*p[i].x;
				if(a>=-eps)continue;
				for(ri k=1;k<=n;k++)
					if(Check(a*p[k].x*p[k].x+b*p[k].x-p[k].y))
						g[i][j]|=(1<<(k-1));
			}
		for(ri s=1;s<(1<<n);s++)f[s]=INF;
		for(ri s=0;s<(1<<n);s++)
		{
			for(ri i=1;i<=n;i++)
			{
				if(!(s&(1<<(i-1))))
				{
					f[s|(1<<(i-1))]=min(f[s|(1<<(i-1))],f[s]+1); 
					for(ri j=i+1;j<=n;j++)
						f[s|g[i][j]]=min(f[s|g[i][j]],f[s]+1);
				}
			}
		}
		printf("%d\n",f[(1<<n)-1]);
	}
	return 0;
}

