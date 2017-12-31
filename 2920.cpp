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
const int MAXN=10001;
const int INF=0x7fffffff;
struct node{int to,val;};
vector<node>a[MAXN];
deque<int>q;
int N,n,m,w[MAXN],s[MAXN],color[MAXN];
int dist[MAXN],used[MAXN];
bool ext[MAXN];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline int max(const int &x,const int &y){return x>y?x:y;}
inline int min(const int &x,const int &y){return x<y?x:y;}
inline void addedge(const int &x,const int &y,const int &z){a[x].push_back((node){y,z});}
bool SPFA(int v0)
{
	for(ri i=1;i<=N;i++)dist[i]=INF;
	q.push_front(v0),dist[v0]=0,ext[v0]=1;
	while(!q.empty())
	{
		int now=q.front();q.pop_front(),ext[now]=0;
		vector<node>::iterator it;
		for(it=a[now].begin();it!=a[now].end();++it)
		{
			if(dist[it->to]>dist[now]+it->val)
			{
				dist[it->to]=dist[now]+it->val;
				if(!ext[it->to])
				{
					if(++used[it->to]>=N)return 0;
					if(!q.empty()&&dist[q.front()]>dist[it->to])q.push_front(it->to);
					else q.push_back(it->to);
					ext[it->to]=1;
				}
			}
		}
	}
	return 1;
}
int main()
{
	n=getint(),m=getint(),N=n*2;
	for(ri i=1;i<=n;i++)color[i]=getint();
	for(ri i=1;i<=n;i++)w[i]=getint();
	for(ri i=1;i<=n;i++)s[i]=getint();
	for(ri i=1;i<=n;i++)//停留 
	{
		addedge(i,n+i,0);
		addedge(n+i,i,s[i]);	
	}
	for(ri i=1;i<=m;i++)
	{
		int u=getint(),v=getint(),k=getint();
		if(color[u]==color[v])//颜色相同 
		{
			addedge(u,v+n,k);
			addedge(u+n,v,k);
		}
		if(color[u]!=color[v])
		{
			int delta=abs(w[u]-w[v]);
			addedge(u,v,max(0,k-delta));	
			addedge(u+n,v+n,k+delta);
		}
	}
	SPFA(1+n*color[1]);
	printf("%d",min(dist[n],dist[N]));
	return 0;
}

