#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define ri register int
using namespace std;
const int MAXN=100005;
const int INF=0x7fffffff/2;
int n,top,x[MAXN],h[MAXN],f[MAXN],L[MAXN],R[MAXN],C[MAXN],Stack[MAXN];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline int lowbit(const int &x){return x&(-x);}
inline int Min(const int &a,const int &b){return a<b?a:b;}
inline void Modify(int pos,int val)
{
	for(ri i=pos;i>=1;i-=lowbit(i))C[i]=min(C[i],val);
}
inline int Query(int pos)
{
	int Ans=INF;
	for(ri i=pos;i<=n;i+=lowbit(i))Ans=min(C[i],Ans);
	return Ans;
}
int main()
{
	n=getint();
	x[0]=-INF,x[n+1]=INF;
	for(ri i=1;i<=n;++i)
		x[i]=getint(),h[i]=getint(),C[i]=INF;
	Stack[top=1]=0;
	for(ri i=1;i<=n;++i)
	{
		while(top&&x[i]-x[Stack[top]]<=h[i])top--;
		L[i]=Stack[top]+1;
		Stack[++top]=i;
	}
	Stack[top=1]=n+1;
	for(ri i=n;i>=1;--i)
	{
		while(top&&x[Stack[top]]-x[i]<=h[i])top--;
		R[i]=Stack[top]-1;
		Stack[++top]=i;
	}
	for(ri i=1;i<=n;++i)
	{
		f[i]=Min(Min(f[L[i]-1],f[i-1])+1,Query(i));
		Modify(R[i],f[i-1]+1);
	}
	printf("%d\n",f[n]);
	return 0;
}