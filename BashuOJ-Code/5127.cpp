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
const int MAXN=65;
const int INF=0x7fffffff/2;
int n;
ll f[MAXN],s[MAXN];
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
void MakeFib()
{
	f[0]=f[1]=1;
	for(ri i=2;i<=59;i++)
		f[i]=f[i-1]+f[i-2];
}
inline ll Climb(ll u,ll v)
{
	for(ri i=59;i>=1;i--)
	{
		if(u-f[i]>0)u-=f[i];
		if(v-f[i]>0)v-=f[i];
		if(u==v)return u;
	}
	return 1;
}
int main()
{
	n=GetInt();
	MakeFib();
	for(ri i=1;i<=n;i++)
	{
		ll u=GetLL(),v=GetLL();
		if(u==v){printf("%lld\n",u);continue;}
		printf("%lld\n",Climb(u,v));
	}
	return 0;
}


