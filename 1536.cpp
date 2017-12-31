#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<deque>
#include<stack>
#include<vector>
#define ri register int
using namespace std;
const int INF=0x7fffffff;
int T,n,m,cnt,s[10005],f[10005][2],g[10005][2];
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
	T=getint();
	while(T--)
	{
		int st=1;n=getint(),m=getint();
		for(ri i=1;i<=n;i++)s[i]=getint(),g[i][0]=g[i][1]=1;
		sort(s+1,s+n+1);g[n+1][0]=g[n+1][1]=n;
		for(ri i=1;i<=n;i++)f[i][0]=(s[i]-s[1])*(s[i]-s[1]);
		for(ri j=2;j<=m;j++,st^=1)
		{
			for(ri i=n;i>=j;i--)
			{
				f[i][st]=INF/2;
				for(ri k=g[i][st^1];k<=g[i+1][st];k++)
					if(f[i][st]>f[k-1][st^1]+(s[i]-s[k])*(s[i]-s[k]))f[i][st]=f[k-1][st^1]+(s[i]-s[k])*(s[i]-s[k]),g[i][st]=k;
			}
		}
		printf("Case %d: %d\n",++cnt,f[n][st^1]);
	}
	return 0;
}