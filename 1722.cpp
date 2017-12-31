#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<cmath>
using namespace std;
const int MAXN=2000005;
int N,M,NN;
int a[MAXN],b[MAXN],root[MAXN];
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+c-'0',c=getchar();
	return num*bj;
}
struct SegTree
{
	int L[MAXN],R[MAXN],s[MAXN],cnt;
	inline int Insert(int l,int r,int now,int val)
	{
		int next=++cnt;
		s[next]=s[now]+1;
		if(l==r)return next;
		L[next]=L[now],R[next]=R[now];
		int mid=(l+r)>>1;
		if(val<=mid)L[next]=Insert(l,mid,L[now],val);
		else R[next]=Insert(mid+1,r,R[now],val);
		return next;
	}
	inline int Query(int l,int r,int x,int y,int k)
	{
		if(l==r)return l;
		int mid=(l+r)>>1;
		int order=s[L[y]]-s[L[x]];
		if(order>=k)return Query(l,mid,L[x],L[y],k);
		else return Query(mid+1,r,R[x],R[y],k-order);
	}
}tr;

int main(){
	N=GetInt();M=GetInt();
	for(int i=1;i<=N;i++)a[i]=b[i]=GetInt();
	sort(b+1,b+N+1);
	NN=unique(b+1,b+N+1)-(b+1);
	for(int i=1;i<=N;i++)a[i]=lower_bound(b+1,b+NN+1,a[i])-b;
	for(int i=1;i<=N;i++)root[i]=tr.Insert(1,NN,root[i-1],a[i]);
	int x,y,z;
	for(int i=1;i<=M;i++)
	{
		x=GetInt();y=GetInt();z=GetInt();
		printf("%d\n",b[tr.Query(1,NN,root[x-1],root[y],z)]);
	}
	return 0;
}
