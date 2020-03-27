#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1005;
const double eps=1e-8;
int N,K;
double a[MAXN],b[MAXN];
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+c-'0',c=getchar();
	return num*bj;
}
inline double judge(double k)
{
	double c[MAXN],ret=0;
	for(int i=1;i<=N;i++)c[i]=a[i]-k*b[i];
	sort(c+1,c+N+1);
	for(int i=K+1;i<=N;i++)ret+=c[i];
	return ret;
}
int main(){
	while(true)
	{
		N=GetInt(),K=GetInt();
		if(N==0&&K==0)break;
		for(int i=1;i<=N;i++)a[i]=(double)GetInt();
		for(int i=1;i<=N;i++)b[i]=(double)GetInt();
		double l=0.0,r=1.0;
		while(r-l>eps)
		{
			double mid=(l+r)/2.0;
			if(judge(mid)<=0)r=mid;
			else l=mid;
		}
		printf("%d\n",int(l*100+0.5));
	}
	return 0;
}