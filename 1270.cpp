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
int n,k,a[45],Ans[45],f[2005],Max=-INF;
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline int DP(int m)
{
	int i;
	for(i=1;i<=2000;i++)f[i]=41;f[0]=0;
	for(i=0;;i++)
	{
		if(f[i]>n)break;
		for(ri j=1;j<=m;j++)f[i+a[j]]=min(f[i]+1,f[i+a[j]]);
	}
	return i-1;
}
void DFS(int x)
{
	int cur_ans=DP(x-1);
	if(x==k+1)
	{
		if(cur_ans>Max){Max=cur_ans;memcpy(Ans,a,sizeof(a));}
		return;
	}
	for(ri i=a[x-1]+1;i<=cur_ans+1;i++)
	{
		a[x]=i;
		DFS(x+1);
	}
}
int main()
{
	n=getint(),k=getint();
	a[1]=1,DFS(2);
	for(ri i=1;i<=k;i++)printf("%d ",Ans[i]);
	printf("\nMAX=%d\n",Max);
	return 0;
}

