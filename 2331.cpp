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
struct part{int l,w;}a[1005];
int n,f[1005];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline bool cmp(const part &a,const part &b)
{
	return (a.l==b.l&&a.w<b.w)||(a.l<b.l);
}
int main()
{
	n=getint();
	for(ri i=1;i<=n;++i)
	{
		int l=getint(),w=getint();
		a[i]=(part){l,w};f[i]=1;
	}
	sort(a+1,a+n+1,cmp);
	for(ri i=2;i<=n;i++)
	for(ri j=1;j<i;j++)
		if(a[j].w>a[i].w&&f[j]+1>f[i])f[i]=f[j]+1;
	int Max=-0x7fffffff;
	for(ri i=1;i<=n;i++)Max=max(Max,f[i]);
	printf("%d",Max);
	return 0;
}

