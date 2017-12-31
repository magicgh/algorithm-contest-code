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
const int MAXN=50;
const int Limit=44;
int T;
ll f[MAXN];
inline const int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline const ll GetLL()
{
	ll num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline void Init()
{
	f[0]=0ll,f[1]=1ll;
	for(ri i=2;i<=Limit;i++)
		f[i]=f[i-1]+f[i-2];
}
inline bool Check(ll x)
{
	if(x==0)return 1;
	for(ri i=1;i<=Limit;i++)
		for(ri j=1;j<=Limit;j++)
			if(f[i]*f[j]==x)return 1;
	return 0;
}
int main()
{
	Init();
	T=GetInt();
	while(T--)
		printf(Check(GetLL())?"Yes\n":"No\n");
	return 0;
}


