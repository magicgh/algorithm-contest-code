#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#define ri register int
using namespace std;
map<long long,long long>mmp;
long long P,B,N; 
int t;
inline long long getll()
{
	long long num=0;
	int bj=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{ 
		if(c==EOF)return EOF;
		bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	} 
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline long long Pow(long long a,long long b,long long p)
{
	long long ret=1,base=a;
	while(b)
	{
		if(b&1)ret=(ret*base)%p;
		base=(base*base)%p;
		b>>=1;
	}
	return ret;
}
void BSGS(long long a,long long b,long long p)
{
	a%=p;
	if(!a&&!b){printf("1\n");return;}
	if(!a){printf("no solution\n");return;}
	long long m=ceil(sqrt(p)),t=1;
	mmp.clear();mmp[1]=m+1;
	for(long long i=1;i<m;i++)
	{
		t=t*a%p;
		if(!mmp[t])mmp[t]=i;
	}
	long long tmp=Pow(a,p-m-1,p);t=1;
	for(long long k=0;k<m;k++)
	{
		long long i=mmp[b*t%p];
		if(i){printf("%lld\n",(i==m+1)?k*m:k*m+i);return;}
		t=t*tmp%p;
	}
	printf("no solution\n");
}
int main()
{
	while(~(P=getll()))
	{
		B=getll(),N=getll();
		BSGS(B,N,P);
	}
	return 0;
}