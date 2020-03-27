#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int T,L,M;
bool Hash[31];
const int MAXN=500005;
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
	int L[MAXN],R[MAXN],C[MAXN];
	inline void Build(int d,int l,int r)
	{
		L[d]=l,R[d]=r,C[d]=1;
		if(l==r)return;
		Build(d<<1,l,(l+r)>>1);
		Build(d<<1|1,((l+r)>>1)+1,r);
	}
	inline void Query(int v,int l,int r)
	{
		if(l>R[v]||r<L[v])return;
		if(l<=L[v]&&r>=R[v]&&C[v]!=-1)
		{
		Hash[C[v]]=1;
		return;
		}
		PushDown(v);	 
		Query(v<<1,l,r);
		Query(v<<1|1,l,r);
	}
	inline void PushDown(int v)
	{
		if(C[v]!=-1)
		{
		C[v<<1]=C[v<<1|1]=C[v];
		C[v]=-1; 
		}
	}
	inline void Insert(int v,int l,int r,int c)
	{	
	    if(l>R[v]||r<L[v]||C[v]==c)return;
		if(l<=L[v]&&r>=R[v])
		{
			C[v]=c;	
			return;
		}
		PushDown(v);
		Insert(v<<1,l,r,c);
		Insert(v<<1|1,l,r,c);
	}
}; 
SegmentTree tr;
int main(){
	L=GetInt();
	T=GetInt();
	M=GetInt();
	tr.Build(1,1,L);
	char ch;
	int a,b,c;
	for(int i=1;i<=M;i++)
	{
		scanf("%s",&ch);
		if(ch=='C'){
			a=GetInt();
			b=GetInt();
			c=GetInt();
			if(a>b)swap(a,b);
			tr.Insert(1,a,b,c);
		}
		if(ch=='P'){
			int Ans=0;
			memset(Hash,0,sizeof(Hash));
			a=GetInt();
			b=GetInt();
			if(a>b)swap(a,b);
			tr.Query(1,a,b);
			for(int j=1;j<=T;j++)Ans+=Hash[j];
			printf("%d\n",Ans);
		}
	}
	return 0;
}