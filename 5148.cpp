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
const int MAXN=500005;
ll n,List[MAXN],C[MAXN],p[MAXN],sum[MAXN],Max[MAXN];
inline const int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline const ll GetLL()
{
	ll num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline ll lowbit(ll &x){return x&(-x);}
inline void Add(ll pos,ll val)
{
	for(ll i=pos;i<=n;i+=lowbit(i))C[i]+=val;
}
inline ll Query(ll pos)
{
	ll ret=0;
	for(ll i=pos;i>=1;i-=lowbit(i))ret+=C[i];
	return ret;
}
inline void Maintain(ll pos,ll cnt)
{
	ll x=pos,y;
	while(x<n&&(n-x-1)*(n-x)/2>=cnt)x++;
	y=cnt-(n-x-1)*(n-x)/2;
	swap(List[x],List[x+y]);//多出y个逆序对 
	sort(List+x+1,List+n+1,greater<int>());//使后面产生最多的逆序对 
}
int main()
{
	n=GetLL();
	for(ri i=1;i<=n;i++)List[i]=GetLL();
	for(ri i=n;i>=1;i--)
	{
		sum[i]=sum[i+1]+(p[i]=Query(List[i]));
		Add(List[i],1),Max[i]=max(Max[i+1],List[i]);
	}
	for(ri i=n;i>=1;i--)
	{
		if(List[i]<Max[i]&&p[i]+1<=sum[i])
		{
			ll pos=0;
			for(ri j=i+1;j<=n;j++)
				if(List[j]>List[i]&&(List[pos]>List[j]||!pos))pos=j;
			swap(List[i],List[pos]);
			sort(List+i+1,List+n+1);
			Maintain(i+1,sum[i]-(p[i]+1));
			break;
		}
	}
	for(ri i=1;i<=n;i++)printf("%lld ",List[i]);
	return 0;
}
