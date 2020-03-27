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
const int MAXN=7000005;
const ll Mod=998244353,Inv2=499122177,Inv6=166374059;
bool vst[MAXN];
ll p[MAXN],g[MAXN],Ans;
int n,m,q,Next;
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
void Init()
{
	static const int Limit=7000000;
	g[1]=1;
	for(ri i=2;i<=Limit;i++)
	{
		if(!vst[i])p[++p[0]]=i,g[i]=i-1;
		for(ri j=1;j<=p[0]&&i*p[j]<=Limit;j++)
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
	for(int i=1;i<=Limit;i++)g[i]=(g[i-1]+g[i]*i%Mod*i%Mod)%Mod;
}
inline ll H(ll n,ll m)
{
	return (Inv6*n%Mod*m%Mod*(n+1)%Mod*(2*n+1)%Mod+Inv6*m%Mod*n%Mod*(m+1)%Mod*(2*m+1)%Mod+Inv2*n%Mod*(n+1)%Mod*m%Mod*(m+1)%Mod)%Mod;
}
int main()
{
	Init(); 
	q=getint();
	while(q--)
	{
		n=getint(),m=getint(),Ans=0;
		for(ri T=1;T<=n&&T<=m;T=Next+1)
		{
			Next=min(n/(n/T),m/(m/T));
			Ans=(Ans+H(n/T,m/T)*(g[Next]-g[T-1]))%Mod;
		}
		Ans=(Ans+Mod)%Mod;
		printf("%lld\n",Ans);
	}
	return 0;
}