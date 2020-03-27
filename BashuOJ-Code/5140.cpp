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
const int MAXN=100005;
const int MAXP=670005;
const int Limit=100000;
int T;
bool vst[MAXN];
ll n,Ans,phi[MAXN],p[MAXN];
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
void Init()
{
	phi[1]=1;
	for(ll i=2;i<=Limit;i++)
	{
		if(!vst[i])p[++p[0]]=i,phi[i]=i-1;
		for(ri j=1;j<=p[0]&&i*p[j]<=Limit;j++)
		{
			vst[i*p[j]]=1;
			if(i%p[j]==0){phi[i*p[j]]=phi[i]*p[j];break;}
			phi[i*p[j]]=phi[i]*phi[p[j]];
		}
	}
}
inline ll Phi(ll x)
{
	if(x<=Limit)return phi[x];
	ll ret=x;
	for(ll i=2;i*i<=x;i++)
		if(x%i==0)
		{
			ret=ret/i*(i-1);
			while(x%i==0)x/=i;
		}
	if(x>1)ret=ret/x*(x-1);
	return ret;
}
int main()
{
	Init();
	T=GetInt();
	while(T--)
	{
		n=GetLL(),Ans=0;
		for(ll x=1;x*x<=n;x++)
		{
			if(n%x==0)
			{
				Ans+=(Phi(x)*x+1)/2;
				if(x*x!=n)Ans+=(Phi(n/x)*(n/x)+1)/2;
			}
		}
		printf("%lld\n",Ans);
	}
	return 0;
}


