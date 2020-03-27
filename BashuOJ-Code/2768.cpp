#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<vector>
using namespace std;
const int MAXN=80005*4;
int N,M,Ans=0;
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
struct LCT{
	int prt[MAXN],ch[MAXN][2],val[MAXN],Max[MAXN];
	bool aux[MAXN],rev[MAXN];
	LCT(){for(int i=0;i<=N;i++)Max[i]=-0x7fffffff;}
	inline void Pushup(int x){Max[x]=max(val[x],max(Max[ch[x][0]],Max[ch[x][1]]));}
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
		Pushdown(x);
		while(aux[x]){
			int y=prt[x],z=prt[y];
			if(aux[y])Pushdown(z);
			Pushdown(y);Pushdown(x);
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
		val[x]=v;
		Pushup(x);
	}
};
LCT tr;
int main(){
	int x,y,z;
	N=GetInt();M=GetInt();
	for(int i=1;i<N;i++)
	{
		x=GetInt();y=GetInt();z=GetInt();
		tr.Link(y,N+i);tr.Link(N+i,x);
		tr.Modify(N+i,z);
	}
	for(int i=1;i<=M;i++)
	{
		x=GetInt();y=GetInt();z=GetInt();
		if(x==0)tr.Modify(N+y,z);
		if(x==1)
		{
			if(y==z)printf("-1\n");
			else tr.Reverse(y),tr.Access(z,0),tr.Splay(z),printf("%d\n",tr.Max[z]);
		}
	}
	return 0;
}