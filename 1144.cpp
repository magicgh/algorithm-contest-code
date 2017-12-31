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
const int MAXN=1e8;
const int Mod=100000007;
bool vst[MAXN+5];
int n,p[6000005];
ll x,y,Ans=1;	
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline void Init(int Limit)
{
	for(ri i=2;i<=n;i++)
	{
		if(!vst[i])p[++p[0]]=i;
		for(ri j=1;j<=p[0]&&p[j]*i<=Limit;j++)
		{
			vst[i*p[j]]=1;
			if(i%p[j]==0)break;
		}
	}
}
int main()
{
	n=getint();
	Init(n);
	for(ri i=1;i<=p[0];i++)
	{
		x=p[i];
		while((y=((ll)p[i]*x))<=n)x=y;
		Ans=Ans%Mod*x%Mod;
	}
	printf("%lld\n",Ans);
	return 0;
}

