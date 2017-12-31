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
const int MAXN=75;
const ll Mod=10086ll;
ll n,m,t,Ans;
ll h[MAXN],f[MAXN][MAXN];
vector<int>a[MAXN];
struct Matrix
{
	static const int SIZE=80;
	int n,m;
	ll a[SIZE][SIZE];
	ll *operator[](const ll x){return a[x];}
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
		for(ri i=1;i<=n;i++)
			for(ri j=1;j<=b.m;j++)
				for(ri k=1;k<=m;k++)c[i][j]=(c[i][j]+a[i][k]*b[k][j]%Mod)%Mod;
		return c;
	}
	void operator *=(Matrix &b){*this=*this*b;}
	Matrix operator ^(ll &b)
	const
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
Matrix A(75,75),B(75,75);
inline const int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline const ll GetLL()
{
	ll num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
void ST1()
{
	f[0][1]=1;
	for(ri i=1;i<=70;i++)
	{
		for(ri j=1;j<=n;j++)
		{
			f[i][j]=f[i-1][j];
			vector<int>::iterator it;
			if(i<h[j])continue;
			for(it=a[j].begin();it!=a[j].end();++it)
				f[i][j]=(f[i][j]+f[i-1][*it])%Mod;
		}
	}
}
void ST2()
{
	for(ri j=1;j<=n;j++)
	{
		A[j][j]=1;
		B[j][j]=f[70][j];//自己到自己的方案 
		vector<int>::iterator it;
		for(it=a[j].begin();it!=a[j].end();++it)
			B[*it][j]=(B[*it][j]+f[70][*it])%Mod;
	}
	t-=71;
	A=(A^t);
	B*=A;
	for(ri i=1;i<=n;i++)
		Ans=(Ans+B[i][n])%Mod;
	printf("%lld\n",Ans);
}
int main()
{
	n=GetLL(),m=GetLL(),t=GetLL();
	for(ri i=1;i<=n;i++)h[i]=GetLL();
	for(ri i=1;i<=m;i++)
	{
		int u=GetInt(),v=GetInt();
		a[v].push_back(u);
		A[u][v]=(A[u][v]+1)%Mod;
	}
	ST1();
	if(t<=70)printf("%lld\n",f[t][n]);
	else ST2();
	return 0;
}