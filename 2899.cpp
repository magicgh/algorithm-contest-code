#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<list>
#include<queue>
#include<climits>
using namespace std;
int N,M,S,T;
int dist[105]={0},cnt[105]={0};
int Min=INT_MAX;
bool vst[105]={0};
struct node
{
	int to,val;
};
struct heap
{
	int to,val;
	bool operator <(heap t)
	const{return val>t.val;}
};
list<node>a[205];
list<node>::iterator i;
void Input()
{
	scanf("%d%d",&N,&M);
	int x,y,z;
	for(int i=1;i<=M;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		a[x].push_back({y,z});
		a[y].push_back({x,z});
	}
	scanf("%d%d",&S,&T);
	return;
}
void Dijkstra(int v0)
{
	priority_queue<heap>q;
	for(int i=1;i<=N;i++)dist[i]=INT_MAX;
	dist[v0]=0;q.push({v0,dist[v0]});cnt[S]=1;
	while(!q.empty())
	{
		heap now=q.top();
		q.pop();
		if(!vst[now.to])
		{
			vst[now.to]=1;
			for(i=a[now.to].begin();i!=a[now.to].end();++i)
			   {
			   	  if((!vst[i->to])&&dist[i->to]==dist[now.to]+i->val)cnt[i->to]+=cnt[now.to];
			   	  if((!vst[i->to])&&dist[i->to]>dist[now.to]+i->val)
			   	  {
			   		dist[i->to]=dist[now.to]+i->val	;
			   		cnt[i->to]=cnt[now.to];
			   		q.push({i->to,dist[i->to]});
				  }
			   }
		}
	}		
	return;
}
void Output()
{
	if(!cnt[T])puts("poor ty");
	else printf("%d",cnt[T]);
	return;
}
int main(){
	Input();
	Dijkstra(S);
	Output();
	return 0;
}
