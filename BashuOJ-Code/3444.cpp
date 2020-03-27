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
const int Mod=2012;
struct Matrix
{
	static const int SIZE=35;
	int n,m,a[SIZE][SIZE];
	int *operator[](int x){return a[x];}
	Matrix(int n,int m)
	{
		this->n=n,this->m=m;
		memset(a,0,sizeof(a));
	}
	inline void Unit(){for(ri i=1;i<=n;i++)a[i][i]=1;}
	Matrix operator +(Matrix b)
	{
		if(n!=b.n||m!=b.m)throw exception();
		Matrix c(n,m);
		for(ri i=1;i<=n;i++)
			for(ri j=1;j<=m;j++)c[i][j]=(a[i][j]+b[i][j])%Mod;
		return c;
	}
	Matrix operator -(Matrix b)
	{
		if(n!=b.n||m!=b.m)throw exception();
		Matrix c(n,m);
		for(ri i=1;i<=n;i++)
			for(ri j=1;j<=m;j++)c[i][j]=a[i][j]-b[i][j];
		return c;
	}
	Matrix operator *(Matrix b)
	{
		Matrix c(n,b.m);
		for(ri i=1;i<=n;i++)
			for(ri j=1;j<=b.m;j++)
				for(ri k=1;k<=m;k++)c[i][j]=(c[i][j]+a[i][k]*b[k][j])%Mod;
		return c;
	}
	void operator *=(Matrix &b){*this=*this*b;}
	Matrix operator ^(int b)
	{
		Matrix ret(n,m),base=*this;ret.Unit();
		while(b)
		{
			if(b&1)ret*=base;
			base*=base;
			b>>=1;
		}
		return ret;
	}
};
int n,k;
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
Matrix Sum(Matrix A,int k)
{
	if(k==1)return A;
	Matrix E(n,n);E.Unit();
	if(k&1)return (E+(A^(k>>1)))*Sum(A,k>>1)+(A^k);
	else return (E+(A^(k>>1)))*Sum(A,k>>1);
}
int main()
{
	n=getint(),k=getint();
	Matrix A(n,n);
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=n;j++)
		{
			int x=getint();
			A[i][j]=x%Mod;
		}
	A=(A^9)*Sum(A,k);
	for(ri i=1;i<=n;i++)
	{
		for(ri j=1;j<=n;j++)printf("%d ",A[i][j]%Mod);
		printf("\n");
	}
	return 0;
}

