#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<deque>
#define ri register int
using namespace std;
const int MAXN=1005;
const int INF=0x7fffffff/2;
struct heap{int v,t;};
deque<heap>q[MAXN];
int n,m,p,ans,a[MAXN][MAXN],cost[MAXN],f[MAXN][MAXN];
inline int Mod(int x){return (x%n+n)%n;}
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void DP()
{
	ans=-INF;
	for(ri i=0;i<n;i++)
	{
		f[0][Mod(i)]=a[0][Mod(i)]-cost[i];
		q[Mod(i)].push_back((heap){-cost[i],0});
		ans=max(ans,f[0][Mod(i)]);
	}
	for(ri i=1;i<m;i++)
	{
		int tmp=ans;
		for(ri j=0;j<n;j++)
		{
			if(q[Mod(j-i)].front().t<=i-p)q[Mod(j-i)].pop_front();
			while(!q[Mod(j-i)].empty()&&q[Mod(j-i)].back().v<=tmp-a[i-1][Mod(j-1)]-cost[j])q[Mod(j-i)].pop_back();
			q[Mod(j-i)].push_back((heap){tmp-a[i-1][Mod(j-1)]-cost[j],i});
			f[i][Mod(j)]=(!q[Mod(j-i)].empty()?q[Mod(j-i)].front().v:-INF)+a[i][Mod(j)];
			ans=max(f[i][Mod(j)],ans);
		}
	}
	printf("%d",ans);
}
int main()
{
	n=getint(),m=getint(),p=getint();
	for(ri i=0;i<n;i++)
		for(ri j=0;j<m;j++)a[j][Mod(i)]=getint();
	for(ri i=1;i<m;i++)
		for(ri j=0;j<n;j++)a[i][Mod(j)]+=a[i-1][Mod(j-1)];
	for(ri i=0;i<n;i++)cost[i]=getint();
	DP();
	return 0;
}
