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
#define gcd __gcd 
using namespace std;
const int MAXN=205;
int n,m;
ll sum,Max,Gcd;
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
	n=getint();
	for(ri i=1;i<=n;i++)
	{
		m=getint(),sum=0;
		for(ri j=1;j<m;j++)
			sum+=getll();
		ll x=getll();
		Max=max(x,Max);
		sum-=x;
		if(!Gcd)Gcd=sum;
		else Gcd=gcd(Gcd,sum);
	}
	if(Max<Gcd)printf("%lld\n",Gcd);
	else printf("-1\n");
	return 0;
}

