#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define ri register int
#define ll long long
using namespace std;
const int INF=0x7fffffff/2;
int f[20005];
int n,m,Max=-INF;
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline void CompleteBag(int v,int p)
{
	for(ri i=v;i<=m;i++)
		f[i]=max(f[i],f[i-v]+p);
}
inline void ZOBag(int v,int p)
{
	for(ri i=m;i>=v;i--)
		f[i]=max(f[i],f[i-v]+p);
}
inline void MultiBag(int v,int p,int cnt)
{
	int k=1;
	if(v*cnt>m)CompleteBag(v,p);
	while(k<cnt)
	{
		ZOBag(k*v,k*p);
		cnt-=k;
		k<<=1;
	}
	ZOBag(cnt*v,cnt*p);
}
int main()
{
	n=getint(),m=getint();
	for(ri i=1;i<=n;i++)
	{
		int op=getint();
		if(op==1)
		{
			int A=getint(),B=getint();
			for(int x=0;x<=m;x++)ZOBag(x,A*x*x-B*x);
		}
		if(op==2)
		{
			int A=getint(),B=getint(),C=getint();
			MultiBag(B,A,C);
		}
		if(op==3)
		{
			int A=getint(),B=getint();
			CompleteBag(B,A);
		}
	}
	for(ri i=0;i<=m;i++)Max=max(f[i],Max);
	printf("%d",Max);
	return 0;
}

