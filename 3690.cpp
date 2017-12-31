#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<list>
using namespace std;
int son[200005],prt[200005],dep[200005],num[200005],fnum[200005],s[200005],top[200005];
int N,Q;
int cnt=0;
list<int>a[200005];
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
	int L[200005*4],R[200005*4],S[200005*4],D[200005*4];
	inline void Build(int d,int l,int r)
	{	
		L[d]=l,R[d]=r,S[d]=0;
		if(l==r)return;
		Build(d<<1,l,(l+r)>>1);
		Build(d<<1|1,((l+r)>>1)+1,r);
	}
	inline void Pushdown(int v)
	{
		if(S[v])
		{
			S[v<<1]+=S[v]; 
			S[v<<1|1]+=S[v]; 
			S[v]=0;
		}
	}
	inline void Modify(int v,int l,int r)
	{
		if(l>R[v]||L[v]>r)return;
		if(l<=L[v]&&r>=R[v]){S[v]++;return;}
		Pushdown(v);
		Modify(v<<1,l,r);
		Modify(v<<1|1,l,r);
	}
	inline int Query2(int v,int l,int r)
	{
		if(l>R[v]||L[v]>r)return 0;//Not Found
		if(l<=L[v]&&r>=R[v])return S[v]*(R[v]-L[v]+1);
		Pushdown(v);
		return Query2(v<<1,l,r)+Query2(v<<1|1,l,r);
	}
};
SegmentTree tr; 
void DFS1(int d,int f,int u)
{
	dep[u]=d;
	s[u]=1;prt[u]=f;	
	list<int>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(prt[u]!=*it)
		{
		DFS1(d+1,u,*it);
		s[u]+=s[*it];
		if((son[u]==0)||s[son[u]]<s[*it])son[u]=*it;
		}
	}
}
void DFS2(int u,int t)
{
	top[u]=t;
	num[u]=++cnt;
	fnum[num[u]]=u;
	if(son[u]!=0)DFS2(son[u],t);//先找重儿子
	list<int>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
		if(prt[u]!=*it&&*it!=son[u])DFS2(*it,*it);//再找轻儿子
}
void Find1(int u,int v)//u->v(原树结点) 
{
	int t1=top[u],t2=top[v];//取出top 
	while(t1!=t2)//爬树 
	{
		if(dep[t1]<dep[t2])swap(t1,t2),swap(u,v);//depth:t1>deph:t2
		tr.Modify(1,num[t1],num[u]);
		u=prt[t1],t1=top[u];
	}			
	if(dep[u]>dep[v])swap(u,v);//交换顺序 
	tr.Modify(1,num[son[u]],num[v]);
}
int Find2(int u,int v)//u->v(原树结点) 
{
	int t1=top[u],t2=top[v];//取出top 
	int sum=0;
	while(t1!=t2)//爬树 
	{
		if(dep[t1]<dep[t2])swap(t1,t2),swap(u,v);//depth:t1>deph:t2
		sum+=tr.Query2(1,num[t1],num[u]);//求当前重链的和
		u=prt[t1],t1=top[u];
	}			
	if(dep[u]>dep[v])swap(u,v);//交换顺序 
	return sum+tr.Query2(1,num[son[u]],num[v]);
}
int main(){
	int x,y,z;
	N=GetInt();	Q=GetInt();
	for(int i=1;i<=N-1;i++)
	{
		x=GetInt();
		y=GetInt();
		a[x].push_back(y);		
		a[y].push_back(x);
	}
	DFS1(1,0,1);//depth,fa,node
	DFS2(1,1);//node,top
	tr.Build(1,1,cnt);
	char k;		
	for(int i=1;i<=Q;i++)	
	{
		while(k=getchar())if(k=='P'||k=='Q')break;
		x=GetInt();y=GetInt();
		if(k=='P')Find1(x,y);
		if(k=='Q')printf("%d\n",Find2(x,y));
	}
	return 0;
}
