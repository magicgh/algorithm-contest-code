#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstring>
#include<queue>
#include<algorithm>
#include<vector>
#define ri register int
using namespace std;
const int MAXN=1005;
const int INF=0x7fffffff;
struct node{int to,v;};
struct heap
{
	int to,d,h;
	bool operator <(const heap& rhs)
	const{return h>rhs.h;};
};
vector<node>a[MAXN],b[MAXN]; 
int n,m,k,s,t,dist[MAXN];
bool ext[MAXN];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+c-'0',c=getchar();
	return num*bj;
}
void SPFA()
{
	queue<int>q;
	for(int i=1;i<=n;i++)dist[i]=INF;
	q.push(t);dist[t]=0;ext[t]=1;
	while(!q.empty())
	{
		int now=q.front();q.pop();ext[now]=0;
		vector<node>::iterator next;
		for(next=b[now].begin();next!=b[now].end();++next)
		{
			if(dist[now]+next->v<dist[next->to])
			{
				dist[next->to]=dist[now]+next->v;
				if(!ext[next->to])q.push(next->to),ext[next->to]=1;
			}
		}
	}
}
void A_Star()
{
	priority_queue<heap> pq;
	if(dist[s]==INF)
	{
		for(int i=1;i<=k;i++)printf("-1\n");
		return;
	}
	if(s==t)k++;
	pq.push((heap){s,0,dist[s]});
	int cnt=0;
	while(!pq.empty())
	{
		heap cur=pq.top();pq.pop();
		if(cur.to==t){cnt++;if(cnt<=k){printf("%d\n",cur.d);}if(cnt==k)return;}
		vector<node>::iterator it;
		for(it=a[cur.to].begin();it!=a[cur.to].end();++it)
		{
		pq.push((heap){it->to,cur.d+it->v,cur.d+it->v+dist[it->to]});
		}
	}
	printf("%d\n",-1);
}
int main()
{
	n=getint(),m=getint(),k=getint();
	s=n,t=1;
	for(ri i=1;i<=m;i++)
	{
		int x=getint(),y=getint(),z=getint();
		a[x].push_back((node){y,z});
		b[y].push_back((node){x,z});
	}
	SPFA();
	A_Star();
	return 0;
}

