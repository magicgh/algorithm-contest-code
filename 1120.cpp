#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<list>
using namespace std;
int son[50005],prt[50005],dep[50005],num[50005],fnum[50005],s[50005],top[50005],data[50005];
int N,Q,M;
int cnt=0;
list<int>a[50005];
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
	int L[50005*4],R[50005*4],S[50005*4];
	inline void Init()
	{
		int i=0;
		while(!a[i].empty())a[i++].clear();
		memset(data,0,sizeof(data));
		memset(son,0,sizeof(son));
		memset(prt,0,sizeof(prt));
		memset(dep,0,sizeof(dep));
		memset(num,0,sizeof(num));
		memset(fnum,0,sizeof(fnum));
		memset(s,0,sizeof(s));
		memset(top,0,sizeof(top));
		memset(L,0,sizeof(L));
		memset(R,0,sizeof(R));
		memset(S,0,sizeof(S));
	}
	inline void Build(int d,int l,int r)
	{	
		L[d]=l,R[d]=r,S[d]=0;
		if(l==r)return;
		Build(d<<1,l,(l+r)>>1);
		Build(d<<1|1,((l+r)>>1)+1,r);
	}
	inline void Insert(int v,int p,int d)
	{
		if(L[v]>p||R[v]<p)return;
		if(p==L[v]&&p==R[v]){S[v]=d;return;}
		Pushdown(v);
		Insert(v<<1,p,d);
		Insert(v<<1|1,p,d);
	}
	inline void Pushdown(int v)
	{
		if(S[v]!=0)
		{
			S[v<<1]+=S[v]; 
			S[v<<1|1]+=S[v]; 
			S[v]=0;
		}
	}
	inline void Modify(int v,int l,int r,int val)
	{
		if(l>R[v]||L[v]>r)return;
		if(l<=L[v]&&r>=R[v]){S[v]+=val;return;}
		Pushdown(v);
		Modify(v<<1,l,r,val);
		Modify(v<<1|1,l,r,val);
	}
	inline int Query(int v,int l,int r)
	{
		if(l>R[v]||L[v]>r)return 0;//Not Found
		if(l==L[v]&&r==R[v])return S[v]*(R[v]-L[v]+1);
		Pushdown(v);
		return Query(v<<1,l,r)+Query(v<<1|1,l,r); 
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
void Find(int u,int v,int k)//u->v(原树结点) 
{
	int t1=top[u],t2=top[v];//取出top 
	while(t1!=t2)//爬树 
	{
		if(dep[t1]<dep[t2])swap(t1,t2),swap(u,v);//depth:t1>deph:t2
		tr.Modify(1,num[t1],num[u],k);
		u=prt[t1],t1=top[u];
	}			
	if(dep[u]>dep[v])swap(u,v);//交换顺序 
	tr.Modify(1,num[u],num[v],k);
}
int main(){
	int x,y,z;
	tr.Init();
	N=GetInt();	M=GetInt();Q=GetInt();
	for(int i=1;i<=N;i++)data[i]=GetInt();
	for(int i=1;i<=M;i++)
	{
		x=GetInt();
		y=GetInt();
		a[x].push_back(y);
		a[y].push_back(x);
	}
	DFS1(1,0,1);//depth,fa,node
	DFS2(1,1);//node,top
	tr.Build(1,1,cnt);
	for(int i=1;i<=N;i++)tr.Insert(1,num[i],data[i]);
	char k;		
	for(int i=1;i<=Q;i++)	
	{
		while(k=getchar())if(k=='I'||k=='D'||k=='Q')break;
		if(k=='I')x=GetInt(),y=GetInt(),z=GetInt(),Find(x,y,z);
		if(k=='D')x=GetInt(),y=GetInt(),z=GetInt(),Find(x,y,-z);
		if(k=='Q')x=GetInt(),printf("%d\n",tr.Query(1,num[x],num[x]));
	}
	return 0;
}
