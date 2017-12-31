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
const ll Mod=100000007ll;
ll n,m,k;
bool map[5005][5005];
inline const ll getll()
{
	ll num=0;int bj=1;
	char c=getchar();
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
	return ret%Mod;
}
int main()
{
	n=getll(),m=getll(),k=getll();
	ll Border=(n+1)/2,Block=(Border+1)*Border/2;
	if(m==0)printf("%lld\n",Pow(k,Block));
	else
	{
		for(ri i=1;i<=m;i++)
		{
			int x=getll()+1,y=getll()+1;
			if(x>Border)x=n+1-x;
			if(y>Border)y=n+1-y;
			if(x>y)swap(x,y);
			if(!map[x][y])
				map[x][y]=1,Block--;
		}
		printf("%lld\n",Pow(k,Block));
	}
	return 0;
}
