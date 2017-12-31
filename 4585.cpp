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
const int INF=0x7fffffff/2;
int n,dist[205][205],f[205];
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
	n=getint();
	for(ri i=1;i<n;i++)
		for(ri j=i+1;j<=n;j++)dist[i][j]=dist[j][i]=getint();
	for(ri i=2;i<=n;i++)f[i]=INF;
	f[1]=0;
	for(ri i=2;i<=n;i++)
		for(ri j=1;j<i;j++)f[i]=min(f[i],f[j]+dist[i][j]);
	printf("%d",f[n]);
	return 0;
}

