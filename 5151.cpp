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
const int MAXN=100005;
const int Limit=100000;
const ll Mod=1000000007ll;
int T,P,N,f[MAXN][2];
ll g[MAXN][2],Max[MAXN];
vector<int>a[MAXN];
inline const int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
void Clear()
{
	for(ri i=1;i<=Limit;i++)a[i].clear();
}
inline ll Pow(ll a,ll b)
{
	ll ret=1,base=a;
	while(b)
	{
		if(b&1)ret=(ret*base)%Mod;
		base=(base*base)%Mod;
		b>>=1;
	}
	return ret;
}
inline ll Inv(ll a){return Pow(a,Mod-2);}
void Tree_DP(int u,int fa)
{
	int ret=0,cnt=0;bool Leaf=0;
	vector<int>::iterator it;
	f[u][0]=f[u][1]=0,g[u][1]=g[u][0]=1;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(*it==fa)continue;
		Leaf=1;
		Tree_DP(*it,u);
		f[u][0]+=max(f[*it][0],f[*it][1]);
		g[u][0]=g[u][0]*Max[*it]%Mod;
	}
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(*it==fa)continue;
		int val=f[u][0]-max(f[*it][0],f[*it][1])+f[*it][0]+1;
		ll cnt=g[u][0]*Inv(Max[*it])%Mod*g[*it][0]%Mod;
		if(f[u][1]<val)
			f[u][1]=val,g[u][1]=cnt;
		else if(f[u][1]==val)
			g[u][1]=(g[u][1]+cnt)%Mod;
	}
	if(!Leaf)Max[u]=1;
	else if(f[u][0]==f[u][1])Max[u]=(g[u][0]+g[u][1])%Mod;
	else Max[u]=(f[u][1]>f[u][0])?g[u][1]:g[u][0];
}
int main()
{
	T=GetInt(),P=GetInt();
	while(T--)
	{
		N=GetInt();
		Clear();
		for(ri i=1;i<N;i++)
		{
			int u=GetInt(),v=GetInt();
			a[u].push_back(v);
			a[v].push_back(u);
		}
		Tree_DP(1,0);
		printf("%d ",max(f[1][0],f[1][1]));
		if(P==2)printf("%lld",Max[1]);
		printf("\n");
	}
	return 0;
}

