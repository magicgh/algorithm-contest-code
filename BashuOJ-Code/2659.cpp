#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int M,N;
const int MAXN=60000*4+5;
struct SegmentTree
{
	int L[MAXN],R[MAXN],len[MAXN],bj[MAXN];
	inline void Build(int d,int l,int r)
	{
		L[d]=l,R[d]=r,len[d]=0,bj[d]=0;
		if(l==r)return;
		Build(2*d,l,(l+r)/2);
		Build(2*d+1,(l+r)/2+1,r);
	}
	inline void Lazy(int v)
	{
		if(bj[v]==-1)
		{
			bj[v*2]=bj[v*2+1]=-1;
			len[v*2]=len[v*2+1]=0;
			bj[v]=0;
		}
		if(bj[v]==1)
		{
			bj[v*2]=bj[v*2+1]=1;
			len[v*2]=R[v*2]-L[v*2]+1;
			len[v*2+1]=R[v*2+1]-L[v*2+1]+1;
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
		Lazy(v);
		Insert(v*2,l,r);
		Insert(v*2+1,l,r);
		len[v]=len[v*2]+len[v*2+1];
	}
	inline void Delete(int v,int l,int r)
	{
		if(l>R[v]||r<L[v]||bj[v]==-1)return;
		if(l<=L[v]&&r>=R[v])
		{
			bj[v]=-1;
			len[v]=0;
			return;
		}
		Lazy(v);
		Delete(v*2,l,r);
		Delete(v*2+1,l,r);
		len[v]=len[v*2]+len[v*2+1];
	}
};
SegmentTree tr;
int main(){
	cin>>N>>M;
	tr.Build(1,0,N);
	int a,b,c;
	for(int i=1;i<=M;i++)
	{
		cin>>a>>b>>c;
		if(a==1)tr.Insert(1,b,c-1);
		if(a==2)tr.Delete(1,b,c-1);
	}
	cout<<tr.len[1];
	return 0;
}
