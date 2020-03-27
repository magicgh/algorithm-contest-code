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
const int MAXN=15;
ll a,b,f[MAXN][MAXN],Num[MAXN];
int len;
inline const ll GetLL()
{
	ll num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
ll DP(int d,int last,bool flag)
{
	if(!d)return 1;
	if(!flag&&f[d][last]!=-1)return f[d][last];
	ll Ans=0,k=(flag)?Num[d]:9;
	for(ri i=0;i<=k;i++)
	{
		if(i==4||(last==3&&i==7))continue;
		Ans+=DP(d-1,i,flag&&(i==k));
	}
	if(!flag)f[d][last]=Ans;
	return Ans;
}
inline ll Solve(ll x)
{
	len=0;
	while(x)
	{
		Num[++len]=x%10;
		x/=10;
	}
	return DP(len,0,1);
}
int main()
{
	a=GetLL(),b=GetLL();
	memset(f,-1,sizeof(f));
	printf("%lld\n",Solve(b)-Solve(a-1));
	return 0;
}


