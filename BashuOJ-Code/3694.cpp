#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define ri register int
#define ll long long
using namespace std;
const int MAXN=100005;
int n,m;
ll Ans,a[MAXN],b[MAXN];
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline const ll getll()
{
	ll num=0;int bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
int main()
{
	n=getint(),m=getint();
	for(ri i=1;i<=n;i++)
	{
		a[i]=getll(),b[i]=getll();
		Ans+=abs(a[i]-b[i]);
	}
	a[n+1]=m,b[n+1]=0;
	sort(a+1,a+n+2);
	sort(b+1,b+n+2);
	for(ri i=1;i<=n+1;i++)
		Ans+=abs(a[i]-b[i]);
	printf("%lld\n",Ans);
	return 0;
}


