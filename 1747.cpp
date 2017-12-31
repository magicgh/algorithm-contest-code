#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#define MOD 8191
using namespace std;
int n,x,y;//x,y,记录各组解 
struct matrix
{
	int m[5][5];
};
matrix d/*记录答案*/,per/*记录快速幂的初始化*/; 
inline void solve()
{
	for(y=1;;y++)//暴力求解佩尔方程 
	{
		x=sqrt(n*y*y+1.0);//精度处理 
		if(x*x-n*y*y==1)break;
	}
}
inline matrix Multi(matrix a,matrix b)//矩阵乘法a*b
{
	matrix c/*记录矩阵乘法的答案*/; 
	for(int i=0;i<2;i++)
	   for(int j=0;j<2;j++)
	   {
	   	c.m[i][j]=0;//初始化答案值
		for(int k=0;k<2;k++)
			c.m[i][j]+=(a.m[i][k]*b.m[k][j])%MOD;//注意是+=
			c.m[i][j]%=MOD;//再膜一次 
		} 
		return c;
} 
inline void init()
{
	d.m[0][0]=x%MOD;
	d.m[0][1]=y*n%MOD;
	d.m[1][0]=y%MOD;
	d.m[1][1]=x%MOD;
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)//快速幂的初始化
		per.m[i][j]=(i==j);/*if(i==j)per[i][j]=1;else per[i][j]=0;*/ 
}

inline matrix quick_mi(matrix a,int k)
{
	matrix ans=per;//ans记录结果 
	while(k)
	{
	if(k&1)ans=Multi(ans,a);
	a=Multi(a,a);
	k>>=1;
	}
	return ans;
}
int main(){
	int k;
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		int t=sqrt(n+0.0);//精度处理
		if(t*t==n)puts("No Answers");
		else
		{
			solve();//解佩尔方程 
			init();//初始化快速幂 
			d=quick_mi(d,k-1);//快速幂，d为答案的返回值
			x=(d.m[0][0]*x%MOD+d.m[0][1]*y%MOD)%MOD;
			printf("%d\n",x);
		}
	}
	return 0;
}
