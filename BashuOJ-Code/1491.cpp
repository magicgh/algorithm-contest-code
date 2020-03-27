#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
long long n,a,b;
struct Matrix
{
	long long v[3][3];
};
Matrix e,w1,w2,w;
inline Matrix Multi_Matrix(Matrix a,Matrix b)
{
	Matrix ans;
	memset(ans.v,0,sizeof(ans.v));
	for(int i=1;i<=2;i++)
	for(int j=1;j<=2;j++)
	for(int k=1;k<=2;k++)ans.v[i][j]=(ans.v[i][j]+a.v[i][k]*b.v[k][j])%10000;
	return ans;
}
inline void quickmi(Matrix a,long long m,int d)
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
	if(d==1)memcpy(w1.v,b.v,sizeof(b.v));
	if(d==2)memcpy(w2.v,b.v,sizeof(b.v));
}
int main(){
	e.v[1][1]=0;e.v[1][2]=e.v[2][1]=e.v[2][2]=1;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		memset(w1.v,0,sizeof(w1.v));
		memset(w2.v,0,sizeof(w2.v));
		scanf("%lld%lld",&a,&b);a--;
		quickmi(e,a,1);
		quickmi(e,b,2);
		printf("%lld\n",(10000+(w2.v[1][2]+w2.v[2][2])%10000-(w1.v[1][2]+w1.v[2][2])%10000)%10000);
	}
	return 0;
}