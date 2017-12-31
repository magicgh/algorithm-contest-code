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
const ll MAXN=10000005;
bool vst[MAXN];
ll p[MAXN],g[MAXN],Ans;
ll n,m,q,Next;
inline const ll getint()
{
	ll num=0;int bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
void Init()
{
	static const ll Limit=10000000;
	g[1]=1;
	for(ll i=2;i<=Limit;i++)
	{
		if(!vst[i])p[++p[0]]=i,g[i]=i-1;
		for(ll j=1;j<=p[0]&&i*p[j]<=Limit;j++)
		{
			vst[i*p[j]]=1;
			if(i%p[j]==0)
			{
				if(i%(p[j]*p[j])==0)g[i*p[j]]=0;
				else g[i*p[j]]=-g[i]/(p[j]-1)*p[j];
				break;
			}
			g[i*p[j]]=g[i]*g[p[j]];
		}
	}
	for(ll i=1;i<=Limit;i++)g[i]+=g[i-1];
}
int main()
{
	Init(); 
	q=getint();
	while(q--)
	{
		n=getint(),m=getint(),Ans=0;
		for(ll T=1;T<=n&&T<=m;T=Next+1)
		{
			Next=min(n/(n/T),m/(m/T));
			Ans=(Ans+(n/T)*(m/T)*(g[Next]-g[T-1]));
		}
		printf("%lld\n",Ans);
	}
	return 0;
}