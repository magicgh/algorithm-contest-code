#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<list>
#include<deque>
using namespace std;
struct node
{
	int to,value;
};
list<node>a[100005];
int N,ML,MD;
int dist[100005]={0},used[100005]={0};
bool ext[100005]={0};
bool SPFA(int u)
{
    deque<int>q;
	for(int i=1;i<=N;i++)dist[i]=0x7fffffff;
	dist[u]=0,q.push_back(u),ext[u]=1;
	list<node>::iterator y;
	while(!q.empty())
	{
		int x=q.front();
		q.pop_front();
		ext[x]=0;
		for(y=a[x].begin();y!=a[x].end();++y)
		{
			if(y->to<=x)continue;
			if(dist[y->to]>dist[x]+(y->value))
			{
		        dist[y->to]=dist[x]+(y->value);
		        if(!ext[y->to])
		        {
		        used[y->to]++;
				if(used[y->to]>=N)return 0;
		        if(!q.empty()&&dist[y->to]<dist[q.front()])q.push_front(y->to);//新增SLF优化 
		        else q.push_back(y->to);
				ext[y->to]=1;
			    }
			}
		}
	}
	return 1;
}
int main(){
	scanf("%d%d%d",&N,&ML,&MD);
	int x,y,z;
	for(int i=1;i<=ML;i++)
	{
	scanf("%d%d%d",&x,&y,&z);
	if(x>y)swap(x,y);
	a[x].push_back((node){y,z});
    }
    for(int i=1;i<=MD;i++)
	{
	scanf("%d%d%d",&x,&y,&z);
	if(x>y)swap(x,y);
	a[x].push_back((node){y,-z});
    }
    SPFA(1);
    printf("%d\n",dist[N]);
    printf(dist[N]<0?"YES":"NO");
	return 0;
}