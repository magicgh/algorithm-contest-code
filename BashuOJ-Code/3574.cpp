#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<stack>
#include<vector>
#define rui register unsigned int
using namespace std;
const int MAXN=825;
struct point{int x,y;};
stack<int>s;
vector<int>a[MAXN];
int n,m,cnt,part;
int dfn[MAXN],low[MAXN],belong[MAXN];
bool ins[MAXN];
point door[MAXN],key[MAXN];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline void AddEdge(int x,int y){a[x].push_back(y);}
inline void Build(int k)
{
	for(rui i=0;i<4*n+1;i++)a[i].clear(),dfn[i]=low[i]=belong[i]=ins[i]=cnt=part=0;
	while(!s.empty())s.pop();
	for(rui i=1;i<=n;i++)AddEdge(key[i].x,key[i].y+(n<<1)),AddEdge(key[i].y,key[i].x+(n<<1));//钥匙对应门 
	for(rui i=1;i<=k;i++)AddEdge(door[i].x+(n<<1),door[i].y),AddEdge(door[i].y+(n<<1),door[i].x);//门对应钥匙
}
inline bool check()
{
	for(int i=1;i<=(n<<1);i++)if(belong[i]==belong[(n<<1)+i])return false;
	return true;
}
inline void Tarjan(int x)
{
	dfn[x]=low[x]=++cnt;
	s.push(x),ins[x]=1;
	vector<int>::iterator it;
	for(it=a[x].begin();it!=a[x].end();++it)
	{
		if(!dfn[*it])Tarjan(*it),low[x]=min(low[x],low[*it]);
		else if(ins[*it])low[x]=min(low[x],dfn[*it]);
	}
	if(low[x]==dfn[x])
	{
		int u;part++;
		do u=s.top(),s.pop(),ins[u]=0,belong[u]=part;
		while(u!=x);
	}
}
inline int Binary()//二分求上界 
{
	int l=0,r=m;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		Build(mid);
		for(int i=1;i<=(n<<2);i++)if(!dfn[i])Tarjan(i);
		if(check())l=mid+1; 
		else r=mid-1;
	} 
	return r;
}
int main()
{
	n=getint(),m=getint();
	for(rui i=1;i<=n;i++)key[i]=(point){getint()+1,getint()+1};
	for(rui i=1;i<=m;i++)door[i]=(point){getint()+1,getint()+1};
	printf("%d",Binary());
	return 0;
}
