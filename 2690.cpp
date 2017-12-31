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
const int MAXN=72;
const ll INF=1e18;
struct Tree{ll val,key,vst;};
Tree a[MAXN];
int n,KeyL;
ll k,Ans=INF,s[MAXN],Num[MAXN],f[MAXN][MAXN][MAXN];
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline const ll getll()
{
	ll num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline bool cmp(const Tree &a,const Tree &b){return a.val<b.val;}
inline ll DP(int l,int r,int Limit)
{
	if(l>r)return 0;
	if(f[l][r][Limit]!=INF)return f[l][r][Limit];
	if(f[l][r][Limit]>Ans)return INF;
	for(ri mid=l;mid<=r;mid++)
	{
		f[l][r][Limit]=min(f[l][r][Limit],DP(l,mid-1,Limit)+DP(mid+1,r,Limit)+s[r]-s[l-1]+k);
		if(a[mid].key>=Limit)
			f[l][r][Limit]=min(f[l][r][Limit],DP(l,mid-1,a[mid].key)+DP(mid+1,r,a[mid].key)+s[r]-s[l-1]);
	}
	return f[l][r][Limit];
}
int main()
{
	n=getint(),k=getll();
	for(ri i=1;i<=n;i++)
		a[i].val=getll();
	for(ri i=1;i<=n;i++)
		a[i].key=getll();
	for(ri i=1;i<=n;i++)
		a[i].vst=getll();
	sort(a+1,a+n+1,cmp);
	for(ri i=1;i<=n;i++)
	{
		Num[i]=a[i].key;
		s[i]=s[i-1]+a[i].vst;
	}
	sort(Num+1,Num+n+1);
	KeyL=unique(Num+1,Num+n+1)-(Num+1);
		for(ri j=0;j<=n;j++)
			for(ri k=0;k<=n;k++)
				for(ri p=0;p<=KeyL;p++)
					f[j][k][p]=INF;
	for(ri i=1;i<=n;i++)
		a[i].key=lower_bound(Num+1,Num+KeyL+1,a[i].key)-Num;
		Ans=min(Ans,DP(1,n,1));
	printf("%lld\n",Ans);	
	return 0;
}
