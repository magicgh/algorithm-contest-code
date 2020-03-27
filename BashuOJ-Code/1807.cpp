#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int N,M;
const int MAXN=500005;
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
struct LCT{
	int prt[MAXN],ch[MAXN][2],val[MAXN],sum[MAXN];
	bool rev[MAXN];
	inline bool isroot(int x){return !(ch[prt[x]][0]==x||ch[prt[x]][1]==x);}
	inline void Pushup(int x){sum[x]=val[x]+sum[ch[x][0]]+sum[ch[x][1]];}
	inline void Pushdown(int x){
		if(rev[x]){
			swap(ch[x][0],ch[x][1]);
			rev[ch[x][0]]^=1,rev[ch[x][1]]^=1,rev[x]=0;
		}
	}
	inline void Rotate(int x){
		int y=prt[x],z=prt[y],l=(ch[y][0]!=x),r=l^1;
		if(!isroot(y))ch[z][!(ch[z][0]==y)]=x;
		prt[x]=z,prt[y]=x,prt[ch[x][r]]=y;
		ch[y][l]=ch[x][r],ch[x][r]=y;
		Pushup(y);Pushup(x);
	}
	inline void Splay(int x){
		Pushdown(x);
		while(!isroot(x)){
			int y=prt[x],z=prt[y];
			if(!isroot(y))Pushdown(z);
			Pushdown(y);Pushdown(x);
			if(!isroot(y)){if(ch[y][0]==x^ch[z][0]==y)Rotate(x);else Rotate(y);}
			Rotate(x);
		}
	}
	inline void Access(int x){
		int t=0;
		while(x)
		{
		Splay(x);
		ch[x][1]=t;
		Pushup(x);
		t=x;x=prt[x];
		}
	}
	inline void Reverse(int x){
		Access(x);
		Splay(x);
		rev[x]^=1;
	}
	inline void Link(int x,int y){
		Reverse(x);
		prt[x]=y;
		Splay(x);
	}
	inline void Modify(int x,int v){
		Reverse(x);
		Splay(x);
		val[x]=v;
		Pushup(x);
	}
	inline int Findroot(int x){
		Access(x);
		Splay(x);
		while(ch[x][0])x=ch[x][0];
		return x;
	} 
};
LCT tr;
bool Bind(int x,int y){return tr.Findroot(x)==tr.Findroot(y);}
int main(){
	N=GetInt();
	for(int i=1;i<=N;i++)tr.sum[i]=tr.val[i]=GetInt();
	M=GetInt();
	char ch[15];
	int x,y;
	for(int i=1;i<=M;i++)
	{
		scanf("%s",ch);
		x=GetInt();
		y=GetInt();
		if(ch[0]=='b')
		{
			if(Bind(x,y))printf("no\n");
			else
			{
				printf("yes\n");
				tr.Link(x,y);
			}
		}
		if(ch[0]=='p')tr.Modify(x,y);
		if(ch[0]=='e')
		{
			if(!Bind(x,y))printf("impossible\n");
			else tr.Reverse(x),tr.Access(y),tr.Splay(y),printf("%d\n",tr.sum[y]);
		}
	}
	return 0;
}