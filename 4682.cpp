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
int n,q,cnt;
vector<int>a[MAXN];
int dep[MAXN],Size[MAXN],top[MAXN],son[MAXN],prt[MAXN],List[MAXN],Tree[MAXN];
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
struct SegmentTree
{
	int L[MAXN<<2],R[MAXN<<2],bj[MAXN<<2];
	inline void Pushup(int d){bj[d]=max(bj[d<<1],bj[d<<1|1]);}
	inline void Build(int d,int l,int r)
	{
		L[d]=l,R[d]=r;
		if(l==r){bj[d]=-1;return;}
		int mid=(l+r)>>1;
		Build(d<<1,l,mid);
		Build(d<<1|1,mid+1,r);
		Pushup(d);
	}
	inline void Modify(int d,int pos)
	{
		if(L[d]>pos||R[d]<pos)return;
		if(L[d]==R[d]&&L[d]==pos){bj[d]=pos;return;}
		Modify(d<<1,pos);
		Modify(d<<1|1,pos);
		Pushup(d);
	}
	inline int Query(int d,int l,int r)
	{
		if(L[d]>r||R[d]<l)return -1;
		if(l<=L[d]&&R[d]<=r)return bj[d];
		return max(Query(d<<1,l,r),Query(d<<1|1,l,r));
	}
};
SegmentTree tr;
void DFSx1(int u,int depth)
{
	dep[u]=depth,Size[u]=1;
	vector<int>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(*it==prt[u])continue;
		prt[*it]=u;
		DFSx1(*it,depth+1);
		Size[u]+=Size[*it];
		if((!son[u])||(Size[son[u]]<Size[*it]))
			son[u]=*it;
	}
}
void DFSx2(int u,int t)
{
	top[u]=t,List[u]=++cnt,Tree[cnt]=u;
	if(son[u])DFSx2(son[u],t);
	vector<int>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
		if(*it!=prt[u]&&*it!=son[u])DFSx2(*it,*it);
}
int Find(int u)
{
	while(top[u]!=top[1]) 
	{
		int Ans=tr.Query(1,List[top[u]],List[u]);
		if(Ans!=-1)return Ans;
		u=prt[top[u]];
	}
	return tr.Query(1,List[1],List[u]);
}
int main()
{
	n=getint(),q=getint();
	for(ri i=1;i<n;i++)
	{
		int u=getint(),v=getint();
		a[u].push_back(v);
	}
	DFSx1(1,0);
	DFSx2(1,1);
	tr.Build(1,1,cnt),tr.Modify(1,List[1]);
	char ch;
	for(ri i=1;i<=q;i++)
	{
		while(ch=getchar())
			if(ch=='Q'||ch=='C')break;
		int pos=getint();
		if(ch=='C')
			tr.Modify(1,List[pos]);
		if(ch=='Q')
			printf("%d\n",Tree[Find(pos)]);
	}
	return 0;
}

