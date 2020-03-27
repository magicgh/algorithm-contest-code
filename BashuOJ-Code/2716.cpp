#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<list>
using namespace std;
struct node
{
	int x,y;
};
node data[80005];
int son[80005],prt[80005],dep[80005],num[80005],fnum[80005],s[80005],top[80005];
int N,Q;
int cnt=0;
list<int>a[80005];
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
	int L[80005*4],R[80005*4],M[80005*4],S[80005*4],D[80005*4];
	inline void Build(int d,int l,int r)
	{	
		L[d]=l,R[d]=r,M[d]=-0x7fffffff,S[d]=0,D[d]=0;
		if(l==r)return;
		Build(d<<1,l,(l+r)>>1);
		Build(d<<1|1,((l+r)>>1)+1,r);
	}
	inline void Pushup(int v)
	{
	M[v]=max(M[v<<1],M[v<<1|1]);
	S[v]=S[v<<1]+S[v<<1|1];
	}
	inline void Modify(int v,int p,int d)
	{
		if(L[v]>p||R[v]<p)return;
		if(p==L[v]&&p==R[v]){M[v]=d;S[v]=d;D[v]=d;return;}
		Modify(v<<1,p,d);
		Modify(v<<1|1,p,d);
		Pushup(v);
	}
	inline int Query1(int v,int l,int r)
	{
		if(l>R[v]||L[v]>r)return -0x7fffffff;//Not Found
		if(l<=L[v]&&r>=R[v])return M[v];
		else return max(Query1(v<<1,l,r),Query1(v<<1|1,l,r));
	}
	inline int Query2(int v,int l,int r)
	{
		if(l>R[v]||L[v]>r)return 0;//Not Found
		if(l<=L[v]&&r>=R[v])return S[v];
		else return Query2(v<<1,l,r)+Query2(v<<1|1,l,r);
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
int Find1(int u,int v)//u->v
{
	int t1=top[u],t2=top[v];//取出top 
	int Max=-0x7fffffff;
	while(t1!=t2)//爬树 
	{
		if(dep[t1]<dep[t2])swap(t1,t2),swap(u,v);//depth:t1>deph:t2
		Max=max(Max,tr.Query1(1,num[t1],num[u]));//求当前重链的最大值 
		u=prt[t1],t1=top[u];
	}	
	if(dep[u]>dep[v])swap(u,v);//交换顺序 
	return max(Max,tr.Query1(1,num[u],num[v]));
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
	return sum+tr.Query2(1,num[u],num[v]);
}
int main(){
	int x,y,z;
	N=GetInt();	
	for(int i=1;i<=N-1;i++)
	{
		x=GetInt();
		y=GetInt();
		data[i].x=x,data[i].y=y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	DFS1(1,0,1);//depth,fa,node
	DFS2(1,1);//node,top
	tr.Build(1,1,cnt);
	for(int i=1;i<=N;i++)
	tr.Modify(1,num[i],GetInt());//点权！！！
	char k[10];		
	Q=GetInt();
	for(int i=1;i<=Q;i++)	
	{
		scanf("%s",&k);x=GetInt();y=GetInt();
		if(strcmp(k,"CHANGE")==0)tr.Modify(1,num[x],y);
		if(strcmp(k,"QMAX")==0)printf("%d\n",Find1(x,y));
		if(strcmp(k,"QSUM")==0)printf("%d\n",Find2(x,y));
	}
	return 0;
}