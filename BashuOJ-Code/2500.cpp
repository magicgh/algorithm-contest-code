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
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
int n,m,x[10005],y[10005],t[10005],f[10005],Max;
int main()
{
	n=getint(),m=getint();
	for(ri i=1;i<=m;i++)t[i]=getint(),x[i]=getint(),y[i]=getint(),f[i]=1;
	for(ri i=2;i<=m;i++)
	{
		for(ri j=1;j<i;j++)
		if(f[j]+1>f[i]&&abs(x[i]-x[j])+abs(y[i]-y[j])<=t[i]-t[j])f[i]=f[j]+1;
		Max=max(Max,f[i]);
	}
	printf("%d",Max);
	return 0;
}

