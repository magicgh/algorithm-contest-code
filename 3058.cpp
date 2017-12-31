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
const int MAXN=2005;
int n,a[MAXN],s[MAXN],f[MAXN][2];
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
	for(ri i=1;i<=n;i++)
	{
		a[i]=getint();
		s[i]=s[i-1]+abs(a[i]-a[i-1]);
	}
	for(ri i=1;i<=n;i++)f[i][0]=f[i][1]=INF;
	f[n+1][0]=0,f[n+1][1]=INF;
	for(ri i=n;i>=1;i--)
	{
		a[n+1]=a[i];
		f[i][0]=min(f[i+1][0]+abs(a[i+1]-a[i]),f[i+1][1]+abs(a[i+2]-a[i]));
		for(ri j=i+1;j<=n;j++)
			f[i][1]=min(f[i][1],min(f[j+1][0]+abs(a[j+1]-a[i]),f[j+1][1]+abs(a[j+2]-a[i]))+abs(a[i]-a[j])+s[j]-s[i+1]);
	}
	printf("%d\n",min(f[1][0],f[1][1]));
	return 0;
}

