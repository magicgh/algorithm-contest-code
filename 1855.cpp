#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
long long n,m;
struct Matrix
{
	int v[3][3];
};
Matrix e,w;
inline Matrix Multi_Matrix(Matrix a,Matrix b)
{
	Matrix ans;
	memset(ans.v,0,sizeof(ans.v));
	for(int i=1;i<=2;i++)
	for(int j=1;j<=2;j++)
	for(int k=1;k<=2;k++)ans.v[i][j]=(ans.v[i][j]+a.v[i][k]*b.v[k][j])%1729;
	return ans;
}
inline void quickmi(Matrix a)
{
	Matrix b;
	memset(b.v,0,sizeof(b.v));
	for(int i=1;i<=2;i++)b.v[i][i]=1;
	while(m>0)
	{	
		if(m&1)b=Multi_Matrix(b,a);
	    a=Multi_Matrix(a,a);
		m>>=1;
	}
	memcpy(w.v,b.v,sizeof(b.v));
}
int main(){
	while(scanf("%lld",&n)!=EOF)
	{
		e.v[1][1]=0;e.v[1][2]=e.v[2][1]=e.v[2][2]=1;
		m=n-2;
		quickmi(e);
		printf("%d\n",(w.v[1][2]+w.v[2][2])%1729);
	}
	return 0;
}
