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
#define gcd(a,b) __gcd(a,b)
using namespace std;
const int MAXN=200005;
vector<int>a[MAXN]; 
int n,m,cnt,Weight[MAXN];
int st[MAXN],ed[MAXN],Array[MAXN];
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
void DFS(int u)
{
	st[u]=++cnt,Array[cnt]=u;
	vector<int>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
		DFS(*it);
	ed[u]=cnt;
}
struct Segtree
{
	int L[MAXN<<2],R[MAXN<<2],Add[MAXN<<2],Gcd[MAXN<<2],val[MAXN<<2],dval[MAXN<<2];
	inline void Clear(int d){Add[d]=Gcd[d]=val[d]=dval[d]=0;}
	inline void Pushup(int d){Gcd[d]=gcd(Gcd[d<<1],Gcd[d<<1|1]);}
	inline void Pushdown(int d)
	{
		int lch=(d<<1),rch=(d<<1|1);
		if(L[lch]==R[lch])val[lch]+=Add[d];
		else Add[lch]+=Add[d];
		if(L[rch]==R[rch])val[rch]+=Add[d];
		else Add[rch]+=Add[d];
		Add[d]=0;
	}
	inline void Build(int d,int l,int r)
	{
		L[d]=l,R[d]=r,Clear(d);
		if(l==r)
		{
			val[d]=Weight[Array[l]];
			dval[d]=Gcd[d]=Weight[Array[l]]-Weight[Array[l-1]];
			return;
		}
		int mid=(l+r)>>1;
		Build(d<<1,l,mid);
		Build(d<<1|1,mid+1,r);
		Pushup(d); 
	}
	inline void Add_tree(int d,int l,int r,int v)
	{
		if(l>R[d]||r<L[d])return;
		if(l<=L[d]&&R[d]<=r)
		{
			if(L[d]==R[d])val[d]+=v;
			else Add[d]+=v;
			return;
		}
		Pushdown(d);
		Add_tree(d<<1,l,r,v);
		Add_tree(d<<1|1,l,r,v); 
	}
	inline void Add_dif(int d,int l,int v)//l表示左端点 
	{
		if(l>R[d]||l<L[d])return;//不为左端点的情况
		if(l==L[d]&&l==R[d])//d为左端点
		{
			dval[d]+=v;
			Gcd[d]=dval[d];
			return;
		}
		Pushdown(d);
		Add_dif(d<<1,l,v);
		Add_dif(d<<1|1,l,v);
		Pushup(d);
	}
	inline int Query_point(int d,int l)
	{
		if(l>R[d]||l<L[d])return 0;
		if(l==L[d]&&l==R[d])return val[d];
		Pushdown(d);
		return Query_point(d<<1,l)+Query_point(d<<1|1,l);
	}
	inline int Query_dif(int d,int l,int r)
	{
		if(l>R[d]||r<L[d])return 0;
		if(l<=L[d]&&R[d]<=r)return Gcd[d];
		return gcd(Query_dif(d<<1,l,r),Query_dif(d<<1|1,l,r));
	}
};
Segtree tr;
int main()
{
	n=getint(),m=getint();
	for(int i=1;i<=n;i++)
	{
		int fa=getint();Weight[i]=getint();
		if(fa)a[fa].push_back(i);	
	} 
	DFS(1);
	tr.Build(1,1,n);
	char ch;
	for(ri i=1;i<=m;i++)
	{
		while(ch=getchar())
			if(ch=='Q'||ch=='C')break;
		if(ch=='Q')
		{
			int x=getint();
			printf("%d\n",abs(gcd(tr.Query_point(1,st[x]),tr.Query_dif(1,st[x]+1,ed[x]))));
		}
		if(ch=='C')
		{
			int x=getint(),v=getint();
			tr.Add_tree(1,st[x],ed[x],v);
			tr.Add_dif(1,st[x],v),tr.Add_dif(1,ed[x]+1,-v);
		}
	} 
	return 0;
}