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
const int MAXN=300005;
const double PI=3.14159265358979323846264338327950288419716939937510;
int Q,N;
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
	inline void FFT(int M,int bj)
	{
		int i,j,k,m;
		complex<double>t0,t1;
		for(i=0;i<M;i++)
		{
			for(j=0,k=i,m=1;m<M;m<<=1,j=((j<<1)|(k&1)),k>>=1);
			if(i<j)swap(num[i],num[j]);
		}
		base[0]=1;
		for(m=1;m<M;m<<=1)
		{
			t0=exp(complex<double>(0,bj*PI/m));
			for(i=1;i<m;i++)base[i]=base[i-1]*t0;
			for(k=0;k<M;k+=(m<<1))
				for(i=k;i<k+m;i++)
					t0=num[i],t1=base[i-k]*num[i+m],num[i]=t0+t1,num[i+m]=t0-t1;
		}
		if(bj==1)return;
		for(i=0;i<M;i++)num[i]*=(1.0/M);
	}
};
Fourier f1,f2,g,ans1,ans2;
int main()
{
	double q;
	Q=getint();
	for(ri i=0;i<Q;i++)
	{
		scanf("%lf",&q);
		f1[i]=q,f2[Q-i-1]=q;
	}
	for(int i=1;i<=Q;i++)g[i]=(1.0/i/i);
	for(N=1;N<=2*Q;N<<=1);
	f1.FFT(N,1),f2.FFT(N,1),g.FFT(N,1);
	for(ri i=0;i<N;i++)ans1[i]=f1[i]*g[i];
	for(ri i=0;i<N;i++)ans2[i]=f2[i]*g[i];
	ans1.FFT(N,-1),ans2.FFT(N,-1);
	for(ri i=0;i<Q;i++)
		printf("%.3lf\n",ans1[i].real()-ans2[Q-i-1].real());
	return 0;
}
