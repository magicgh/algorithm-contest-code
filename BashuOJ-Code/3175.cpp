#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
const int MAXN=500005;
int N,M;
struct Stack
{
	int S[MAXN];
	inline void push(int x){S[++S[0]]=x;}
	inline void pop(){--S[0];}
	inline bool empty(){return S[0]==0;}
	inline int& top(){return S[S[0]];}
};
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+c-'0',c=getchar();
	return num*bj;
}
struct LCT{
	Stack s;
	int prt[MAXN],ch[MAXN][2],sum[MAXN],dist[MAXN];
	bool aux[MAXN],rev[MAXN];
	inline void Pushup(int x){sum[x]=sum[ch[x][0]]+sum[ch[x][1]]+1;}
	inline void Pushdown(int x){
		if(rev[x]){
			swap(ch[x][0],ch[x][1]);
			rev[ch[x][0]]^=1,rev[ch[x][1]]^=1,rev[x]=0;
		}
	}
	inline void Rotate(int x){
		int y=prt[x],z=prt[y],l=(ch[y][0]!=x),r=l^1;
		if(aux[y])ch[z][!(ch[z][0]==y)]=x;
		else aux[y]=1,aux[x]=0;
		prt[x]=z,prt[y]=x,prt[ch[x][r]]=y;
		ch[y][l]=ch[x][r],ch[x][r]=y;
		Pushup(y);Pushup(x);
	}
	
	inline void Splay(int x){
		s.push(x);
		for(int i=x;aux[i];i=prt[i])s.push(prt[i]);
		while(!s.empty())Pushdown(s.top()),s.pop();
		while(aux[x]){
			int y=prt[x],z=prt[y];
			if(aux[y]){if(ch[y][0]==x^ch[z][0]==y)Rotate(x);else Rotate(y);}
			Rotate(x);
		}
	}
	inline void Access(int x,int y){
		if(!x)return;
		Splay(x);
		aux[ch[x][1]]=0;
		prt[y]=x;ch[x][1]=y;aux[y]=1;
		Pushup(x);
		Access(prt[x],x); 
	}
	inline void Reverse(int x){
		Access(x,0);
		Splay(x);
		rev[x]^=1;
	}
	inline void Link(int x,int y){
		Reverse(x);
		prt[x]=y;
	}
	inline void Modify(int x,int v){
		Reverse(x);
		Splay(x);
		Pushup(x);
	}
	inline void Cut(int x,int y){
		Reverse(x);
		Access(y,0);
		Splay(y);
		ch[y][0]=aux[ch[y][0]]=prt[ch[y][0]]=0;
	} 
	inline int Findroot(int x){
		Access(x,0);
		Splay(x);
		while(ch[x][0])
		{
			x=ch[x][0];
			Pushdown(x); 
		}
		return x;
	} 
};
LCT tr;
int main(){
	N=GetInt();
	for(int i=1;i<=N;i++)
	{
	tr.dist[i]=GetInt();
	tr.Link(i,min(i+tr.dist[i],N+1));
	}
	M=GetInt();
	int opt,x,y;
	for(int i=1;i<=M;i++)
	{
		opt=GetInt();
		if(opt==1)
		{
			x=GetInt()+1;
			tr.Reverse(x);
			tr.Access(N+1,0);
			tr.Splay(N+1);
			printf("%d\n",tr.sum[N+1]-1);
		}
		if(opt==2)
		{
			x=GetInt()+1;
			y=GetInt();
			tr.Cut(x,min(x+tr.dist[x],N+1));
			tr.dist[x]=y;
			tr.Link(x,min(x+tr.dist[x],N+1));
		}
	}	
	return 0;
}
