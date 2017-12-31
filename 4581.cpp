#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#define ri register int
#define ll long long
#define lowbit(x) x&(-x)
using namespace std;
const int MAXN=100005;
vector<int>a[MAXN];
int n,m,cnt;
int L[MAXN],R[MAXN],value[MAXN],d[MAXN];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
struct Bit
{
	ll C[MAXN];
	inline void Add(int pos,ll val)
	{
		for(ri i=pos;i<=n;i+=lowbit(i))C[i]+=val;
	}
	inline ll Query(int pos)
	{
		ll Ans=0;
		for(ri i=pos;i>=1;i-=lowbit(i))Ans+=C[i];
		return Ans;
	}
};
Bit C1,C2;
void DFS(int u,int fa,int depth)
{
	L[u]=++cnt,d[u]=depth;
	vector<int>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{	
		if(*it==fa)continue;
		DFS(*it,u,depth+1);
	}
	R[u]=cnt;
}
int main()
{
	n=getint(),m=getint();
	for(ri i=1;i<=n;++i)
		value[i]=getint();
	for(ri i=1;i<n;++i)
	{
		int u=getint(),v=getint();
		a[u].push_back(v);
		a[v].push_back(u);
	}
	DFS(1,0,0);
	for(ri i=1;i<=n;++i)
		C1.Add(L[i],value[i]),C1.Add(R[i]+1,-value[i]);
	for(ri i=1;i<=m;++i)
	{
		int op=getint();
		if(op==1)
		{
			int x=getint(),a=getint();
			C1.Add(L[x],a),C1.Add(R[x]+1,-a);
		}
		if(op==2)
		{
			int x=getint(),a=getint();
			C1.Add(L[x],(ll)(-(d[x]-1))*(ll)a),C1.Add(R[x]+1,(ll)(d[x]-1)*(ll)a);
			C2.Add(L[x],a),C2.Add(R[x]+1,-a);
		}
		if(op==3)
		{
			int x=getint();
			printf("%lld\n",C1.Query(L[x])+C2.Query(L[x])*(ll)d[x]);
		}
	}
	return 0;
}