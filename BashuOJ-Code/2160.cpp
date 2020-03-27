#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<bitset>
#define ri register int
using namespace std;
const int MAXN=55;
const int INF=0x7fffffff;
struct node{int to,v;};
struct heap
{
	int to,f,h;
	string s;
	bitset<55>used;
	bool operator <(const heap& rhs)
	const{return (h==rhs.h&&s>rhs.s)||(h>rhs.h);}
};
vector<node>a[MAXN],b[MAXN];
int dist[MAXN];
bool ext[MAXN];
int n,m,k,s,t;
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+c-'0',c=getchar();
	return num*bj;
}
void BellmanFord()
{
	deque<int>q;
	for(int i=1;i<=n;i++)dist[i]=INF;
	q.push_back(t),dist[t]=0,ext[t]=1;
	while(!q.empty())
	{
		int now=q.front();q.pop_front();ext[now]=0;
		vector<node>::iterator next;
		for(next=b[now].begin();next!=b[now].end();++next)
		{
			if(dist[next->to]>dist[now]+next->v)
			{
				dist[next->to]=dist[now]+next->v;
				if(!ext[next->to])
				{
					if(!q.empty()&&dist[q.front()]>dist[next->to])q.push_front(next->to);
					else q.push_back(next->to);
					ext[next->to]=1;
				}
			}
		}
	}
}
void Astar()
{
	priority_queue<heap> q;
	if(s==t)k++;
	if(dist[s]==INF){printf("No\n");return;}
	heap tmp;int cnt=0;
	tmp.h=dist[s],tmp.f=0,tmp.to=s,tmp.used[s]=1,tmp.s=char(s+'0');
	q.push(tmp);
	while(!q.empty())
	{
		heap cur=q.top();q.pop();
		vector<node>::iterator it;
		if(cur.to==t)
		{
			cnt++;
			if(cnt==k)
			{
				for(ri i=0;i<cur.s.length()-1;i++)printf("%d-",int(cur.s[i]-'0'));
				printf("%d",int(cur.s[cur.s.length()-1]-'0'));
				return;
			}
		}
		for(it=a[cur.to].begin();it!=a[cur.to].end();++it)
		{
			if(!cur.used[it->to])
			{
				heap tmp;
				tmp.f=cur.f+it->v,tmp.h=tmp.f+dist[it->to],tmp.to=it->to,tmp.s=cur.s+char(it->to+'0'),tmp.used=cur.used,tmp.used[it->to]=1;
				q.push(tmp);
			}
		}
	}
	printf("No\n");
}
int main()
{
	n=getint(),m=getint(),k=getint(),s=getint(),t=getint();
	for(ri i=1;i<=m;i++)
	{
		int x=getint(),y=getint(),z=getint();
		a[x].push_back((node){y,z});
		b[y].push_back((node){x,z});
	}
	BellmanFord();
	Astar();
	return 0;
}

