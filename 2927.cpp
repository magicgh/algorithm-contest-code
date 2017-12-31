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
const int Mod=10007;
const int MAXN=1005;
int T,n,k,ch[MAXN][MAXN],Size[MAXN],Y[MAXN][MAXN],f[MAXN],s[MAXN];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void Init()
{
	for(ri i=1;i<=1000;i++)
	{
		Y[i][1]=Y[i][i]=1;
		for(ri j=2;j<i;j++)
		Y[i][j]=(Y[i-1][j]+Y[i-1][j-1])%Mod;
	}
}
void Tree_DP(int u)
{
	f[u]=1;int cnt=0;
	if(!Size[u]){s[u]=1;return;}
	for(ri i=Size[u];i>0;i--)
	{
		Tree_DP(ch[u][i]);
		cnt+=s[ch[u][i]];
		f[u]=(f[u]%Mod*f[ch[u][i]]%Mod*Y[cnt][s[ch[u][i]]]%Mod)%Mod;
	}
	s[u]=cnt+1;
}
void Input()
{
	memset(ch,0,sizeof(ch));
	memset(Size,0,sizeof(Size));
	n=getint();
	for(ri i=1;i<=n;i++)
	{
		k=getint();
		if(k==0)continue;
		for(ri j=1;j<=k;j++)
		{
			int child=getint();
			ch[i][++Size[i]]=child;
		}
	}
	Tree_DP(1);
	printf("%d\n",f[1]%Mod);
}
int main()
{
	Init();
	T=getint();
	while(T--)Input();
		return 0;
}

