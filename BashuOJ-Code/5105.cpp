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
ll N,M,K,Base,Mod;
inline const ll GetLL()
{
	int num=0,bj=1;
	ll c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline ll Pow(ll a,ll b)
{
	ll ret=1,base=a;
	while(b)
	{
		if(b&1)ret=(ret*base)%Mod;
		base=(base*base)%Mod;
		b>>=1;
	}
	return ret;
}
int main()
{
	N=GetLL(),M=GetLL(),K=GetLL(),Mod=N+M,Base=Pow(2,K);
	printf("%lld\n",min(N*Base%Mod,M*Base%Mod));
	return 0;
}