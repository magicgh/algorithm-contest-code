#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<list>
#include<queue>
#include<limits>
using namespace std;
const double DOUBLE_MAX=(numeric_limits<double>::max)();
int N,M;
double dist[3][205]={0};
double Min=DOUBLE_MAX;
int prt[205]={0};
bool vst[205]={0},disable[205][205]={0};
struct point
{
	double x,y;
}P[205];
struct node
{
	int to;
	double val;
};
struct heap
{
	int to;
	double val;
	bool operator <(heap t)
	const{return val>t.val;}
};
list<node>a[205];
list<node>::iterator i;
inline double Calc(int px,int py)
{
	return sqrt((P[px].x-P[py].x)*(P[px].x-P[py].x)+(P[px].y-P[py].y)*(P[px].y-P[py].y));
}
void Input()
{
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;i++)
	scanf("%lf%lf",&P[i].x,&P[i].y);
	int x,y;
	for(int i=1;i<=M;i++)
	{
		scanf("%d%d",&x,&y);
		double z=Calc(x,y);
		a[x].push_back({y,z});
		a[y].push_back({x,z});
	}
	return;
}
void Dijkstra(int k)
{
	priority_queue<heap>q;
	memset(vst,0,sizeof(vst));
	for(int i=1;i<=N;i++)dist[k][i]=DOUBLE_MAX;
	dist[k][1]=0;q.push({1,dist[k][1]});
	if(k==0)prt[1]=1;
	while(!q.empty())
	{
		heap now=q.top();
		q.pop();
		if(!vst[now.to])
		{
			vst[now.to]=1;
			for(i=a[now.to].begin();i!=a[now.to].end();++i)
			   {
			   	  if((!vst[i->to])&&(!disable[now.to][i->to])&&dist[k][i->to]>dist[k][now.to]+i->val)
			   	  {
			   		dist[k][i->to]=dist[k][now.to]+i->val;
			   		q.push({i->to,dist[k][i->to]});
			   		if(k==0)prt[i->to]=now.to;
				  }
			   }
		}
	}
}
void Output()
{
	if(Min==DOUBLE_MAX)printf("-1");
	else printf("%.2lf\n",Min);
}
void Second_Path()
{
	for(int u=N;u!=1;u=prt[u])
	{
	disable[u][prt[u]]=disable[prt[u]][u]=1;
	Dijkstra(1);
	Min=min(Min,dist[1][N]);
	disable[u][prt[u]]=disable[prt[u]][u]=0;
    }
    Output();
	return;
}
int main(){
	Input();
	Dijkstra(0);
	Second_Path();
	return 0;
}
