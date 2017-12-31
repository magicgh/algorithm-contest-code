#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define rui register unsigned int
using namespace std;
const int MAXN=2005;
const int INF=0x7fffffff;
struct Vector
{
	int x,y;
	Vector(int x=0,int y=0):x(x),y(y){};
};
vector<int>a[MAXN];
stack<int>s;
Vector p1,p2,lb[MAXN*2],hb[MAXN*2];
int n,like,hate,Min,Max,distwo,part,cnt;
int dist[MAXN],dfn[MAXN],low[MAXN],belong[MAXN];
bool ins[MAXN];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline int getdist(Vector pa,Vector pb){return abs(pa.x-pb.x)+abs(pa.y-pb.y);}
inline void Build(int k)
{
	for(rui i=0;i<=(n<<2)+1;i++)a[i].clear(),dfn[i]=low[i]=belong[i]=ins[i]=cnt=part=0;
	for(rui i=1;i<=hate;i++)//不喜欢的到不同的点 
	{
		a[hb[i].x].push_back(hb[i].y+n);
		a[hb[i].y+n].push_back(hb[i].x);
		a[hb[i].x+n].push_back(hb[i].y);
		a[hb[i].y].push_back(hb[i].x+n);
	}
	for(rui i=1;i<=like;i++)//喜欢的到相同的点 
	{
		a[lb[i].x].push_back(lb[i].y);
		a[lb[i].y].push_back(lb[i].x);
		a[lb[i].x+n].push_back(lb[i].y+n);
		a[lb[i].y+n].push_back(lb[i].x+n);
	}
	for(rui i=1;i<=n;i++)//枚举任意一对barn 
		for(rui j=1;j<=n;j++)
		{
			if(i==j)continue;
			if(dist[i]+dist[j]>k)//i->S1->j
				a[i].push_back(j+n);
			if(dist[i+n]+dist[j+n]>k)//i->S2->j
				a[i+n].push_back(j);
			if(dist[i]+distwo+dist[j+n]>k)//i->S1->S2->j
				a[i].push_back(j);
			 if(dist[i+n]+distwo+dist[j]>k)//j->S1->S2->i
				a[i+n].push_back(j+n);
		}
}
inline bool check()
{
	for(int i=1;i<=n;i++)if(belong[i]==belong[n+i])return false;
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
int Binary()//二分求下界 
{	
	int l=0,r=Max<<4,ans=-1;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		Build(mid);
		for(rui i=1;i<=(n<<1);i++)if(!dfn[i])Tarjan(i);
		if(check())ans=mid,r=mid-1;
		else l=mid+1;
	}
	return ans;
}
int main()
{
	n=getint(),hate=getint(),like=getint();
	p1=(Vector){getint(),getint()},p2=(Vector){getint(),getint()};
	distwo=getdist(p1,p2),Max=-INF,Min=INF;
	for(rui i=1;i<=n;i++)
	{	
		Vector p=(Vector){getint(),getint()};
		dist[i]=getdist(p,p1),dist[i+n]=getdist(p,p2);
		Min=min(Min,min(dist[i],dist[i+n]));
		Max=max(Max,max(dist[i],dist[i+n]));
	}
	for(rui i=1;i<=hate;i++)hb[i]={getint(),getint()};
	for(rui i=1;i<=like;i++)lb[i]={getint(),getint()};
	printf("%d",Binary());
	return 0;
}