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
const int MAXN=300005;
struct node{int x,y;};
node a[MAXN];
int n,b[MAXN];
ll C[MAXN],ans;
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline bool cmp(const node &a,const node &b){return (a.x==b.x&&a.y<b.y)||(a.x<b.x);}
inline int lowbit(int x){return x&(-x);}
inline void add(int x,int val)
{
	for(ri i=x;i<=n;i+=lowbit(i))C[i]+=val;
}
inline ll query(int x)
{
	ll ans=0;
	for(ri i=x;i>0;i-=lowbit(i))ans+=C[i];
	return ans;
}
int main()
{
	n=getint();
	for(ri i=1;i<=n;i++)
	{
		int x=getint(),y=getint();
		a[i]=(node){x,y},b[i]=y;
	}
	sort(a+1,a+n+1,cmp);
	sort(b+1,b+n+1);
	for(ri i=1;i<=n;i++)
		a[i].y=lower_bound(b+1,b+n+1,a[i].y)-b;//原值
	for(ri i=1;i<=n;i++)
	{
		ans+=query(n)-query(a[i].y);
		add(a[i].y,1);
	}
	printf("%lld",ans);
	return 0;
}