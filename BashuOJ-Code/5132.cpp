#include<iostream>
#include<cstdio>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<queue>
#define ri register int
#define ll long long
using namespace std;
const ll Mod=1000007ll;
const int MAXN=10005;
int n,a[MAXN],Max[MAXN];
ll Ans,f[MAXN];
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
int main()
{
	n=GetInt();
	for(ri i=1;i<=n;i++)
	{
		a[i]=GetInt();
		Max[i]=max(Max[i-1],a[i]);
	}
	for(ri i=1;i<=n+1;i++)f[i]=1;
	for(ri i=n;i>=1;i--)
	{
		Ans=(Ans+(ll)f[Max[i-1]]*(ll)(a[i]-1)%Mod)%Mod;
		for(ri j=1;j<=n;j++)
			f[j]=(f[j]*(ll)j+f[j+1])%Mod;
	}
	printf("%lld\n",(Ans+1)%Mod);
	return 0;
}
