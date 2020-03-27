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
list<node>a[1005];
int M,N;
int dist[1005],used[1005]={0};
bool ext[1005]={0};
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
	for(int i=1;i<=N;i++)dist[i]=INF;
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
				if(used[i->to]>=N)return 0;
				dist[i->to]=dist[now]+i->val;
				if(!ext[i->to])q.push(i->to),ext[i->to]=1;
			}
		}
	}
	return 1;
}
int main(){
	N=GetInt();
	M=GetInt();
	int x,y,z;
	for(int i=1;i<=M;i++)
	{
	x=GetInt();
	y=GetInt();
	z=GetInt();
	a[y].push_back({x,z});
    }
    for(int i=1;i<=N;i++)a[0].push_back({i,0});
	if(SPFA(0))
	{
		int Min=INF;
		for(int i=1;i<=N;i++)Min=min(Min,dist[i]);
		for(int i=1;i<=N;i++)printf("%d\n",dist[i]-Min);
	}
	else printf("NO SOLUTION");
	return 0;
}
