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
const ll Mod=1000000007ll;
const int MAXN=100005;
vector<int>a[MAXN];
int n,Val[MAXN];
ll f[MAXN][2];
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
void Tree_DP(int u)
{
	f[u][1]=Val[u],f[u][0]=Val[u]^1;
	vector<int>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		Tree_DP(*it);
		f[u][1]=((f[u][1]*f[*it][1])%Mod+(f[u][1]*f[*it][0])%Mod+(f[u][0]*f[*it][1])%Mod)%Mod;
		f[u][0]=((f[u][0]*f[*it][1])%Mod+(f[u][0]*f[*it][0])%Mod)%Mod;
	}
}
int main()
{
	n=getint();
	for(ri i=2;i<=n;i++)
	{
		int fa=getint()+1;
		a[fa].push_back(i);
	}
	for(ri i=1;i<=n;i++)Val[i]=getint();
	Tree_DP(1);
	printf("%lld\n",f[1][1]);
	return 0;
}

