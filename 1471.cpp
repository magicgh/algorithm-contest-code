#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
const int MAXN=50005;
inline int GetLL()
{
	long long num=0;int bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
struct splay_tree
{
	long long data[MAXN],prt[MAXN],l[MAXN],r[MAXN],ln[MAXN],rn[MAXN];
	long long root;
	splay_tree()
	{
		root=0;
		memset(data,0,sizeof(data));
		memset(prt,0,sizeof(prt));
		memset(l,0,sizeof(l));
		memset(r,0,sizeof(r));
		memset(ln,0,sizeof(ln));
		memset(rn,0,sizeof(rn));
	}
		inline void DFS(int u)
	{
		if(l[u]>0)DFS(l[u]);
		cout<<u<<"::"<<data[u]<<"->";
		if(r[u]>0)DFS(r[u]);
	}
	inline long long NodeNum(long long x)//返回x节点下的节点数
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
	inline void Zag(long long x)//左旋 
	{
		long long y=prt[x];
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
	inline void Splay(long long x)//伸展
	{
		while(prt[x])
		{
			long long u=prt[x];
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
		long long u=root;
		while(u)
		{
			if(x==data[u]){Splay(u);return 1;}//旋转至根节点 
			if(x<data[u])u=l[u];
			else u=r[u];		
		}
		return 0;//Not Found 
	}
	inline void Insert(long long x,long long d)//插入 
	{
		long long u=root,getfa=0;
		while(u)
		{
			getfa=u;
			if(x<=data[u])ln[u]++,u=l[u];
			else rn[u]++,u=r[u];
		}
		data[d]=x;	
		if(root==0){root=d;return;}//空树
		l[d]=0;r[d]=0;ln[d]=0;rn[d]=0;prt[d]=0;prt[d]=getfa;
		if(x<=data[getfa])l[getfa]=d;
		else r[getfa]=d;
		Splay(d);
	}
inline void Delete(long long x)//删除
	{
		Splay(x);//查找x 
		long long u=root;
		long long lch=l[u],rch=r[u];
		if(!lch&&!rch){root=0;return;}//无左右子树
		if(!lch)//无左子树
		{root=rch;prt[rch]=0;return;}
		if(!rch)//无右子树			
		{root=lch;prt[lch]=0;return;}
		//左右子树都有
		u=lch;//从左子树开始
		prt[lch]=0;
		while(r[u])u=r[u];//寻找x节点的前驱
		Splay(u);
		r[u]=rch;prt[rch]=u;
		rn[u]=NodeNum(rch);
	}
	inline long long FindOrder(long long k)//查找第K大 
	{
		int u=root;
		if(NodeNum(u)<k)return -1;
		while(true)
		{
			if(rn[u]+1==k)return data[u];
			if(rn[u]>=k)u=r[u];//右儿子寻找
			else //左儿子寻找
			{
				k=k-rn[u]-1;//ln[x]+rn[x]+1=NodeNum(x) 
				u=l[u];
			} 
		}
	}
	inline long long LowerBound(long long x)//前驱
	{
		Find(x);//查找x 
		long long u=l[root];//比x小(左) 
		while(u)//且最大(右) 
		{
		if(!r[u])break;//搜到叶子节点 
		u=r[u];
		}
		if(u)return data[u];
		return -1;//Not Found
	}
	inline long long UpperBound(long long x)//后驱
	{
		Find(x);//查找x 
		long long u=r[root];//比x大(右)
		while(u)//且最小(左) 
		{
		if(!l[u])break;//搜到叶子节点 
		u=l[u];
		}
		if(u)return data[u];
		return -1;//Not Found
		
	}
	inline long long Max(long long x)
	{
		long long u=root;
		while(r[u])u=r[u];//最大值向右找
		return data[u]; 
	}
	inline long long Min(long long x)
	{
		long long u=root;
		while(l[u])u=l[u];//最大值向左找
		return data[u];
	}
};
long long N,M;
long long x,a,b,c,cnt=0;
splay_tree tr;
int main(){
	N=GetLL();
	for(int i=1;i<=N;i++)
	{
		x=GetLL();;
		tr.Insert(x,i);cnt++;
	}
	M=GetLL();
	char ch;
	for(int i=1;i<=M;i++)
	{
		while(ch=getchar())if(ch=='C'||ch=='Q'||ch=='A')break;
		if(ch=='A')
		{
			a=GetLL();
			b=GetLL();
			c=tr.data[a];
			tr.Delete(a);
			cnt--;
			if(c-b>0)tr.Insert(c-b,a),cnt++;
		}
		if(ch=='C')
		{
			a=GetLL();
			b=GetLL();
			c=tr.data[a];
			tr.Delete(a);
			cnt--;
			if(c+b>0)tr.Insert(c+b,a),cnt++;
		}
		if(ch=='Q')
		{
			a=GetLL();
			printf("%lld\n",tr.FindOrder(a));
		}
	}
	printf("%lld",cnt);
	return 0;
}