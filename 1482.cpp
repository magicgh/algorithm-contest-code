#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
const int MAXN=100005;
int delta=0,N,M,Ans=0,n=0;
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
struct splay_tree
{
	int data[MAXN],prt[MAXN],l[MAXN],r[MAXN],ln[MAXN],rn[MAXN];
	int root,cnt;
	splay_tree()
	{
		root=0;cnt=0;
	}
		inline void DFS(int u)
	{
		if(l[u])DFS(l[u]);
		cout<<u<<"("<<data[u]<<")"<<"->";
		if(r[u])DFS(r[u]);
	}
	inline int NodeNum(int x)//返回x节点下的节点数
	{
		return ln[x]+rn[x]+1;
	}
inline void Zig(int x)//右旋 
	{
		int y=prt[x];
		l[y]=r[x];
		if(r[x])prt[r[x]]=y;
		prt[x]=prt[y];
		if(prt[y])
		{
			if(l[prt[y]]==y)l[prt[y]]=x;
			else r[prt[y]]=x;
		}
		prt[y]=x;r[x]=y;
		ln[y]=rn[x];rn[x]=NodeNum(y);
	}
	inline void Zag(int x)//左旋 
	{
		int y=prt[x];
		r[y]=l[x];
		if(l[x])prt[l[x]]=y;
		prt[x]=prt[y];
		if(prt[y])
		{
			if(l[prt[y]]==y)l[prt[y]]=x;
			else r[prt[y]]=x;
		}
		prt[y]=x;l[x]=y;
		rn[y]=ln[x];ln[x]=NodeNum(y);
	}
	inline void Splay(int x)//伸展
	{
		while(prt[x])
		{
			int u=prt[x];
			if(prt[u]==0)
			{
				if(x==l[u])Zig(x);
				else Zag(x);
				break;
			}
			if(x==l[u])
			{
				if(u==l[prt[u]])Zig(u),Zig(x);
				else Zig(x),Zag(x);
			}
			if(x==r[u])
			{
				if(u==l[prt[u]])Zag(x),Zig(x);
				else Zag(u),Zag(x);
			}
		}
		root=x;
	}
	inline bool Find(int x)//查找元素 
	{
		int u=root;
		while(u)
		{
			if(x==data[u]){Splay(u);return 1;}//旋转至根节点 
			if(x<data[u])u=l[u];
			else u=r[u];		
		}
		return 0;//Not Found 
	}
	inline void Insert(int x)//插入 
	{
		int u=root,getfa=0;
		while(u)
		{
			getfa=u;
			if(x<=data[u])ln[u]++,u=l[u];
			else rn[u]++,u=r[u];
		}
		data[++cnt]=x;	
		l[cnt]=0;r[cnt]=0;ln[cnt]=0;rn[cnt]=0;prt[cnt]=0;
		if(root==0){root=cnt;return;}//空树
		prt[cnt]=getfa;
		if(x<=data[getfa])l[getfa]=cnt;
		else r[getfa]=cnt;
		Splay(cnt);
	}
inline void Delete(int x)
{
	int getfa=0,u=root;
	while(u)
	{
		
		if(data[u]<x)getfa=u,u=r[u];
		else u=l[u];
	}
	if(!getfa)return;
	Splay(getfa);
	Ans+=NodeNum(root)-rn[root];
	root=r[root];
	prt[root]=0;
	
}
	inline int FindOrder(int k)//查找第K大 
	{
		int u=root;
		if(NodeNum(u)<k)return -1;
		while(true)
		{
			if(rn[u]+1==k)return data[u]<M-delta?-1:data[u]+delta;
			if(rn[u]>=k)u=r[u];//右儿子寻找
			else //左儿子寻找
			{
				k=k-rn[u]-1;//ln[x]+rn[x]+1=NodeNum(x) 
				u=l[u];
			} 
		}
	}
	inline int LowerBound(int x)//前驱
	{
		Find(x);//查找x 
		int u=l[root];//比x小(左) 
		while(u)//且最大(右) 
		{
		if(!r[u])break;//搜到叶子节点 
		u=r[u];
		}
		if(u)return data[u];
		return -1;//Not Found
	}
	inline int UpperBound(int x)//后驱
	{
		Find(x);//查找x 
		int u=r[root];//比x大(右)
		while(u)//且最小(左) 
		{
		if(!l[u])break;//搜到叶子节点 
		u=l[u];
		}
		if(u)return data[u];
		return -1;//Not Found
		
	}
	inline int Max(int x)
	{
		int u=root;
		while(r[u])u=r[u];//最大值向右找
		return data[u]; 
	}
	inline int Min(int x)
	{
		int u=root;
		while(l[u])u=l[u];//最大值向左找
		return data[u];
	}
};
splay_tree tr;
int main(){
	int k;
	N=GetInt();
	M=GetInt();
	char ch;
	for(int i=1;i<=N;i++)
	{
		while(ch=getchar())if(ch=='I'||ch=='A'||ch=='S'||ch=='F')break;
		k=GetInt();
		if(ch=='I'&&k>=M)n++,tr.Insert(k-delta);	
		if(ch=='A')delta+=k;
		if(ch=='S')delta-=k,tr.Delete(M-delta);
		if(ch=='F'){
			if(n-Ans-k+1<=0)printf("-1\n");
			else printf("%d\n",tr.FindOrder(k));
		}
	}
	printf("%d\n",Ans);
	return 0;
}