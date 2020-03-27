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
const int Mod=30031;
const int MAXN=130;
int N,K,P,Pow[11]={1},S[MAXN],cnt;
struct Matrix
{
	static const int SIZE=150;
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
		for(ri i=1;i<=n;i++)
			for(ri j=1;j<=b.m;j++)
				for(ri k=1;k<=m;k++)
					c[i][j]=(c[i][j]+a[i][k]*b[k][j]%Mod)%Mod;
		return c;
					
	}
	void operator *=(Matrix &a){*this=*this*a;}
	Matrix operator ^(int b)
	const
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
	void operator ^=(int b){*this=*this^b;}
};
Matrix A(MAXN,MAXN),B(MAXN,MAXN); 
inline int lowbit(int x){return x&(-x);}
void DFS(int station,int bus,int sta)//当前在第i个站，启用了j辆巴士，停靠信息为sta（枚举所有状态） 
{
	if(bus==K)
	{
		S[++cnt]=sta;
		return;
	} 
	for(ri i=station-1;i>=1;i--)DFS(i,bus+1,sta+Pow[i-1]);//Pow[0]=1,Pow[1]=10;
}
void Init()
{
	for(ri i=1;i<=cnt;i++)
		for(ri j=1;j<=cnt;j++)
		{
			int x=(((S[i]<<1)^Pow[P])^S[j]);//(S[i]<<1)^Pow[P](强行去掉最高位) ^S[j]找不同
			if(x==lowbit(x))B[i][j]=1;//两种方案只有一个站有区别，即可转移 
		}
}
inline const int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
int main()
{
	N=GetInt(),K=GetInt(),P=GetInt();
	for(ri i=1;i<=P;i++)Pow[i]=Pow[i-1]<<1;
	DFS(P,1,Pow[P-1]);//最后一个站强制停
	Init();A[1][1]=1;
	B^=(N-K),A*=B;//转移N-K次 
	printf("%d\n",A[1][1]);
	return 0;
}

