#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<complex>
#define ri register int
using namespace std;
const int MAXN=250005;
const double PI=3.1415926535;
int n,N,ans[MAXN],last;
complex<double>base[MAXN];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
struct Fourier
{
	complex<double>num[MAXN];
	complex<double> &operator[](int pos){return num[pos];}
	inline void Input()
	{
		for(ri i=0;i<n;i++)
		{
			char ch;
			while(ch=getchar())if(isdigit(ch))break;
			num[n-i-1]=ch-'0';//倒序存储 
		}
	}
	inline void FFT(int M,int bj)//bj=-1为IDFT 
	{
		int i,j,k,m;//(i,j)->pos,k二进制的当前位,m限制位数范围(分治m次的结果) 
		complex<double>t0,t1;
		for(i=0;i<M;i++)
		{
			for(j=0,k=i,m=1;m<M;m<<=1,j=((j<<1)|(k&1)),k>>=1);
			if(i<j)swap(num[i],num[j]);//小于交换 
		}
		base[0]=1;
		for(m=1;m<M;m<<=1)//开始分治
		{
			t0=exp(complex<double>(0,bj*PI/m));//算出单位根
			for(i=1;i<m;i++)base[i]=t0*base[i-1];//算出单位根的m次幂
			for(k=0;k<M;k+=m<<1)//分块的起始位置
				for(i=k;i<k+m;i++)//分块的区间
					t0=num[i],t1=base[i-k]*num[i+m],num[i]=t0+t1,num[i+m]=t0-t1;
		}
		if(bj==1)return;//FFT
		for(int i=0;i<M;i++)num[i]*=(1.0/M);//IDFT *(1/n) 
	}
};
Fourier a,b,c;
int main()
{
	n=getint();
	a.Input(),b.Input();
	for(N=1;N<2*n;N<<=1);//最接近n的2的幂,分治的份数 
	a.FFT(N,1),b.FFT(N,1);
	for(ri i=0;i<N;i++)c[i]=a[i]*b[i];
	c.FFT(N,-1);//IDFT
	for(ri i=0;i<N;i++)ans[i]=int(c[i].real()+0.3);//防炸精度
	for(ri i=0;i<N;i++)
		ans[i+1]+=ans[i]/10,ans[i]%=10,last=ans[i]?i:last;
	for(ri i=last;i>=0;i--)printf("%d",ans[i]);	
	return 0;
}

