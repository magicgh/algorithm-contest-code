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
int n,a[MAXN];
ll Ans;
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
	for(ri i=1;i<=n;i++)a[i]=getint();
	for(ri i=2;i<n;i++)
	{
		if(a[i]>a[i-1]&&a[i]>a[i+1])
		{
			Ans+=min(abs(a[i]-a[i-1]),abs(a[i+1]-a[i]));
			a[i]=max(a[i-1],a[i+1]);
		}
		if(a[i]<a[i-1]&&a[i]<a[i+1])
		{
			Ans+=min(abs(a[i]-a[i-1]),abs(a[i+1]-a[i]));
			a[i]=min(a[i-1],a[i+1]);
		}
	}
	for(ri i=1;i<n;i++)Ans+=abs(a[i+1]-a[i]);
	printf("%lld\n",Ans);
	return 0;
}

