#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define ri register int
#define ll long long
using namespace std;
const ll Mod=1000000007;
ll n,m,Ans;
inline const ll GetLL()
{
	ll num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
struct Matrix
{
	static const int SIZE=105;
	int n,m;
	ll a[SIZE][SIZE];
	Matrix(int n,int m)
	{
		this->n=n,this->m=m;
		memset(a,0,sizeof(a));
	}
	inline void Unit(){for(ri i=1;i<=n;i++)a[i][i]=1;}
	Matrix operator *(Matrix &b)
	{
		Matrix c(n,b.m);
		for(ri i=1;i<=n;i++)
			for(ri j=1;j<=b.m;j++)
				for(ri k=1;k<=m;k++)
					c.a[i][j]=(c.a[i][j]+a[i][k]*b.a[k][j]%Mod)%Mod;
		return c;
	}
	Matrix operator ^(ll &b)
	{
		Matrix ret(n,m),base=*this;
		ret.Unit();
		while(b)
		{
			if(b&1)ret=ret*base;
			base=base*base;
			b>>=1;
		}
		return ret;
	}
};
Matrix A(100,100);
int main()
{
	n=GetLL(),m=GetLL();
	for(ri i=1;i<=m;i++)
	{
		for(ri j=2;j<=i;j++)A.a[i][j]=1;
		if(i!=m)A.a[i][i+1]=m-(i-1);
	}
	A=(A^n);
	for(ri i=2;i<=m;i++)Ans=(Ans+A.a[1][i])%Mod;
	printf("%lld\n",Ans);
	return 0;
}


