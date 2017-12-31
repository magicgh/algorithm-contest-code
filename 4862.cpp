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
const int MAXN=2005;
stack<int>s;
struct Point{int x,y;};
vector<int>a[MAXN];
Point b[MAXN];
int n,cnt=1,mark,part;
ll Max,dist[MAXN][MAXN];
int dfn[MAXN],low[MAXN],Belong[MAXN];
bool Ins[MAXN];
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline ll Getdist(int i,int j)
{
	ll ax=(ll)b[i].x,ay=(ll)b[i].y,bx=(ll)b[j].x,by=(ll)b[j].y;
	return (ax-bx)*(ax-bx)+(ay-by)*(ay-by);
}
void Tarjan(int u)
{
	dfn[u]=low[u]=++mark;
	s.push(u);Ins[u]=1;
	vector<int>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(!dfn[*it])
		{
			Tarjan(*it);
			low[u]=min(low[u],low[*it]);
		}
		else if(Ins[*it])
			low[u]=min(low[u],dfn[*it]);
	}
	int t;
	if(dfn[u]==low[u])
	{
		part++;
		do
		{
			t=s.top();s.pop();Ins[t]=0;
			Belong[t]=part;
		}
		while(t!=u);
	}
}
inline bool Check(ll Limit)
{
	while(!s.empty())s.pop();
	for(ri i=0;i<=cnt;i++)
		dfn[i]=low[i]=Belong[i]=mark=part=0,Ins[i]=false,a[i].clear();
	for(ri i=2;i<=cnt;i++)
		for(ri j=2;j<=cnt;j++)
			if((i^1)!=j&&i!=j&&dist[i][j]<Limit)
				a[i].push_back(j^1);
	for(ri i=2;i<=cnt;i++)if(!dfn[i])Tarjan(i);
	for(ri i=2;i<=cnt;i++)
		if(Belong[i]==Belong[i^1])return 0;
	return 1;
}
inline ll Binary()
{
	ll l=0,r=Max;
	while(l<=r)
	{
		ll mid=(l+r)>>1;
		if(Check(mid))l=mid+1;
		else r=mid-1;
	}
	return r;
}
int main()
{
	n=getint();
	for(ri i=1;i<=n;i++)
	{
		int x=getint(),y=getint(),d=getint();
		b[++cnt]=(Point){x,y-d};
		b[++cnt]=(Point){x,y+d};
	}
	for(ri i=2;i<cnt;i++)
		for(ri j=i+1;j<=cnt;j++)
		{
			dist[i][j]=dist[j][i]=Getdist(i,j);
			Max=max(Max,dist[i][j]);
		}
	printf("%lld\n",Binary());
	return 0;
}
