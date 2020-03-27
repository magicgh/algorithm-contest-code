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
#define ll long long
using namespace std;
const int MAXN=105;
const int INF=0x7fffffff/2;
int n,m,map[MAXN][MAXN];
ll g[MAXN][MAXN];	
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void Floyed()
{
	for(ri k=1;k<=n;k++)
		for(ri i=1;i<=n;i++)
			for(ri j=1;j<=n;j++)
			{
				if(map[i][k]!=INF&&map[k][j]!=INF&&i!=j)
				{
					if(map[i][j]==map[i][k]+map[k][j])
						g[i][j]+=g[i][k]*g[k][j];
					else if(map[i][j]>map[i][k]+map[k][j])
					{
						map[i][j]=map[i][k]+map[k][j];
						g[i][j]=g[i][k]*g[k][j];
					}
				}
			}
}
inline double Getvalue(int u)
{
	double Ans=0;
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=n;j++)
		{
			if(i!=u&&j!=u&&map[i][u]!=INF&&map[u][j]!=INF&&i!=j&&map[i][u]+map[u][j]==map[i][j])
			Ans+=(double)(((double)g[i][u]*(double)g[u][j])/double(g[i][j]));
		}
	return Ans;
}
int main()
{
	n=getint(),m=getint();
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=n;j++)
			if(i!=j)map[i][j]=INF;
	for(ri i=1;i<=m;i++)
	{
		int u=getint(),v=getint(),w=getint();
		map[u][v]=map[v][u]=min(w,map[u][v]);
		g[u][v]=g[v][u]=1;
	}
	Floyed();
	for(int i=1;i<=n;i++)printf("%.3lf\n",Getvalue(i));
	return 0;
}

