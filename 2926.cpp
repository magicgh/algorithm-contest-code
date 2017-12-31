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
const int MAXN=10005*2;
const ll INF=1e20;
ll h[MAXN],a[MAXN],f[MAXN][3],Ans=INF;
int n,m;
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}	
void DP(int pos)
{
	for(ri i=pos;i<=n+pos;i++)h[i-pos+1]=a[i];
	f[1][0]=f[1][1]=0;//0上1下
	for(ri i=2;i<=n+1;i++)
	{
		if(h[i]>h[i-1])//向上
		{
			ll delta=abs(h[i]-h[i-1]);
			f[i][0]=min(f[i-1][0]+delta,f[i-1][1]+m+delta);
			f[i][1]=min(f[i-1][1]+delta*delta,f[i-1][0]+m+delta*delta);
		}
		else
		{
			ll delta=abs(h[i-1]-h[i]);
			f[i][1]=min(f[i-1][1]+delta,f[i-1][0]+m+delta);
			f[i][0]=min(f[i-1][0]+delta*delta,f[i-1][1]+m+delta*delta);		
		}
	}
	Ans=min(Ans,min(f[n+1][0],f[n+1][1]));
}
int main()
{
	n=getint(),m=getint();
	for(ri i=1;i<=n;i++)
		scanf("%lld",a+i),a[n+i]=a[i];
	ll Max=a[1],Min=a[1],Maxp=1,Minp=1;
	for(ri i=2;i<=n;i++)
	{
		if(Max<a[i])Max=a[i],Maxp=i;
		if(Min>a[i])Min=a[i],Minp=i;
	}
	DP(Minp);
	printf("%lld",Ans);
	return 0;
}
