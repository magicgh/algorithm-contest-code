#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define ri register int
using namespace std;
int n,m;
int dist[5005],f[2005][5005],fs[2005][5005],d[5005][5005];
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
	for(ri i=1;i<=n;i++)dist[i]=getint();
	sort(dist+1,dist+n+1); 
	for(ri i=1;i<n;i++)
		for(ri j=i+1;j<=n;j++)d[i][j]=d[i][j-1]+dist[j]-dist[(i+j)>>1];
	for(ri i=1;i<=n;i++)f[1][i]=d[1][i],fs[1][i]=1;
	for(ri i=1;i<=m;i++)fs[i][n+1]=n-1;
	for(ri i=2;i<=m;i++)
	for(ri j=n;j>=i;j--)
	{
		f[i][j]=0x7fffffff/2;
	for(ri k=fs[i-1][j];k<=fs[i][j+1];k++)
		if(f[i][j]>f[i-1][k]+d[k+1][j])
		{
			f[i][j]=f[i-1][k]+d[k+1][j];
			fs[i][j]=k;
		}
	}
	printf("%d",f[m][n]);
	return 0;
}

