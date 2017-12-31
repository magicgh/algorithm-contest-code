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
const int MAXN=1005;
int p[MAXN];
bool vst[MAXN];
ll n,Ans,f[MAXN][MAXN];
inline ll getll()
{
	ll num=0;
	int bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void Init()
{
	for(ri i=2;i<=n;i++)
	{
		if(!vst[i])p[++p[0]]=i;
		for(ri j=1;j<=p[0]&&i*p[j]<=n;j++)
		{
			vst[i*p[j]]=1;
			if(i%p[j]==0)break;
		}
	}
}
int main()
{
	n=getll();
	Init();
	f[0][0]=1;
	for(ri i=1;i<=p[0];i++)
		for(ri j=0;j<=n;j++)
		{
			f[i][j]=f[i-1][j];
			for(ri k=p[i];k<=j;k*=p[i])
			f[i][j]+=f[i-1][j-k];
		}
	for(ri i=0;i<=n;i++)Ans+=f[p[0]][i];
	printf("%lld",Ans);
	return 0;
}

