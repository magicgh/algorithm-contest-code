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
const int MAXN=500005;
const ll INF=1e18;
vector<int>a[MAXN],b[MAXN];
struct stk
{
	int now,next;
	vector<int>::iterator it; 
};
stack<stk>ms;
stack<int>s;
deque<int>q;
ll Money[MAXN],value[MAXN],dist[MAXN],Max=-INF;
bool Pub[MAXN],Ins[MAXN],Cpub[MAXN],ext[MAXN];
int cnt,part,dfn[MAXN],low[MAXN],Belong[MAXN];
int n,m,st,p;
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void Tarjan(int now)
{
	vector<int>::iterator it;
	int next;
START:
	dfn[now]=low[now]=++cnt;
	s.push(now);Ins[now]=1;
	for(it=a[now].begin();it!=a[now].end();++it)
	{
		next=*it;
		if(!dfn[next])
		{
			ms.push((stk){now,next,it});
			now=next;
			goto START;
RET:		
			now=ms.top().now;
			next=ms.top().next;
			it=ms.top().it;
			ms.pop();
			low[now]=min(low[now],low[next]);
		}
		else if(Ins[next])low[now]=min(low[now],dfn[next]);
	}
	int t;
	if(dfn[now]==low[now])
	{
		part++;
		do
		{
			t=s.top();s.pop();Ins[t]=0;
			Belong[t]=part;
			value[part]+=Money[t];
			Cpub[part]=(Cpub[part]||Pub[t]);
		}
		while(t!=now);
	}
	if(!ms.empty())goto RET;
}
void SPFA(int v0)
{
	for(ri i=0;i<=part;i++)dist[i]=-INF;
	q.push_back(v0),dist[v0]=0;ext[v0]=1;
	while(!q.empty())
	{
		int now=q.front();q.pop_front();ext[now]=0;
		vector<int>::iterator it;
		for(it=b[now].begin();it!=b[now].end();++it)
		{
			if(dist[now]+value[*it]>dist[*it])
			{
				dist[*it]=dist[now]+value[*it];
				if(!ext[*it])
				{
					if(!q.empty()&&dist[q.front()]<dist[*it])q.push_front(*it);
					else q.push_back(*it);
					ext[*it]=1;
				}
			}
		}
	}
}
int main()
{
	n=getint(),m=getint();
	for(ri i=1;i<=m;i++)
	{
		int u=getint(),v=getint();
		a[u].push_back(v);
	}
	for(ri i=1;i<=n;i++)
		scanf("%lld",&Money[i]);
	st=getint(),p=getint();
	for(ri i=1;i<=p;i++)Pub[getint()]=1;
	for(ri i=1;i<=n;i++)
		if(!dfn[i])Tarjan(i);
	st=Belong[st];
	for(int u=1;u<=n;u++)
	{
		vector<int>::iterator it;
		for(it=a[u].begin();it!=a[u].end();++it)
		{
			if(Belong[u]==Belong[*it])continue;
			b[Belong[u]].push_back(Belong[*it]);
		}
	}
	b[0].push_back(st);
	SPFA(0);
	for(ri i=1;i<=part;i++)
		if(i!=st&&Cpub[i])Max=max(Max,dist[i]);
	printf("%lld\n",Max==-INF?0:Max);
	return 0;
}