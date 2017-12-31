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
int v,n,a[30];
long long f[10005];
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
	v=getint(),n=getint();
	for(ri i=1;i<=v;i++)a[i]=getint();
	f[0]=1;
	for(ri i=1;i<=v;i++)
		for(ri j=a[i];j<=n;j++)if(f[j-a[i]])f[j]+=f[j-a[i]];
	printf("%lld",f[n]);
	return 0;
}

