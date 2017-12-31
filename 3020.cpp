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
int h[55],g[55],s[55];
int n,totalfood;
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline bool Check(int k)
{
	int sum=0;
	for(ri i=1;i<=n;i++)s[i]=h[i]+g[i]*(k-1);
	sort(s+1,s+n+1);
	for(ri i=1;i<=k;i++)sum+=s[i];
	return sum<=totalfood;
}
int Binary()
{
	int l=0,r=n;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(Check(mid))l=mid+1;
		else r=mid-1;
	}
	return l-1;
}
int main()
{
	n=getint(),totalfood=getint();
	for(ri i=1;i<=n;i++)h[i]=getint();
	for(ri i=1;i<=n;i++)g[i]=getint();
	printf("%d",Binary());
	return 0;
}

