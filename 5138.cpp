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
const int MAXN=15;
vector<ll>a[MAXN];
int n,m,k;
ll sum; 
struct heap
{
	int x,y;ll val;
	bool operator <(const heap &rhs)
	const{return val>rhs.val;}
};
priority_queue<heap>q;
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
int main()
{
	m=GetInt(),k=GetInt();
	for(ri i=1;i<=m;i++)
	{
		n=GetInt();
		for(ri j=1;j<=n;j++)
			a[i].push_back(GetLL());
		sort(a[i].begin(),a[i].end());
		sum+=a[i][0];
	}
	q.push((heap){1,0,sum});
	for(ri cnt=1;cnt<k;cnt++)
	{
		heap now=q.top();q.pop();
		if(now.y<a[now.x].size()-1)
			q.push((heap){now.x,now.y+1,now.val-a[now.x][now.y]+a[now.x][now.y+1]});
		for(ri i=now.x+1;i<=m;i++)
			if(a[i].size()>1)q.push((heap){i,1,now.val-a[i][0]+a[i][1]});
	}
	printf("%lld\n",q.top().val);
	return 0;
}


