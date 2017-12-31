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
const int MAXN=500005;
ll Ans,sum[MAXN];
int n,k,l,r;
int Maxpos[MAXN][21];
struct heap
{
	int i,l,r,j;
	bool operator <(const heap &rhs)
	const{return sum[j]-sum[i-1]<sum[rhs.j]-sum[rhs.i-1];}
};
priority_queue<heap>q;
inline int min(const int &a,const int &b){return a<b?a:b;}
inline int max(const int &a,const int &b){return a>b?a:b;}
inline ll min(const ll &a,const ll &b){return a<b?a:b;}
inline ll max(const ll &a,const ll &b){return a>b?a:b;}
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void ST()
{
	for(ri i=1;i<=n;i++)Maxpos[i][0]=i;
	int k=log2(n);
	for(ri j=1;j<=k;j++)
		for(ri i=1;i+(1<<j)-1<=n;i++)
		{
			int L=Maxpos[i][j-1],R=Maxpos[i+(1<<(j-1))][j-1];
			Maxpos[i][j]=sum[L]>sum[R]?L:R;
		}
}
inline int Query(int l,int r)
{
	if(l==r)return l;
	int k=log2(r-l+1);
	int L=Maxpos[l][k],R=Maxpos[r-(1<<k)+1][k];
	return sum[L]>sum[R]?L:R;
}
void Solve()
{
	for(ri i=1;i<=n;i++)
	{
		int L=i+l-1,R=min(i+r-1,n);
		if(L<=n)q.push((heap){i,L,R,Query(L,R)});
	}
	for(ri i=1;i<=k;i++)
	{
		heap now=q.top();q.pop();
		Ans+=sum[now.j]-sum[now.i-1];
		if(now.l<now.j)q.push((heap){now.i,now.l,now.j-1,Query(now.l,now.j-1)});
		if(now.j<now.r)q.push((heap){now.i,now.j+1,now.r,Query(now.j+1,now.r)});
	}
}
int main()
{
	n=getint(),k=getint(),l=getint(),r=getint();
	for(ri i=1;i<=n;i++)
	{
		ll x;
		scanf("%lld",&x);
		sum[i]=sum[i-1]+x;
	}
	ST(),Solve();
	printf("%lld\n",Ans);
	return 0;
}