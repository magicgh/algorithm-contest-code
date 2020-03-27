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
const int MAXN=105;
const ll INF=1e18;
const ll Mod=998244353ll;
ll C[MAXN][MAXN],S[MAXN],Ans=1;
int n,m,t,s,List[MAXN];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
void Init()
{
	int Limit=100;
	for(ri i=1;i<=Limit;i++)
	{
		C[i][0]=C[i][i]=1;
		for(ri j=1;j<i;j++)
		C[i][j]=C[i-1][j-1]+C[i-1][j];	
	}
	for(ri i=1;i<=Limit;i++)
		for(ri j=1;j<=i;j++)
			S[i]=(S[i]+C[i][j])%Mod;
}
inline ll Pow(ll base,int b)
{
	ll ret=1;
	while(b)
	{
		if(b&1)ret=(ret%Mod*base%Mod)%Mod;
		base=(base%Mod*base%Mod)%Mod;
		b>>=1;
	}
	return ret%Mod;
}
inline ll Solve()
{
	int x=0,zero=0,one=0;
	for(ri i=1;i<=m;i++)
	{
		if(List[i]==0)zero++;
		if(List[i]==1)one++;
		if(List[i]==2)x++;
	}
	if(t==0&&s==0)
	{
		if(!x)
		{
			if(zero)return 1;
			else return 0;
		}
		else if(!zero)return S[x];
		else return Pow(2ll,x);
	}
	if(t==0&&s==1)
	{
		if(!x)
		{
			if(one==m)return 1;
			else return 0;
		}
		else if(zero)return 0;
		else return 1;
	}
	if(t==1&&s==0)
	{
		if(!x)
		{
			if(zero==m)return 1;
			else return 0;
		}
		else if(one)return 0;
		else return 1;
	}
	if(t==1&&s==1)
	{
		if(!x)
		{
			if(one)return 1;
			else return 0;
		}
		else if(!one)return S[x];
		else return Pow(2ll,x);
	}
}
int main()
{
	Init();
	n=getint(),m=getint();
	for(ri i=1;i<=n;i++)
	{
		for(ri j=1;j<=m;j++)
		List[j]=getint();
		t=getint(),s=getint();
		Ans=(Ans%Mod*Solve()%Mod)%Mod;
	}
	printf("%lld\n",Ans);
	return 0;
}

