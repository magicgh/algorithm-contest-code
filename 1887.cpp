#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<list>
#include<queue>
using namespace std;
const int INF=0x7fffffff;
struct node
{
	int to,val;
};
list<node>a[2005];
int N,A0,B0,L0,A1,B1,L1;
int dist[2005],used[2005]={0};
bool ext[2005]={0};
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-')||(bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
bool SPFA(int v0)
{
	queue<int>q;
	list<node>::iterator i;
	for(int i=0;i<=N;i++)dist[i]=INF;
	dist[v0]=0;q.push(v0);ext[v0]=1;
	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		ext[now]=0;
		for(i=a[now].begin();i!=a[now].end();++i)
		{
			if(dist[i->to]>dist[now]+i->val)
			{
				used[i->to]++;
				if(used[i->to]>=N+1)return 0;
				dist[i->to]=dist[now]+i->val;
				if(!ext[i->to])q.push(i->to),ext[i->to]=1;
			}
		}
	}
	return 1;
}
int main(){
	N=GetInt();
	A0=GetInt();
	B0=GetInt();
	L0=GetInt();
	A1=GetInt();
	B1=GetInt();
	L1=GetInt();
	for(int i=1;i<=N;i++)
	{
		a[i-1].push_back({i,1});
		a[i].push_back({i-1,0});
		a[i+L0-1].push_back({i-1,B0-L0});
		a[i-1].push_back({i+L0-1,L0-A0});
		a[i+L1-1].push_back({i-1,-A1});
		a[i-1].push_back({i+L1-1,B1});
	}
    if(SPFA(0))
    {
    	printf("%d",dist[N]-dist[0]);
	}
	else printf("-1");
	return 0;
}