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
const int MAXN=1005;
int n,Ans,cnt,c[MAXN][MAXN],d[MAXN];
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
int main()
{
	n=getint();
	for(ri i=1;i<=n;i++)
		c[1][i]=getint();
	for(ri i=1;i<=n;i++)
		d[i]=getint();
	for(ri i=1;i<=n;i++)
		for(ri j=2;j<=n;j++)
			c[j][i]=c[j-1][i]-d[i];
	for(ri i=1;i<=n;i++)
	{
		sort(c[i]+1,c[i]+n+1,greater<int>());
		int sum=0;
		for(ri j=1;j<=i;j++)
			sum+=c[i][j];
		if(sum>=Ans)Ans=sum,cnt=i;
	}
	printf("%d\n%d\n",Ans,cnt);
	return 0;
}


