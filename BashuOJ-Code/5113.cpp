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
const ll Mod=1000000007ll;
ll n,m,t_m,Ans,p[1000005];
inline const ll GetLL()
{
	ll num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
void Init()
{
	const ll Limit=sqrt(m);
	for(ll i=2;i<=Limit;i++)
	{
		if(t_m%i==0)
		{
			p[++p[0]]=i;
			while(t_m%i==0)t_m/=i;
		}
	}
	if(t_m>1)p[++p[0]]=t_m;
}
inline ll Pow(ll a,ll b)
{
	ll ret=1,base=a%Mod;
	while(b)
	{
		if(b&1)ret=(ret*base)%Mod;
		base=(base*base)%Mod;
		b>>=1;
	}
	return ret;
}
void DFS(int tot,ll mul,ll rc)
{
	if(tot>p[0])
	{
		Ans=((Ans+Pow(m/mul,n)*rc)%Mod+Mod)%Mod;
		return;
	}
	DFS(tot+1,mul,rc);
	DFS(tot+1,mul*p[tot],-rc);
}
int main()
{
	n=GetLL(),m=t_m=GetLL();
	Init();
	DFS(1,1ll,1ll);
	printf("%lld\n",Ans);
	return 0;
}
