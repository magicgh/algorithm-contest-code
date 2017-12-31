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
const int MAXN=2005;
const int MAXC=305;
const int INF=0x7fffffff/2;
const double Limit=1e300;
int n,m,v,e;
int C[MAXN],D[MAXN];
double K[MAXN],f[MAXN][MAXN][2],Ans;
int map[MAXC][MAXC];
inline int min(const int &a,const int &b){return a<b?a:b;}
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
void Floyed()
{
	for(ri k=1;k<=v;k++)
		for(ri i=1;i<=v;i++)
			for(ri j=1;j<=v;j++)
				if(i!=j&&map[i][k]!=INF&&map[k][j]!=INF)
					map[i][j]=min(map[i][j],map[i][k]+map[k][j]);
}
void DP()
{
	for(ri i=1;i<=n;i++)
		for(ri j=0;j<=m;j++)f[i][j][0]=f[i][j][1]=Limit;
	f[1][0][0]=f[1][1][1]=0;
	for(ri i=2;i<=n;i++)
		for(ri j=0;j<=m&&j<=i;j++)
		{
			f[i][j][0]=min(f[i-1][j][0]+map[C[i-1]][C[i]],f[i-1][j][1]+K[i-1]*map[D[i-1]][C[i]]+(1-K[i-1])*map[C[i-1]][C[i]]);
			if(j)
				f[i][j][1]=min(f[i-1][j-1][0]+K[i]*map[C[i-1]][D[i]]+(1-K[i])*map[C[i-1]][C[i]],f[i-1][j-1][1]+K[i]*(K[i-1]*map[D[i-1]][D[i]]+(1-K[i-1])*map[C[i-1]][D[i]])+(1-K[i])*(K[i-1]*map[D[i-1]][C[i]]+(1-K[i-1])*map[C[i-1]][C[i]]));
		}
	Ans=f[n][0][0];
	for(ri i=1;i<=m&&i<=n;i++)
		Ans=min(Ans,min(f[n][i][0],f[n][i][1]));
	printf("%.2lf\n",Ans);
}
int main()
{
	n=getint(),m=getint(),v=getint(),e=getint();
	for(ri i=1;i<=v;i++)
		for(ri j=1;j<=v;j++)if(i!=j)map[i][j]=INF;
	for(ri i=1;i<=n;i++)C[i]=getint();
	for(ri i=1;i<=n;i++)D[i]=getint();
	for(ri i=1;i<=n;i++)scanf("%lf",K+i); 
	for(ri i=1;i<=e;i++)
	{
		int u=getint(),v=getint(),w=getint();
		if(u==v)continue;
		map[u][v]=map[v][u]=min(map[u][v],w);
	}
	Floyed(),DP();
	return 0;
}

