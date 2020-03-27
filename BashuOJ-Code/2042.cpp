#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int M,N,S,MIN=0x7fffffff;
const int MAXN=60000*4+5;
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
	int L[MAXN],R[MAXN],Min[MAXN],cnt[MAXN];//cnt[i]记录prt[i]的总乘客数 
	inline void Build(int d,int l,int r)
	{
		L[d]=l,R[d]=r,Min[d]=S,cnt[d]=0;//Min[d]剩余座位数 
		if(l==r)return;
		Build(d<<1,l,(l+r)>>1);
		Build((d<<1)+1,((l+r)>>1)+1,r);
	}
	inline void PushDown(int v)//向下调整 
	{
		if(cnt[v]==0)return;
		Min[v<<1]-=cnt[v];
		Min[(v<<1)+1]-=cnt[v];//cnt下传 
		cnt[v<<1]+=cnt[v];
		cnt[(v<<1)+1]+=cnt[v];//prt区间乘客相当于乘坐其子节点区间的并集	
		cnt[v]=0;
	}
	inline void Update(int v,int l,int r)
	{
		if(l>R[v]||r<L[v])return;
		if(l<=L[v]&&r>=R[v])
		{
			MIN=min(MIN,Min[v]);
			return;
		}
		PushDown(v);
		Update(v<<1,l,r);
		Update((v<<1)+1,l,r);
		Min[v]=min(Min[(v<<1)+1],Min[v<<1]);//合并Min至prt 
	}
	inline void Modify(int v,int l,int r,int num)//调整更新元素值
	{
		 if(l>R[v]||r<L[v])return;
		 if(l<=L[v]&&r>=R[v])
		 {
		 	Min[v]-=num;//调整剩余座位个数
			cnt[v]+=num;//调整乘客个数
			return;
		 }
		 PushDown(v);
		 Modify(v<<1,l,r,num);
		 Modify((v<<1)+1,l,r,num);	
		 Min[v]=min(Min[(v<<1)+1],Min[v<<1]);//合并Min至prt 
	} 
};
SegmentTree tr;
int main(){
	N=GetInt();
	S=GetInt();
	M=GetInt();
	int x,y,z;
	tr.Build(1,1,N);
	for(int i=1;i<=M;i++)
	{
		MIN=0x7fffffff;
		x=GetInt();
		y=GetInt()-1;
		z=GetInt();
		tr.Update(1,x,y);
		if(MIN>=z)//剩余座位数>预定个数 
		{
			tr.Modify(1,x,y,z);
			puts("YES");
		}
		else puts("NO");
	}
	return 0;
}