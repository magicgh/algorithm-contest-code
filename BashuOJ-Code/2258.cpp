#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
long long n,k,ans=0;
struct Matrix
{
	long long v[15][15];
};
Matrix e,f,w;
inline Matrix Multi_Matrix(Matrix a,Matrix b,int d)
{
	Matrix ans;
	memset(ans.v,0,sizeof(ans.v));
	if(d==0)
	{
	for(int i=0;i<=n;i++)
	for(int j=0;j<=n;j++)
	for(int k=0;k<=n;k++)ans.v[i][j]=(ans.v[i][j]+a.v[i][k]*b.v[k][j])%9973;
	}
	if(d==1)
	{
	for(int i=0;i<=0;i++)
	for(int j=0;j<=n;j++)
	for(int k=0;k<=n;k++)ans.v[i][j]=(ans.v[i][j]+a.v[i][k]*b.v[k][j])%9973;
	}
	return ans;
}
inline void quickmi(Matrix a,long long m)
{
	Matrix b;
	memset(b.v,0,sizeof(b.v));
	for(int i=0;i<=n;i++)b.v[i][i]=1;
	while(m>0)
	{	
		if(m&1)b=Multi_Matrix(b,a,0);
	    a=Multi_Matrix(a,a,0);
		m>>=1;
	} 
	w=Multi_Matrix(f,b,1);
}
int main(){
	scanf("%lld%lld",&n,&k);
	for(int i=0;i<=n;i++)scanf("%lld",&e.v[i][n-1]);
	for(int i=0;i<=n-2;i++)e.v[i+1][i]=1;
	e.v[n][n]=1;
    for(int i=0;i<=n-1;i++)scanf("%lld",&f.v[0][i]);
    f.v[0][n]=1;
    quickmi(e,k-n+1);
	printf("%lld",(w.v[0][n-1]+9973)%9973); 
	return 0;
}