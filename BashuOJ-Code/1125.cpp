#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<list>
using namespace std;
struct node
{
	int x,y,z;
};
node data[30005];
list<int>a[30005];
int son[30005],prt[30005],dep[30005],num[30005],s[30005],top[30005];
int cnt=0;
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline void swap(int *xx,int *yy){(*xx)^=(*yy);(*yy)^=(*xx);(*xx)^=(*yy);}
struct SegmentTree
{
	int L[80005*4],R[80005*4],V[80005*4],Ma[80005*4],Mi[80005*4],Tr[80005*4];
	/*OK*/inline void Build(int d,int l,int r)
	{	
		L[d]=l,R[d]=r,Ma[d]=-0x7fffffff,Mi[d]=0x7fffffff,Tr[d]=0;//Tr 反转(0,1) 
		if(l==r)return;
		Build(d<<1,l,(l+r)>>1);
		Build(d<<1|1,((l+r)>>1)+1,r);
	}
	/*OK*/inline void Pushup(int v)
	{
		Ma[v]=max(Ma[v<<1],Ma[v<<1|1]);
		Mi[v]=min(Mi[v<<1],Mi[v<<1|1]);
	}
	/*OK*/inline void Pushdown(int v)
	{
		if(Tr[v])
		{
			Tr[v<<1]^=1;
			Tr[v<<1|1]^=1;
			Tr[v]=0;
			swap(Ma[v<<1],Mi[v<<1]);
			Ma[v<<1]=~Ma[v<<1]+1;
			Mi[v<<1]=~Mi[v<<1]+1;
			swap(Ma[v<<1|1],Mi[v<<1|1]);
			Ma[v<<1|1]=~Ma[v<<1|1]+1;
			Mi[v<<1|1]=~Mi[v<<1|1]+1;
		}
	}
	/*OK*/inline void Insert(int v,int x,int d)
	{
		if(L[v]>x||R[v]<x)return;
		if(x==L[v]&&x==R[v]){Ma[v]=d;Mi[v]=d;return;}
		Pushdown(v);
		Insert(v<<1,x,d);
		Insert(v<<1|1,x,d);
		Pushup(v);
	}
	/*OK*/inline int QueryMax(int v,int l,int r)
	{
		if(l>R[v]||L[v]>r)return -0x7fffffff;//Not Found
		if(l<=L[v]&&r>=R[v])return Ma[v];
		Pushdown(v);
		return max(QueryMax(v<<1,l,r),QueryMax(v<<1|1,l,r));
		Pushup(v);
	}
	/*OK*/inline void QueryTr(int v,int l,int r)
	{
		if(l>R[v]||L[v]>r)return;//Not Found
		if(l<=L[v]&&r>=R[v]){Tr[v]^=1;swap(Ma[v],Mi[v]);Ma[v]=~Ma[v]+1;Mi[v]=~Mi[v]+1;return;}
		Pushdown(v);
		QueryTr(v<<1,l,r);QueryTr(v<<1|1,l,r);
		Pushup(v); 
	} 
};
SegmentTree tr; 
/*OK*/void DFS1(int d,int f,int u)
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
/*OK*/void DFS2(int u,int t)
{
	top[u]=t;
	num[u]=++cnt;
	if(son[u]!=0)DFS2(son[u],t);//先找重儿子
	list<int>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
		if(prt[u]!=*it&&*it!=son[u])DFS2(*it,*it);//再找轻儿子
}
/*OK*/void FindTr(int u,int v)//寻找反转 
{
	int t1=top[u],t2=top[v];//取出top 
	while(t1!=t2)//爬树 
	{
		if(dep[t1]<dep[t2])swap(t1,t2),swap(u,v);//depth:t1>deph:t2
		tr.QueryTr(1,num[t1],num[u]);
		u=prt[t1],t1=top[u];
	}	
	if(dep[u]>dep[v])swap(u,v);//交换顺序 
	tr.QueryTr(1,num[son[u]],num[v]);
}
/*OK*/int FindMax(int u,int v)//u->v
{
	int t1=top[u],t2=top[v];//取出top 
	int Max=-0x7fffffff;
	while(t1!=t2)//爬树 
	{
		if(dep[t1]<dep[t2])swap(t1,t2),swap(u,v);//depth:t1>deph:t2
		Max=max(Max,tr.QueryMax(1,num[t1],num[u]));//求当前重链的最大值 
		u=prt[t1],t1=top[u];
	}
	if(u==v)return Max;//同一点的情况			
	if(dep[u]>dep[v])swap(u,v);//交换顺序 
	return max(Max,tr.QueryMax(1,num[son[u]],num[v]));
}
int N;
int x,y,z; 
/*OK*/int main(){
	N=GetInt();
	for(int i=1;i<=N-1;i++)
	{
		x=GetInt();
		y=GetInt();
		z=GetInt();
		a[x].push_back(y);
		a[y].push_back(x);
		data[i]=(node){x,y,z};
	}
	DFS1(1,0,1);
	DFS2(1,1);
	tr.Build(1,1,cnt);
	for(int i=1;i<=N-1;i++)
	{
		if(dep[data[i].x]<dep[data[i].y])swap(data[i].x,data[i].y);
		tr.Insert(1,num[data[i].x],data[i].z);
	}
	char ch[10];
	
	while(~scanf("%s",ch))
	{
		if(ch[0]=='D')break;
		x=GetInt();
		y=GetInt();
		if(ch[0]=='C')tr.Insert(1,num[data[x].x],y);
		if(ch[0]=='N')FindTr(x,y); 
		if(ch[0]=='Q')printf("%d\n",FindMax(x,y));
	}
	return 0;
}