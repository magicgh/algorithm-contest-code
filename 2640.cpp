#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<deque>
#include<stack>
#include<vector>
#define ri register int
using namespace std;
const int MAXN=100105;
const int INF=0x7fffffff;
vector<int>a[MAXN],b[MAXN];
int n,m,ans,p[MAXN],f[MAXN],g[MAXN],used[MAXN];
bool ext[MAXN];
deque<int>q;
inline int min(const int &t1,const int &t2){return t1<t2?t1:t2;}
inline int max(const int &t1,const int &t2){return t1>t2?t1:t2;}
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
bool SPFAx1(int v0)
{
	q.clear();
	for(ri i=1;i<=n;i++)f[i]=INF,ext[i]=used[i]=0;
	q.push_back(v0),f[v0]=p[v0],ext[v0]=1;
	while(!q.empty())
	{
		int now=q.front();q.pop_front(),ext[now]=0;
		vector<int>::iterator it;
		for(it=a[now].begin();it!=a[now].end();++it)
		{
			if(f[*it]>min(f[now],p[*it]))
			{
				f[*it]=min(f[now],p[*it]);
				if(!ext[*it])
				{
					if(++used[*it]>=n)return 0;
					if(!q.empty()&&f[q.front()]>f[*it])q.push_front(*it);
					else q.push_back(*it);
					ext[*it]=1;
				}
			}
		}
	}
	return 1;
}
bool SPFAx2(int v0)
{
	q.clear();
	for(ri i=1;i<=n;i++)g[i]=-INF,ext[i]=used[i]=0;
	q.push_back(v0),g[v0]=p[v0],ext[v0]=1;
	while(!q.empty())
	{
		int now=q.front();q.pop_front(),ext[now]=0;
		vector<int>::iterator it;
		for(it=b[now].begin();it!=b[now].end();++it)
		{
			if(g[*it]<max(g[now],p[*it]))
			{
				g[*it]=max(g[now],p[*it]);
				if(!ext[*it])
				{
					if(++used[*it]>=n)return 0;
					if(!q.empty()&&g[q.front()]<g[*it])q.push_front(*it);
					else q.push_back(*it);
					ext[*it]=1;
				}
			}
		}
	}
	return 1;
}
int main()
{
	n=getint(),m=getint();
	for(ri i=1;i<=n;i++)p[i]=getint();
	for(ri i=1;i<=m;i++)
	{
		int x=getint(),y=getint(),z=getint();
		if(z==1)a[x].push_back(y),b[y].push_back(x);
		if(z==2)a[x].push_back(y),a[y].push_back(x),b[x].push_back(y),b[y].push_back(x);
	}
	SPFAx1(1),SPFAx2(n);
	for(ri i=1;i<=n;i++)if(g[i]!=-INF&&f[i]!=INF)ans=max(ans,g[i]-f[i]);
	printf("%d",ans);
	return 0;
}
