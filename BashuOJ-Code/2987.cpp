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
int n,m,map[105][105];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
int main()
{
	n=getint(),m=getint();
	for(ri i=1;i<n;i++)
		for(ri j=i+1;j<=n;j++)if(i!=j)map[i][j]=map[j][i]=0x7fffffff/2;
	for(ri i=1;i<=m;i++)
	{
		int x=getint(),y=getint(),z=getint();
		map[x][y]=map[y][x]=z;
	}
	for(ri k=1;k<=n;k++)
		for(ri i=1;i<=n;i++)
			for(ri j=1;j<=n;j++)
				if(map[i][k]!=0x7fffffff/2&&map[k][j]!=0x7fffffff/2)
					map[i][j]=min(map[i][k]+map[k][j],map[i][j]);
	for(ri i=1;i<=n;i++)
	{
		for(ri j=1;j<=n;j++)
		printf("%d ",map[i][j]==0x7fffffff/2?0:map[i][j]);
		printf("\n");
	}
	return 0;
}
