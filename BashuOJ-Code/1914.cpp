#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<list>
#include<queue>
#include<climits>
using namespace std;
int N,M,A,B,C;
int double_dist[2][1005]={0},double_cnt[2][1005]={0};
int Min=INT_MAX;
bool vst[1005]={0};
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
list<node>a[1005];
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
	A=GetInt();
	B=GetInt();
	C=GetInt();
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
void Dijkstra(int v0,int dist[],int cnt[])
{
	memset(vst,0,sizeof(vst));
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
int Output()
{
	if(double_dist[0][B]==double_dist[0][C]+double_dist[1][B])return double_cnt[0][C]*double_cnt[1][B];
	else return 0;
}
int main(){
	Input();
	Dijkstra(A,double_dist[0],double_cnt[0]);
	Dijkstra(C,double_dist[1],double_cnt[1]);
	printf("%d",Output());
	return 0;
}