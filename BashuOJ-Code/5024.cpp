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
const ll Mod=998244353;
const int MAXN=100005;
struct node{int to;ll val;};
vector<node>a[MAXN];
int n,m,cnt,Belong[MAXN];
bool vst[MAXN];
ll d1[MAXN],d2[MAXN],Maxlen[MAXN],Ans;
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline const ll getll()
{
	ll num=0;int bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline ll Pow(ll a,ll b)
{
	ll ret=1,base=a;
	while(b)
	{
		if(b&1)ret=(ret%Mod*base%Mod)%Mod;
		base=(base%Mod*base%Mod)%Mod;
		b>>=1;
	}
	return ret%Mod;
}
void DFS(int u,int fa,int part)
{
	Belong[u]=part,vst[u]=1;
	vector<node>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(vst[it->to]||it->to==fa)continue;
		DFS(it->to,u,part);
		if(d1[it->to]+it->val>d1[u])
			d2[u]=d1[u],d1[u]=d1[it->to]+it->val;
		else if(d1[it->to]+it->val>d2[u])
			d2[u]=d1[it->to]+it->val;
	}
}
int main()
{
	n=getint(),m=getint();
	for(ri i=1;i<=m;i++)
	{
		int x=getint(),y=getint();
		ll z=getll();
		a[x].push_back((node){y,z});
		a[y].push_back((node){x,z});
	}
	for(ri i=1;i<=n;i++)
		if(!vst[i])DFS(i,0,++cnt);
	for(ri i=1;i<=n;i++)
		Maxlen[Belong[i]]=max(Maxlen[Belong[i]],d1[i]+d2[i]);
	for(ri i=1;i<=cnt;i++)
		Ans+=Maxlen[i];
	printf("%lld\n",Pow(2,Ans));
	return 0;
}