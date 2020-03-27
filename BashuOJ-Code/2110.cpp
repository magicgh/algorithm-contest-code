#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAXN=400005;
struct node
{
	int lx,ly,rx,ry,color;
};
int N,A,B,NN;
node Data[MAXN];
int m[MAXN],ans[MAXN];
struct SegmentTree
{
	int L[MAXN],R[MAXN],C[MAXN];
	inline void Build(int d,int l,int r)
	{	
		L[d]=l,R[d]=r,C[d]=0;
		if(l==r)return;
		Build(d<<1,l,(l+r)>>1);
		Build(d<<1|1,((l+r)>>1)+1,r);
	}
	inline void Insert(int v,int l,int r,int c)
	{
		if(l>R[v]||r<L[v]||C[v]>0)return;
		if(l<=L[v]&&r>=R[v]&&C[v]!=-1)
		{
			C[v]=c;
			return;
		}
		Insert(v<<1,l,r,c); 
		Insert(v<<1|1,l,r,c);
		C[v]=-1;//节点v的子树已涂色 
	}
	inline void Query(int v,int x)
	{
		if(C[v]==0)return;//未涂色
		if(C[v]>0)
		{
			ans[C[v]]+=(R[v]-L[v]+1)*(m[x+1]-m[x]);
			C[v]=0;//标记已处理 
			return;
		}
		Query(v<<1,x); 
		Query(v<<1|1,x);
		C[v]=0;//标记已处理
	}
};	
SegmentTree tr;
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
int main(){
	A=GetInt();
	B=GetInt();
	N=GetInt();
	int lx,ly,rx,ry,color;
	for(int i=1;i<=N;i++)
	{
		lx=GetInt();
		ly=GetInt();
		rx=GetInt();
		ry=GetInt();
		color=GetInt();
		Data[i]=(node){lx,ly,rx,ry,color};
		m[i]=Data[i].lx;
		m[N+i]=Data[i].rx;
	}
	sort(m+1,m+(N<<1|1));
	NN=unique(m+1,m+(N<<1|1))-(m+1);//去重后的总个数
	for(int i=1;i<=N;i++)
	{
		Data[i].lx=lower_bound(m+1,m+NN+1,Data[i].lx)-m;
		Data[i].rx=lower_bound(m+1,m+NN+1,Data[i].rx)-m;//建立映射
	}
	tr.Build(1,0,B-1);
	for(int i=1;i<NN;i++)//枚举离散化区间 
	{
		for(int j=N;j>=1;j--)
		//向前枚举矩形
			if(m[Data[j].lx]<=m[i]&&m[Data[j].rx]>m[i])//第j个矩形跨越第i个区间
				tr.Insert(1,Data[j].ly,Data[j].ry-1,Data[j].color);//插入
		tr.Query(1,i); 
	}
	ans[1]=A*B;
	for(int i=2;i<=2500;i++)ans[1]-=ans[i];//枚举颜色 白纸颜色为1 
	for(int i=1;i<=2500;i++)if(ans[i])printf("%d %d\n",i,ans[i]); 
	
	return 0;
}
