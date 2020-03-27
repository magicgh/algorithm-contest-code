#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<vector>
#include<stack>
#define ri register int
#define ll long long
using namespace std;
const int MAXN=205;
const double INF=1e18;
double p[MAXN],map[MAXN][MAXN];
int N,T;
namespace FastIO
{
    const ll L=1<<15;
    char buffer[L],*S,*T;
    inline char getchar()
	{
        if(S==T){T=(S=buffer)+fread(buffer,1,L,stdin);if(S==T)return EOF;}
		return *S++;
    }
	inline int GetInt()
	{
		ri num=0,bj=1;
		register char c=getchar();
		while(!isdigit(c))bj=(bj==-1||c=='-')?-1:1,c=getchar();
		while(isdigit(c))num=num*10+c-'0',c=getchar();
		return num*bj;
	}
	inline bool GetDouble(double &num)    
	{  
	    register char c=getchar();
		double Dec=0.1;  
	    bool is_n=0,is_d=0;  
	    if(c==EOF)return 0;  
	    while(c!='-'&&c!='.'&&!isdigit(c))c=getchar();  
	    if(c=='-')is_n=1,num=0;
	    else if(c=='.')is_d=1,num=0;
	    else num=c-'0';  
	    if(!is_d)
	        while(c=getchar(),isdigit(c))num=num*10+c-'0'; 
	    if(c!='.'){if(is_n)return num*=-1,1;}
		else
		{  
	        while(c=getchar(),isdigit(c))
	        	num+=Dec*(c-'0'),Dec*=0.1;  
	    }  
	    if(is_n)num*=-1; 
	    return 1;  
	}  
};
struct Matrix
{
	static const int SIZE=205;
	int n,m;
	double a[SIZE][SIZE];
	double *operator[](int x){return a[x];}
	Matrix(int n,int m)
	{
		this->n=n,this->m=m;
		memset(a,0,sizeof(a));
	}
	inline void Unit(){for(ri i=1;i<=n;i++)a[i][i]=1.0;}
	Matrix operator *(Matrix &b)
	const
	{
		Matrix c(n,b.m);
		for(ri i=1;i<=n;i++)
			for(ri j=1;j<=b.m;j++)
				for(ri k=1;k<=m;k++)c[i][j]=(c[i][j]+a[i][k]*b[k][j]);
		return c;
	}
	void operator *=(Matrix &b){*this=*this*b;}
	Matrix operator ^(int &b)
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
using FastIO::GetInt;
using FastIO::GetDouble;
int main()
{
	N=GetInt(),T=GetInt();
	for(ri i=1;i<=N;i++)
		GetDouble(p[i]);
	for(ri i=1;i<=N;i++)
		for(ri j=1;j<=N;j++)
			GetDouble(map[i][j]);
	for(ri k=1;k<=N;k++)
		for(ri i=1;i<=N;i++)
			for(ri j=1;j<=N;j++)
				map[i][j]=min(map[i][j],map[i][k]+map[k][j]);
	for(ri i=1;i<=N;i++)
	{
		double sum=0;
		for(ri j=1;j<=N;j++)
			sum+=map[i][j];
		for(ri j=1;j<=N;j++)
			map[i][j]/=sum;
	}		
	Matrix A(N,N);
	for(ri i=1;i<=N;i++)	
		for(ri j=1;j<=N;j++)
			A[i][j]=map[i][j];
	A=(A^T);
	for(ri i=1;i<=N;i++)
	{
		double sum=0;
		for(ri j=1;j<=N;j++)
			sum+=p[j]*A[j][i];
		printf("%.6lf\n",sum);
	}
		return 0;
}
