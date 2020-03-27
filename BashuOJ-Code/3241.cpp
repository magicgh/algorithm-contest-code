#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
const int MAXN=100005;
int root=0;
int prt[MAXN],s[MAXN],ch[MAXN][2],re[MAXN];
int N,M;
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
	s[x]=s[l]+s[r]+1;
}
inline void Pushdown(int x)
{
	int l=ch[x][0],r=ch[x][1];
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
int main(){
	int k,l,r,v;
	N=GetInt();
	M=GetInt();
	root=Build(1,N+2);
	for(int i=1;i<=M;i++)
	{
		l=GetInt();
		r=GetInt();
		Reverse(l,r);
	}
	for(int i=2;i<=N+1;i++)printf("%d ",Find(root,i)-1);
	return 0;
}