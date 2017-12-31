#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<climits>
#include<vector>
#define ri register int
#define ll long long
using namespace std;
const int MAXN=205;
const int MAXS=(1<<12)+5;
const ll INF=LLONG_MAX/2;
ll map[MAXN][MAXN],f[MAXN][MAXS],Ans=INF;
int n,m,p,spe[MAXN];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline ll getll()
{
	ll num=0;int bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void DFS(int u,ll dist,int sta)
{
	if(f[u][sta]>dist)f[u][sta]=dist;//记忆化搜索
	else return;//剪枝
	if(sta==(1<<p)-1){Ans=min(Ans,dist+map[u][n]);return;}//全部特殊点外都访问过
	for(int i=1;i<=p;i++)
		if(!(sta&(1<<(i-1))))//第spe[i]点未访问 
			DFS(spe[i],dist+map[u][spe[i]],sta|(1<<(i-1))); 
}
inline bool Judge()
{
	if(map[1][n]==INF)return 0;
	for(ri i=1;i<=p;i++)if(map[1][spe[i]]==INF)return 0;
	return 1;
}
int main()
{
	n=getint(),m=getint();
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=n;j++)if(i!=j)map[i][j]=INF;
	for(ri i=1;i<=m;i++)
	{
		int x=getint(),y=getint();
		ll z=getll();
		if(x==y)continue;
		map[x][y]=map[y][x]=min(map[x][y],z);
	}
	p=getint();
	for(ri i=0;i<=n;i++)
		for(ri j=0;j<=(1<<p);j++)f[i][j]=INF;
	for(ri i=1;i<=p;i++)spe[i]=getint();
	for(ri k=1;k<=n;k++)
		for(ri i=1;i<=n;i++)
			for(ri j=1;j<=n;j++)
			if(map[i][k]!=INF&&map[k][j]!=INF)map[i][j]=min(map[i][j],map[i][k]+map[k][j]);
	if(!Judge()){printf("-1\n");return 0;}
	DFS(1,0,0);
	printf("%lld\n",Ans);
	return 0;
}

