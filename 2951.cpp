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
const int MAXN=100005;
int n,a[MAXN],f[MAXN];
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
	for(ri i=1;i<=n;i++)a[i]=getint();
	sort(a+1,a+n+1);
	f[1]=a[1],f[2]=a[2];
	for(ri i=3;i<=n;i++)
	f[i]=min(f[i-1]+a[1]+a[i],f[i-2]+a[1]+a[i]+2*a[2]);
	printf("%d",f[n]);
	return 0;
}

