#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;	
int L,R,N;
const int MAXN=100000*10+5;
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
	int L[MAXN],R[MAXN],len[MAXN],bj[MAXN];
	inline void Build(int d,int l,int r)
	{
		L[d]=l,R[d]=r,len[d]=0,bj[d]=0;
		if(l==r)return;
		Build(d<<1,l,(l+r)>>1);
		Build(d<<1|1,((l+r)>>1)+1,r);
	}
	inline void PushDown(int v)
	{
		if(bj[v]==-1)
		{
			bj[v<<1]=bj[v<<1|1]=-1;
			len[v<<1]=len[v<<1|1]=0;
			bj[v]=0;
		}
		if(bj[v]==1)
		{
			bj[v<<1]=bj[v<<1|1]=1;
			len[v<<1]=R[v<<1]-L[v<<1]+1;
			len[v<<1|1]=R[v<<1|1]-L[v<<1|1]+1;
			bj[v]=0;
		}
		return;
	}
	inline void Insert(int v,int l,int r)
	{
		if(l>R[v]||r<L[v]||bj[v]==1)return;
		if(l<=L[v]&&r>=R[v])
		{
			bj[v]=1;
			len[v]=R[v]-L[v]+1;
			return;
		}
		PushDown(v);
		Insert(v<<1,l,r);
		Insert(v<<1|1,l,r);
		len[v]=len[v<<1]+len[v<<1|1];
	}
};
SegmentTree tr;
int main(){
	L=GetInt();
	R=GetInt()-1;
	N=GetInt();
	int x,y;
	tr.Build(1,L,R);
	for(int i=1;i<=N;i++)
	{
		x=GetInt();
		y=GetInt()-1;
		if(x>y)continue;
		tr.Insert(1,x,y); 
	}
	printf("%d",tr.len[1]);
	return 0;
}
