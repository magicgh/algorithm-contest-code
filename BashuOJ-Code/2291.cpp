#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<queue>
#include<climits>
#include<list>
using namespace std;
int N,M;
int dist[2010]={0},cnt[2010]={0},map[2010][2010]={0};
bool vst[2010]={0};
struct node
{
	int to,val;
};
list<node>a[2010];
list<node>::iterator i;
struct heap
{	
	int to,val;
	bool operator <(heap t)
	const{return val>t.val;}
};
inline int GetInt()
{
	int num=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num;
}
void Input()
{
	N=GetInt();
	M=GetInt();
	int x,y,z;
	for(int i=1;i<=N;i++)
	   for(int j=1;j<=N;j++)map[i][j]=INT_MAX;
	for(int i=1;i<=M;i++)
	{
		x=GetInt();
		y=GetInt();
		z=GetInt();
		map[x][y]=min(map[x][y],z);
	}
	for(int i=1;i<=N;i++)
	   for(int j=1;j<=N;j++)
	   {
	   	if(map[i][j]!=INT_MAX)a[i].push_back({j,map[i][j]});
	   }
	return;
}	
inline void Dijkstra(int v0)
{
	priority_queue<heap>q;
	for(int i=1;i<=N;i++)dist[i]=INT_MAX;
	dist[v0]=0;q.push({v0,dist[v0]});cnt[v0]=1;
	while(!q.empty())
	{
	priority_queue<heap>q;
	for(int i=1;i<=N;i++)dist[i]=INT_MAX;
	dist[v0]=0;q.push({v0,dist[v0]});cnt[v0]=1;
	while(!q.empty())
	{
		heap now=q.top();
		q.pop();
		if(!vst[now.to])
		{
			vst[now.to]=1;
			for(i=a[now.to].begin();i!=a[now.to].end();++i)
			   {
			   	  if((!vst[i->to])&&dist[i->to]==dist[now.to]+i->val)cnt[i->to]=(cnt[i->to]+cnt[now.to]);
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
	return;
}
void Output()
{
	if(dist[N]==INT_MAX)printf("No answer\n");
	else printf("%d %d\n",dist[N],cnt[N]);
	return;
}
int main(){
	Input();
	Dijkstra(1);
	Output();
	return 0;
}