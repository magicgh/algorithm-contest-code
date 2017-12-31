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
const int MAXN=105;
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
	for(ri i=1;i<=n;i++)
	{
		f[i]=f[i-1]+a[i];
		for(ri j=0;j<=i-2;j++)
		f[i]=max(f[i],f[j]+(i-j)*abs(a[i]-a[j+1]));
	}
		printf("%d",f[n]);
	return 0;
}

