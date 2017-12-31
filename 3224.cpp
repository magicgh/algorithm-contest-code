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
long long n,ans;
int m;
inline long long getll()
{
	long long num=0;
	int bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline long long phi(long long x)
{
	long long ans=x;
	for(int i=2;i<=sqrt(n);i++)
	{
		if(x%i==0)
		{
			ans=(ans/i)*(i-1);
			while(x%i==0)x/=i;
		}
	}
	if(x>1)ans=(ans/x)*(x-1);
	return ans;
}
int main()
{
	n=getll();
	for(int i=1;i<=sqrt(n);i++)
	{
		if(n%i==0)
		{
			ans+=(long long)i*phi(n/i);
			if(i*i<n)ans+=(long long)(n/i)*phi(i);
		}
	}
	printf("%lld",ans);
	return 0;
}

