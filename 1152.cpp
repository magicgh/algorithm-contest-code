#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
const int MAXN=100000*4+5;
int N,M,ans=0;
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
struct SegmentTree
{
	int L[MAXN],R[MAXN],sum[MAXN];
	inline void Build(int d,int l,int r)
	{	
		L[d]=l,R[d]=r,sum[d]=0;
		if(l==r)return;
		Build(d<<1,l,(l+r)>>1);
		Build(d<<1|1,((l+r)>>1)+1,r);
	}
	inline void Modify(int v,int l,int r)
	{
		if(l>R[v]||r<L[v])return;
		if(l<=L[v]&&r>=R[v]){sum[v]++;return;}
		if(L[v]==R[v])return;
		Modify(v<<1,l,r);
		Modify(v<<1|1,l,r);
	}
	inline void Query(int v,int d)
	{
		if(d>R[v]||d<L[v])return;
		if(d>=L[v]&&d<=R[v])ans+=sum[v];
		if(L[v]==R[v])return;
		int mid=(L[v]+R[v])>>1;
		if(d<=mid)Query(v<<1,d);
		else Query(v<<1|1,d);
	}
};
SegmentTree tr;
int main(){
	N=GetInt();M=GetInt();
	int t,x,y;
	tr.Build(1,1,N);
	for(int i=1;i<=M;i++)
	{
		ans=0;
		t=GetInt();
		if(t==1)
		{
			x=GetInt();
			y=GetInt();
			tr.Modify(1,x,y);
		}
		if(t==2)
		{
			x=GetInt();
			tr.Query(1,x);
			if(ans&1)printf("1\n");
			else printf("0\n");
		}
	}
	return 0;
}