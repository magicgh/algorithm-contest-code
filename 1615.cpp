#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
const int MAXN=500005;
const int Mod=51061;
typedef unsigned int INT;
int N,M;
inline INT GetInt()
{
	INT num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
struct LCT{
	INT prt[MAXN],ch[MAXN][2],val[MAXN],plus[MAXN],multi[MAXN],cnt[MAXN],ans[MAXN];
	bool aux[MAXN],rev[MAXN];
	void Init(){for(int i=1;i<=N;i++)val[i]=multi[i]=cnt[i]=ans[i]=1;}
	inline void Calc(INT x,INT a,INT b)
	{
		val[x]=(val[x]*a+b)%Mod;
		ans[x]=(ans[x]*a+b*cnt[x])%Mod;
		plus[x]=(plus[x]*a+b)%Mod;
		multi[x]=(multi[x]*a)%Mod;
	}
	inline void Pushup(INT x)
	{
		cnt[x]=cnt[ch[x][0]]+cnt[ch[x][1]]+1;
		ans[x]=(val[x]+ans[ch[x][0]]+ans[ch[x][1]])%Mod; 
	}
	inline void Pushdown(INT x){
		if(rev[x]){
			swap(ch[x][0],ch[x][1]);
			rev[ch[x][0]]^=1,rev[ch[x][1]]^=1,rev[x]=0;
		}
		if(multi[x]!=1||plus[x]!=0)
		{
		Calc(ch[x][0],multi[x],plus[x]);
		Calc(ch[x][1],multi[x],plus[x]);
		multi[x]=1;plus[x]=0;
		}
		
	}
	inline void Rotate(INT x){
		INT y=prt[x],z=prt[y],l=(ch[y][0]!=x),r=l^1;
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

	inline void Access(INT x,INT y){
		if(!x)return;
		Splay(x);
		aux[ch[x][1]]=0;
		prt[y]=x;ch[x][1]=y;aux[y]=1;
		Pushup(x);
		Access(prt[x],x); 
	}
	inline void Reverse(INT x){
		Access(x,0);
		Splay(x);
		rev[x]^=1;
	}
	inline void Link(INT x,INT y){
		Reverse(x);
		prt[x]=y;
	}
	inline void Modify(INT x,INT y,INT a,INT b){
		Reverse(x);Access(y,0);
		Splay(y);Calc(y,a,b);
		}
	inline void Split(INT x,INT y){
		Reverse(x);
		Access(y,0);
		Splay(y);
		ch[y][0]=aux[ch[y][0]]=prt[ch[y][0]]=0;
	} 
	inline INT Findroot(INT x){
		Access(x,0);
		Splay(x);
		while(ch[x][0])x=ch[x][0];
		return x;
	} 
};
LCT tr;
int main(){
	INT x,y,c,d;
	N=GetInt();
	M=GetInt();
	tr.Init(); 
	for(int i=1;i<N;i++)tr.Link(GetInt(),GetInt());
	char ch;
	for(int i=1;i<=M;i++)
	{
		while(ch=getchar())if(ch=='+'||ch=='-'||ch=='*'||ch=='/')break;
		switch(ch)
		{
			case '+':
			x=GetInt();y=GetInt();c=GetInt();
			tr.Modify(x,y,1,c);break;
			case '-':
			x=GetInt();y=GetInt();c=GetInt();d=GetInt();
			tr.Split(x,y);tr.Link(c,d);break;
			case '*':
			x=GetInt();y=GetInt();c=GetInt();
			tr.Modify(x,y,c,0);break;
			case '/':
			x=GetInt(),y=GetInt();
			tr.Modify(x,y,1,0);printf("%u\n",tr.ans[y]);break;
		}
	}
	return 0;
}