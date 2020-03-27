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
int T;
ll A,N;
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
inline ll mod(ll a,ll b,ll Mod){return (a*b<Mod)?a*b:a*b%Mod;}
inline ll Pow(ll a,ll b,ll Mod)
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
inline int Solve()
{
	if(A&1)return 1;
	int Ans=0;
	ll Mod=(1<<N);
	for(ll i=2;i<=N;i+=2)
		if(Pow(A,i,Mod)==Pow(i,A,Mod))Ans++;
	int Len=(N+A-1)/A;
	return Ans+((1<<N)>>Len)-(N>>Len);
}
int main()
{
	T=GetInt();
	while(T--)
	{
		A=GetLL(),N=GetLL();
		printf("%d\n",Solve());
	}
	return 0;
}

