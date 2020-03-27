#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAXN=200005;
const int SegMAXN=200005*20;
struct Request
{
	char cmd;
	int l,r,val;
};
Request q[MAXN]; 
int N,M,NN,bN=0;
int a[MAXN],b[MAXN],root[SegMAXN];
int t1[SegMAXN],t2[SegMAXN];
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
	int L[SegMAXN],R[SegMAXN],s[SegMAXN],cnt;
	inline int Insert(int l,int r,int now,int val,int d)
	{
		int next=++cnt;
		s[next]=s[now]+d;
		if(l==r)return next;
		L[next]=L[now],R[next]=R[now];
		int mid=(l+r)>>1;
		if(val<=mid)L[next]=Insert(l,mid,L[now],val,d);
		else R[next]=Insert(mid+1,r,R[now],val,d);
		return next;
	}
	inline int Query(int l,int r,int k)
	{
		if(l==r)return l;
		int lsum=0,rsum=0;
		for(int i=1;i<=t1[0];i++)lsum+=s[L[t1[i]]];
		for(int i=1;i<=t2[0];i++)rsum+=s[L[t2[i]]];
		int sum=rsum-lsum;
		int mid=(l+r)>>1;
		if(sum>=k)
		{
			for(int i=1;i<=t1[0];i++)t1[i]=L[t1[i]];
			for(int i=1;i<=t2[0];i++)t2[i]=L[t2[i]];
			return Query(l,mid,k);
		}
		else
		{
			for(int i=1;i<=t1[0];i++)t1[i]=R[t1[i]];
			for(int i=1;i<=t2[0];i++)t2[i]=R[t2[i]];
			return Query(mid+1,r,k-sum);
		}
	}
};
SegTree st;
struct bit
{
	inline int Lowbit(int x){return x&(-x);}
	inline void Add(int val,int x,int d)
	{
		for(int i=x;i<=NN;i+=Lowbit(i))root[i]=st.Insert(1,NN,root[i],val,d);
	}
	inline int Query(int l,int r,int k)
	{
		t1[0]=t2[0]=0;//清零 
		for(int i=l;i>0;i-=Lowbit(i))t1[++t1[0]]=root[i];
		for(int i=r;i>0;i-=Lowbit(i))t2[++t2[0]]=root[i];
		return st.Query(1,NN,k);
	} 
};
bit tr;
int main(){
	bN=N=GetInt();M=GetInt();
	for(int i=1;i<=N;i++)a[i]=b[i]=GetInt();
	int x,y,z;
	char ch;
	for(int i=1;i<=M;i++)
	{
		while(ch=getchar())if(ch=='C'||ch=='Q')break;
		switch(ch)
		{
			case 'C':
			q[i].cmd=ch;
			q[i].l=GetInt(),q[i].val=GetInt();
			b[++bN]=q[i].val;break;
			case 'Q':
			x=GetInt(),y=GetInt(),z=GetInt();
			q[i]=(Request){ch,x,y,z};break;	 
		}
	}
	sort(b+1,b+bN+1);
	NN=unique(b+1,b+bN+1)-(b+1);
	for(int i=1;i<=N;i++)a[i]=lower_bound(b+1,b+NN+1,a[i])-b;
	for(int i=1;i<=N;i++)tr.Add(a[i],i,1);
	for(int i=1;i<=M;i++)
	{
		switch(q[i].cmd)
		{
			case 'C':
			tr.Add(a[q[i].l],q[i].l,-1);
			a[q[i].l]=lower_bound(b+1,b+NN+1,q[i].val)-b;
			tr.Add(a[q[i].l],q[i].l,1);break;
			case 'Q':
			printf("%d\n",b[tr.Query(q[i].l-1,q[i].r,q[i].val)]);break;
		}
	}
	return 0;
}
