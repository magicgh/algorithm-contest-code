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
int dist[1005],used[1005]={0},sum[1005]={0};
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
	for(int i=0;i<=N;i++)dist[i]=-INF;
	dist[v0]=0;q.push(v0);ext[v0]=1;
	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		ext[now]=0;
		for(i=a[now].begin();i!=a[now].end();++i)
		{
			if(dist[i->to]<dist[now]+i->val)
			{
				used[i->to]++;
				if(used[i->to]>=N+1)return 0;
				//cout<<now<<"->"<<i->to<<":"<<" from "<<dist[i->to]<<" to "<<dist[now]<<'+'<<i->val<<endl;
				dist[i->to]=dist[now]+i->val;
				if(!ext[i->to])q.push(i->to),ext[i->to]=1;
			}
		}
	}
	return 1;
}
int main(){
	M=GetInt();
	N=-INF;
	for(int i=0;i<=1000;i++)sum[i]=i;
	int x,y,z;
	for(int i=1;i<=M;i++)
	{
		x=GetInt();
		y=GetInt();
		z=GetInt();
		N=max(N,sum[y]);
		a[sum[x-1]].push_back({sum[y],z});
	}
	for(int i=1;i<=N;i++)
	{
		a[sum[i]].push_back({sum[i-1],-1});
		a[sum[i-1]].push_back({sum[i],0});
	}
	list<node>::iterator j;
	/*for(int i=0;i<=N;i++)
	   for(j=a[i].begin();j!=a[i].end();++j)cout<<i<<"->"<<j->to<<":"<<j->val<<endl;*/
	if(SPFA(sum[0]))printf("%d",dist[sum[N]]);
	else printf("-1\n");
	return 0;
}
