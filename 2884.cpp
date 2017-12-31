#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<list>
#include<queue>
#include<climits>
using namespace std;
int N,M,Min=INT_MAX,MinV=0,MinE=0;
int double_dist[2][505]={0};
bool vst[505]={0};
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
list<node>a[505];
list<node>::iterator i;
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
	for(int i=1;i<=M;i++)
	{
		x=GetInt();
		y=GetInt();
		z=GetInt();
		a[x].push_back({y,z});
		a[y].push_back({x,z});
	}
	return;
}
void Dijkstra(int v0,int dist[])
{
	memset(vst,0,sizeof(vst));
	priority_queue<heap>q;
	for(int i=1;i<=N;i++)dist[i]=INT_MAX;
	dist[v0]=0;q.push({v0,dist[v0]});
	while(!q.empty())
	{
		heap now=q.top();
		q.pop();
		if(!vst[now.to])
		{
			vst[now.to]=1;
			for(i=a[now.to].begin();i!=a[now.to].end();++i)
			   {
			   	  if((!vst[i->to])&&dist[i->to]>dist[now.to]+i->val)
			   	  {
			   		dist[i->to]=dist[now.to]+i->val;
			   		q.push({i->to,dist[i->to]});
				  }
			   }
		}
	}		
	return;
}
void Enumerate()
{
	for(int j=1;j<=N;j++)
	   for(i=a[j].begin();i!=a[j].end();++i)
	      	{
	      	if(Min>double_dist[0][j]+double_dist[1][i->to]+i->val/2)
	      	{
	      		Min=double_dist[0][j]+double_dist[1][i->to]+i->val/2;
	      		MinE=j;MinV=i->to;
			}
			if(Min>double_dist[0][i->to]+double_dist[1][j]+i->val/2)
	      	{
	      		Min=double_dist[0][i->to]+double_dist[1][j]+i->val/2;
	      		MinE=j;MinV=i->to;
			}
	        }
	return;	
	   
}
int main(){
	Input();
	Dijkstra(1,double_dist[0]);
	Dijkstra(N,double_dist[1]);
	Enumerate();
	if(MinV>MinE)swap(MinV,MinE);
	printf("%d %d\n%d",MinV,MinE,Min);
	return 0;
}