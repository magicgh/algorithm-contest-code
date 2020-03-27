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
ll a,b,ans;
ll lucky[2050],luck[2050];
bool vst[2050];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void Init(ll x)
{
	if(x>b)return;
	if(x>0)lucky[++lucky[0]]=x;
	Init(x*10+6);
	Init(x*10+8);
}
void Rongchi(ll cnt,ll limit,ll k,ll lcm)
{
	ll tmp; 
	for(ll i=cnt;i>=1;i--)
	{
		tmp=lcm/__gcd(lcm,luck[i])*luck[i];//求新的LCM
		if(tmp>0&&tmp<=limit)
		{
			ans=ans+(limit/tmp)*k;//容斥原理，容斥容斥 
			Rongchi(i-1,limit,-k,tmp);
		} 
	} 
}
ll Solve(ll x)
{
	if(x<=5)return 0;
	ans=0;
	Rongchi(luck[0],x,1,1);
	return ans;
}
int main()
{
	scanf("%lld%lld",&a,&b);
	Init(0);
	sort(lucky+1,lucky+lucky[0]+1);//排序 
	for(ri i=1;i<=lucky[0];i++)
	{
		if(vst[i])continue;
		for(ri j=i+1;j<=lucky[0];j++)if(lucky[j]%lucky[i]==0)vst[j]=1;//去倍数 
	}
	for(ri i=1;i<=lucky[0];i++)if(!vst[i])luck[++luck[0]]=lucky[i];
	printf("%lld",Solve(b)-Solve(a-1)); 
	return 0;
}

