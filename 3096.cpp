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
vector<int>a[MAXN];
int n,m,cnt;
int prt[MAXN],son[MAXN],s[MAXN],dep[MAXN],top[MAXN],Num[MAXN],End[MAXN];
ll List[MAXN];
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
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
struct SegTree
{
	int L[MAXN<<2],R[MAXN<<2];ll sum[MAXN<<2],Max[MAXN<<2];
	inline void Pushup(int d)
	{
		sum[d]=sum[d<<1]+sum[d<<1|1];
		Max[d]=max(Max[d<<1],Max[d<<1|1]);
	}
	inline void Build(int d,int l,int r)
	{
		L[d]=l,R[d]=r,sum[d]=Max[d]=0;
		if(l==r)return;
		int mid=(l+r)>>1;
		Build(d<<1,l,mid);
		Build(d<<1|1,mid+1,r);
	}
	inline void Modify(int d,int p,ll v)
	{
		if(L[d]>p||R[d]<p)return;
		if(L[d]==p&&R[d]==p){sum[d]=Max[d]=v;return;}
		Modify(d<<1,p,v);
		Modify(d<<1|1,p,v);
		Pushup(d);
	}
	inline void Mod(int d,int l,int r,ll mod)
	{
		if(L[d]>r||R[d]<l)return;
		if(l<=L[d]&&R[d]<=r)
		{
			if(Max[d]<mod)return;
			if(L[d]==R[d]){sum[d]%=mod,Max[d]%=mod;return;}
		}
		Mod(d<<1,l,r,mod);
		Mod(d<<1|1,l,r,mod);
		Pushup(d);
	}
	inline ll Query(int d,int l,int r)
	{
		if(L[d]>r||R[d]<l)return 0;
		if(l<=L[d]&&R[d]<=r)return sum[d];
		else return Query(d<<1,l,r)+Query(d<<1|1,l,r);
	}
};
SegTree tr;
void DFSx1(int u,int fa,int depth)
{
	prt[u]=fa,dep[u]=depth,s[u]=1;
	vector<int>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(*it==fa)continue;
		DFSx1(*it,u,depth+1);
		s[u]+=s[*it];
		if((!son[u])||(s[son[u]]<s[*it]))son[u]=*it;
	}
}
void DFSx2(int u,int t)
{
	top[u]=t,Num[u]=++cnt;
	if(son[u])DFSx2(son[u],t);//先连接重链
	vector<int>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
		if(*it!=prt[u]&&*it!=son[u])DFSx2(*it,*it);//再连接轻链，链顶为该节点  
	End[u]=cnt;
}
inline ll Find(int u,int v)
{
	int t1=top[u],t2=top[v];
	ll sum=0;
	while(t1!=t2)
	{
		if(dep[t1]<dep[t2])swap(u,v),swap(t1,t2);
		sum+=tr.Query(1,Num[t1],Num[u]);
		u=prt[t1],t1=top[u];
	}
	if(dep[u]>dep[v])swap(u,v);
	return sum+tr.Query(1,Num[u],Num[v]);
}
int main()
{
	n=getint(),m=getint();
	for(ri i=1;i<n;i++)
	{
		int u=getint(),v=getint();
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for(ri i=1;i<=n;i++)List[i]=getll();
	DFSx1(1,0,0);//node,fa,depth
	DFSx2(1,1);//node,top(1)(链顶的编号) 把边连成链
	tr.Build(1,1,cnt);
	for(ri i=1;i<=n;i++)tr.Modify(1,Num[i],List[i]);
	for(ri i=1;i<=m;i++)
	{
		int op=getint(),u=getint(),x=getint();
		if(op==1)tr.Mod(1,Num[u],End[u],(ll)x);
		if(op==2)tr.Modify(1,Num[u],(ll)x);
		if(op==3)printf("%lld\n",Find(u,x));
	}
	return 0;
}

