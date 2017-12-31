#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<deque>
#include<queue>
#define ri register int
using namespace std;
const int MAXN=1005;
const int INF=0x7fffffff;
struct node{int to,val;};
struct heap
{
	int to,f,h;
	bool operator <(const heap &rhs)
	const{return h>rhs.h;}
};//f距离函数,h估价函数 
vector<node>a[MAXN],b[MAXN];
bool ext[MAXN];
int n,m,s,t,k,dist[MAXN];
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
	deque<int>q;
	for(int i=1;i<=n;i++)dist[i]=INF;
	q.push_back(t);ext[t]=1;dist[t]=0;
	while(!q.empty())
	{
		int now=q.front();q.pop_front();ext[now]=0;
		vector<node>::iterator next;
		for(next=b[now].begin();next!=b[now].end();++next)
		{
			if(dist[now]+next->val<dist[next->to])
			{
				dist[next->to]=dist[now]+next->val;
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
int A_Star()
{
	priority_queue<heap> q;
	if(s==t)k++;//S->T路径不算
	if(dist[s]==INF)return -1;//无解
	q.push((heap){s,0,dist[s]});
	int cnt=0;
	while(!q.empty())
	{
		heap cur=q.top();q.pop();
		if(cur.to==t)cnt++;//统计搜索到T的次数
		if(cnt==k)return cur.f;
		vector<node>::iterator it;
		for(it=a[cur.to].begin();it!=a[cur.to].end();++it)q.push((heap){it->to,cur.f+it->val,cur.f+it->val+dist[it->to]});//更新 
	}
	return -1;
}
int main()
{
	n=getint(),m=getint();
	for(int i=1;i<=m;i++)
	{
		int x=getint(),y=getint(),z=getint();
		a[x].push_back({y,z});//建立正图 
		b[y].push_back({x,z});//建立反图 
	}
	s=getint(),t=getint(),k=getint();
	SPFA();
	printf("%d",A_Star());
	return 0;
}
