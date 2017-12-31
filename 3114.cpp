#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define ri register int
#define ll long long
using namespace std;
const int MAXN=205;
const int INF=0x7fffffff/2;
struct node{int x,y,z;};
node a[MAXN];
int Ori[MAXN];
int n,t,s,e,cnt;
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
struct Matrix
{
	static const int SIZE=205;
	int n,m,a[SIZE][SIZE];
	int *operator[](int x){return a[x];}
	Matrix(int n,int m)
	{
		this->n=n,this->m=m;
		memset(a,0,sizeof(a));
	}
	inline void Unit(){for(ri i=1;i<=n;i++)a[i][i]=1;}
	Matrix operator *(Matrix &b)
	const
	{
		Matrix c(n,b.m);
		for(ri i=1;i<=c.n;i++)
			for(ri j=1;j<=c.m;j++)c[i][j]=INF;
		for(ri i=1;i<=n;i++)
			for(ri j=1;j<=b.m;j++)
				for(ri k=1;k<=m;k++)c[i][j]=min(c[i][j],a[i][k]+b[k][j]);
		return c;
	}
	void operator *=(Matrix &b){*this=*this*b;}
	inline Matrix Pow(Matrix &base,int b)
	{
		Matrix ret=*this;
		while(b)
		{
			if(b&1)ret*=base;
			base*=base;
			b>>=1;
		}
		return ret;
	}
};
int main()
{
	n=GetInt(),t=GetInt(),s=GetInt(),e=GetInt();
	for(ri i=1;i<=t;i++)
	{
		int z=GetInt(),x=GetInt(),y=GetInt();
		a[i]=(node){x,y,z};
		Ori[++cnt]=x,Ori[++cnt]=y;
	}
	sort(Ori+1,Ori+cnt+1);
	cnt=unique(Ori+1,Ori+cnt+1)-(Ori+1);//离散化 
	Matrix A(cnt,cnt),B(cnt,cnt);
	s=lower_bound(Ori+1,Ori+cnt+1,s)-Ori;
	e=lower_bound(Ori+1,Ori+cnt+1,e)-Ori;
	for(ri i=1;i<=t;i++)
	{
		a[i].x=lower_bound(Ori+1,Ori+cnt+1,a[i].x)-Ori;
		a[i].y=lower_bound(Ori+1,Ori+cnt+1,a[i].y)-Ori;
		B[a[i].x][a[i].y]=B[a[i].y][a[i].x]=a[i].z;
	}
	for(ri i=1;i<=cnt;i++)
		for(ri j=1;j<=cnt;j++)
		{
			if(!B[i][j])B[i][j]=INF; 
			A[i][j]=B[i][j];//复制 
		}
	A=A.Pow(B,n-1);
	printf("%d\n",A[s][e]);
	return 0;
}

