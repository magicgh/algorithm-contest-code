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
const int Limit=162005;
ll T,sum[Limit];
inline ll getint()
{
	ll num=0;int bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void Init()
{
	for(ll x=1;x<=162000;x++)
	{
		ll num=x; 
		while(num)
		{
			sum[x]+=num%10;
			num/=10;
		} 
	}
}
int main()
{
	Init();
	T=getint();
	while(T--)
	{
		ll l=getint(),r=getint(),k=getint(),cnt=0;
		if(l>162000){printf("0\n");continue;}
		if(r>162000)r=162000;
		for(ll i=l;i<=r;i++)if(sum[i]*k%i==0)cnt++;
		printf("%lld\n",cnt);
	}
	return 0;
}

