#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int Ln,Rn,N,Color=0,cnt=0;
const int MAXN=1000005;
bool Hash[1000005]={0};
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
	int L[MAXN],R[MAXN],bj[MAXN];
	inline void Build(int d,int l,int r)
	{	
		L[d]=l,R[d]=r,bj[d]=0;
		if(l==r)return;
		Build(d<<1,l,(l+r)>>1);
		Build(d<<1|1,((l+r)>>1)+1,r);
	}
	inline void PushDown(int v)
	{
		if(bj[v])
		{
		bj[v<<1]=bj[v<<1|1]=bj[v];
		bj[v]=0;
	}		
		return;
	}
	inline void Insert(int v,int l,int r)
	{
		if(l>R[v]||r<L[v])return;
		if(l<=L[v]&&r>=R[v])
		{
			//cout<<L[v]<<' '<<R[v]<<' '<<Color<<endl;
			bj[v]=Color;
			return;
		}
		PushDown(v);
		Insert(v<<1,l,r);
		Insert(v<<1|1,l,r);
	}
	inline void DFS(int v)
	{
		if(L[v]==R[v])
		{
		if(bj[v]!=0&&Hash[bj[v]]==0)
		{
			cnt++;Hash[bj[v]]=1;
		}
		return;
	}
		PushDown(v);
		DFS(v<<1);
		DFS(v<<1|1);
	}
};
SegmentTree tr;
int main(){
	Ln=GetInt();
	Rn=GetInt()-1;
	N=GetInt();
	tr.Build(1,Ln+100000,Rn+100000);
	int x,y;
	for(int i=1;i<=N;i++)
	{
		x=GetInt();
		y=GetInt()-1;
		if(x>y)continue;
		Color=i;
		tr.Insert(1,x+100000,y+100000);
	}
	tr.DFS(1); 
	printf("%d",cnt); 
	return 0;
}