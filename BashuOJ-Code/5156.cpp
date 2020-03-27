#include<iostream>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<vector>
#include<stack>
#include<map>
#define ri register int
#define ll long long
#define pii pair<int,int>
#define mp make_pair
using namespace std;
const int MAXN=100005;
int n,k,cnt;
ll a[MAXN],s[MAXN],List[MAXN];
map<pii,bool>Hash;
struct heap
{
	int l,r;ll val;
	bool operator <(const heap &rhs)
	const{return val<rhs.val;}
};
priority_queue<heap>q;
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(bj==-1||c=='-')?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
int main()
{
	n=GetInt(),k=GetInt();
	for(ri i=1;i<=n;i++)a[i]=GetInt(),s[i]=s[i-1]+a[i];
	q.push((heap){1,n,s[n]});
	while(!q.empty())
	{
		heap now=q.top();q.pop();
		if(Hash[mp(now.l,now.r)])continue;
		Hash[mp(now.l,now.r)]=1,List[++cnt]=now.val;
		if(cnt==k)break;
		if(now.l==now.r)continue;
		q.push((heap){now.l+1,now.r,s[now.r]-s[now.l]});
		q.push((heap){now.l,now.r-1,s[now.r-1]-s[now.l-1]});
	}
	sort(List+1,List+cnt+1,greater<ll>());
	for(ri i=1;i<=cnt;i++)printf("%lld ",List[i]);
	return 0;
}
