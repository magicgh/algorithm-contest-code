#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define ri register int
#define ll long long
using namespace std;
const int MAXN=100005;
const int INF=0x7fffffff;
int n,Ans,tot,a[MAXN],b[MAXN],L[MAXN],R[MAXN],Hash[MAXN];
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
void LIS()
{
	int len=0;
	for(ri i=1;i<=n;i++)
	{
		int pos=lower_bound(b+1,b+len+1,a[i])-b;
		L[i]=pos;
		if(a[i]>b[len])b[++len]=a[i];
		else b[pos]=a[i];
	}
	Ans=len;
	printf("%d\n",Ans);
}
void AntiLIS()
{
	int len=0;
	for(ri i=0;i<=n;i++)b[i]=-INF;
	for(ri i=n;i>=1;i--)
	{
		int pos=lower_bound(b+1,b+len+1,a[i])-b;
		R[i]=pos;
		if(a[i]>b[len])b[++len]=a[i];
		else b[pos]=a[i];
	}
}
int main()
{
	n=getint();
	for(ri i=1;i<=n;i++)a[i]=getint();
	LIS();
	for(ri i=1;i<=n;i++)a[i]=-a[i];
	AntiLIS();
	for(ri i=1;i<=n;i++)
		if(L[i]+R[i]-1==Ans)Hash[L[i]]++;
	for(ri i=1;i<=n;i++)
		if(L[i]+R[i]-1==Ans&&Hash[L[i]]==1)a[++tot]=i;
	for(ri i=1;i<=tot;i++)printf("%d ",a[i]);
	return 0;
}

