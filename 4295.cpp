#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
const int MAXN=100005;
const int INF=0x7fffffff;
int root=0;
int prt[MAXN],s[MAXN],ch[MAXN][2],delta[MAXN],re[MAXN],maxx[MAXN],v[MAXN],sum[MAXN];
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline void Pushup(int x)
{
	int l=ch[x][0],r=ch[x][1];
	sum[x]=sum[l]+sum[r]+v[x];
	s[x]=s[l]+s[r]+1;
	maxx[x]=max(v[x],max(maxx[l],maxx[r]));
}
inline void Pushdown(int x)
{
	int l=ch[x][0],r=ch[x][1];
	if(delta[x]!=0)
	{
		if(l)delta[l]+=delta[x],maxx[l]+=delta[x],v[l]+=delta[x],sum[l]+=delta[x]*s[l];
		if(r)delta[r]+=delta[x],maxx[r]+=delta[x],v[r]+=delta[x],sum[r]+=delta[x]*s[r];
		delta[x]=0;
	}
	if(re[x])
	{
		re[x]=0;re[l]^=1;re[r]^=1;
		swap(ch[x][0],ch[x][1]);
	}
}
inline void Rotate(int x,int &fa){
	int y=prt[x],z=prt[y],l=(ch[y][0]!=x),r=l^1;
	if(fa==y)fa=x;
	else ch[z][ch[z][1]==y]=x;
	prt[x]=z,prt[y]=x,prt[ch[x][r]]=y;
	ch[y][l]=ch[x][r],ch[x][r]=y;
	Pushup(y);Pushup(x);
}
inline void Splay(int x,int &fa){
	while(x!=fa){
		if(prt[x]!=fa){
			if((ch[prt[x]][0]==x)^(ch[prt[prt[x]]][0]==prt[x]))Rotate(x,fa);
			else Rotate(prt[x],fa);//让位移动
		}
		Rotate(x,fa); 
	}
}
inline int Find(int x,int k)
{
	Pushdown(x);
	if(s[ch[x][0]]+1==k)return x;
	if(s[ch[x][0]]>=k)return Find(ch[x][0],k);
	else return Find(ch[x][1],k-s[ch[x][0]]-1);
}
inline void Reverse(int l,int r)
{
	int x=Find(root,l);
	int y=Find(root,r+2);
	Splay(x,root);Splay(y,ch[x][1]);
	x=ch[y][0];re[x]^=1;
}
inline int Sum(int l,int r)
{
	int x=Find(root,l);
	int y=Find(root,r+2);
	Splay(x,root);
	Splay(y,ch[x][1]);
	x=ch[y][0];
	return sum[x];		
}
inline int Max(int l,int r)
{
	int x=Find(root,l);
	int y=Find(root,r+2);
	Splay(x,root);Splay(y,ch[x][1]);
	x=ch[y][0];
	return maxx[x];
}
inline void Add(int l,int r,int value)
{
	int x=Find(root,l);
	int y=Find(root,r+2);
	Splay(x,root);	
	Splay(y,ch[x][1]);
	x=ch[y][0];
	delta[x]+=value;maxx[x]+=value;v[x]+=value;sum[x]+=value*s[x];
}
inline int Build(int l,int r)
{
	int mid=(l+r)>>1;
	if(l>r)return 0;
	ch[mid][0]=Build(l,mid-1);
	if(ch[mid][0])prt[ch[mid][0]]=mid;
	ch[mid][1]=Build(mid+1,r);
	if(ch[mid][1])prt[ch[mid][1]]=mid;
	Pushup(mid);
	return mid;
}
int N,M;
int main(){
		int a,b,c,k;
	N=GetInt();
	M=GetInt();
	root=Build(1,N+2);
	maxx[0]=-INF/2;
	for(int i=1;i<=N;i++)a=GetInt(),Add(i,i,a);
	for(int i=1;i<=M;i++)
	{
		k=GetInt();
		if(k==1)a=GetInt(),printf("%d\n",Sum(a,a));
		if(k==2)a=GetInt(),b=GetInt(),Add(a,a,b);
		if(k==3)a=GetInt(),b=GetInt(),printf("%d\n",Sum(a,b));
		if(k==4)a=GetInt(),b=GetInt(),printf("%d\n",Max(a,b));
		if(k==5)a=GetInt(),b=GetInt(),Reverse(a,b);
	}
	return 0;
}