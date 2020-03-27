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
const int MAXN=300005;
int n,a[MAXN],dep[MAXN],L[MAXN],R[MAXN],u[MAXN],v[MAXN];
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
	for(ri i=1;i<=n;i++)L[i]=i-1,R[i]=i+1;
	for(ri i=n;i>=1;i--)
	{
		u[a[i]]=L[a[i]],v[a[i]]=R[a[i]];
		L[R[a[i]]]=L[a[i]],R[L[a[i]]]=R[a[i]];
	}
	for(ri i=1;i<=n;i++)
	{
		if(u[a[i]]>=1&&u[a[i]]<=n)
			dep[a[i]]=max(dep[a[i]],dep[u[a[i]]]+1);
		if(v[a[i]]>=1&&v[a[i]]<=n)
			dep[a[i]]=max(dep[a[i]],dep[v[a[i]]]+1);
		Ans+=dep[a[i]];
		printf("%lld\n",Ans);
	}
	return 0;
}

