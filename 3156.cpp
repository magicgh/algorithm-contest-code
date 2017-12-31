#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAXN=400005;
int N,NN;
long long Ans=0;
int m[MAXN];
struct node
{
	int a,b,h;
};
struct SegmentTree
{
	int L[MAXN],R[MAXN],H[MAXN];
	inline void Build(int d,int l,int r)
	{	
		L[d]=l,R[d]=r,H[d]=0;
		if(l==r)return;
		Build(d<<1,l,(l+r)>>1);
		Build(d<<1|1,((l+r)>>1)+1,r);
	}
	inline void PushDown(int v)//向下维护 
	{
		if(H[v]!=-1)
		{
		H[v<<1]=H[v<<1|1]=H[v];
		H[v]=-1;
		}
	}
	inline void Insert(int v,int l,int r,int d)
	{
		if(l>R[v]||r<L[v]||d<=H[v])return;
		if(l<=L[v]&&r>=R[v]&&H[v]!=-1)
		{
			H[v]=d;
			return;
		}
		if(L[v]!=R[v])
		{
		PushDown(v);
		Insert(v<<1,l,r,d); 
		Insert(v<<1|1,l,r,d);
	    }
		if(H[v<<1]==H[v<<1|1])H[v]=H[v<<1];//向上维护 
	}
	inline void Query(int v)
	{
		if(H[v]>0)
		{
		Ans+=H[v]*(long long)(m[R[v]+1]-m[L[v]]);//计算面积 
		return;
		}
		if(L[v]==R[v])return;
		Query(v<<1);
		Query(v<<1|1);
	}
};
SegmentTree tr;
node Data[MAXN];
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
int main(){
	N=GetInt();
	int a,b,h;
	for(int i=1;i<=N;i++)
	{
		a=GetInt();
		b=GetInt();
		h=GetInt();
		Data[i]=(node){a,b,h};
		m[i]=Data[i].a;
		m[i+N]=Data[i].b;
	}
	sort(m+1,m+2*N+1);
	NN=unique(m+1,m+(N<<1|1))-(m+1);//去重后的总个数 
	for(int i=1;i<=N;i++)
	{
		Data[i].a=lower_bound(m+1,m+NN+1,Data[i].a)-m;
		Data[i].b=lower_bound(m+1,m+NN+1,Data[i].b)-m;//建立映射 
	}
	tr.Build(1,1,NN-1);
	for(int i=1;i<=N;i++)
		tr.Insert(1,Data[i].a,Data[i].b-1,Data[i].h);
	tr.Query(1);
	printf("%lld\n",Ans);
	return 0;
}