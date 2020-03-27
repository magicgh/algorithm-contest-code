#include<iostream>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<queue>
#include<stack>
#define ri register int
#define ll long long
using namespace std;
const int MAXN=5000005;
const ll Mod=100000007;
bool vst[MAXN];
ll n,Ans=1,p[420000];
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(bj==-1||c=='-')?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline ll GetLL()
{
	ll num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(bj==-1||c=='-')?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline ll Pow(ll a,ll b)
{
	ll ret=1,base=a;
	while(b)
	{
		if(b&1)ret=ret*base%Mod;
		base=base*base%Mod;
		b>>=1;
	}
	return ret;
}
void Init()
{
	for(ll i=2;i<=n;i++)
	{
		if(!vst[i])p[++p[0]]=i;
		for(ri j=1;j<=p[0]&&i*p[j]<=n;j++)
		{
			vst[i*p[j]]=1;
			if(i%p[j]==0)break;
		}
	}
}
int main()
{
	n=GetLL();
	Init();
	for(ri i=1;i<=p[0];i++)
	{
		ll x=n,cnt=0;
		while(x>=p[i])
			cnt+=x/p[i],x/=p[i];
		Ans=Ans*Pow(p[i],(cnt&1)?cnt-1:cnt)%Mod;
	}
	printf("%lld\n",Ans%Mod);
	return 0;
}
