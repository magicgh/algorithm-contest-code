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
const int MAXN=100005;
int c[5],tot,s,d[5];
ll Ans,f[MAXN];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void DFS(int k,bool bj,int sum)
{
	if(sum<0)return;
	if(k==5)
	{
		if(bj)Ans-=f[sum];
		else Ans+=f[sum];
		return;
	}
	DFS(k+1,bj^1,sum-(d[k]+1)*c[k]);
	DFS(k+1,bj,sum);
}
int main()
{
	for(ri i=1;i<=4;i++)c[i]=getint();
	f[0]=1;
	for(ri i=1;i<=4;i++)
		for(ri j=c[i];j<=100000;j++)f[j]+=f[j-c[i]];
	tot=getint();
	for(ri i=1;i<=tot;i++)
	{
		Ans=0;
		for(ri i=1;i<=4;i++)d[i]=getint();
		s=getint();
		DFS(1,0,s);
		printf("%lld\n",Ans);
	}
	return 0;
}

