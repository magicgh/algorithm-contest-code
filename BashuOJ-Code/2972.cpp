#include<iostream>
#include<cstdio>
#include<cmath>
#define ri register int
using namespace std;
const int INF=0x7fffffff/2;
const int MAXN=201;
int n,m,q,pre=1;
int t[MAXN],map[MAXN][MAXN];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline void Floyed(int T)
{
	ri i,j,k;
	for(k=pre;t[k]<=T&&k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(map[i][k]!=INF&&map[k][j]!=INF)map[i][j]=min(map[i][j],map[i][k]+map[k][j]);
	pre=k;
}
int main()
{
	n=getint(),m=getint();
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=n;j++)
			if(i!=j)map[i][j]=INF;
	for(ri i=1;i<=n;i++)t[i]=getint();
	for(ri i=1;i<=m;i++)
	{
		int x=getint()+1,y=getint()+1,z=getint();
		map[x][y]=map[y][x]=z;
	}
	q=getint();
	for(ri i=1;i<=q;i++)
	{
		int x=getint()+1,y=getint()+1,z=getint();
		if(t[x]>z||t[y]>z){printf("-1\n");continue;}
		Floyed(z);
		printf("%d\n",map[x][y]==INF?-1:map[x][y]);
	}
	return 0;
}
