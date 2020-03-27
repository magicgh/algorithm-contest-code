#include<iostream>
#include<cstdio>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<queue>
#define ri register int
#define ll long long
using namespace std;
const int MAXN=305;
const int MAXG=105;
const double INF=1e18;
const double eps=1e-5;
struct Point
{
	double x,y;
	inline void Input(){scanf("%lf%lf",&x,&y);}
	bool operator ==(const Point &a){return ((x-eps)<=a.x&&a.x<=(x+eps))&&((y-eps)<=a.y&&a.y<=(y+eps));}
};
struct node{int to;double val;};
struct heap
{
	int u;double dist;
	bool operator <(const heap &rhs)
	const {return dist>rhs.dist;}
};
vector<node>a[MAXN];
int n,m,Node,S,T;
int Belong[MAXN];
double dist[MAXN];
bool vst[MAXN];
Point p[MAXN];
vector<Point>Gra[MAXG];
inline double Sqr(const double &x){return x*x;}
inline double GetDist(const Point &a,const Point &b){return sqrt(Sqr(a.x-b.x)+Sqr(a.y-b.y));}
inline void AddEdge(int u,int v,double w)
{
	a[u].push_back((node){v,w});
	a[v].push_back((node){u,w});
}
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
void Dijkstra(int v0)
{
	priority_queue<heap>q;
	for(ri i=1;i<=m;i++)dist[i]=INF;
	dist[v0]=0,q.push((heap){v0,dist[v0]});
	while(!q.empty())
	{
		heap now=q.top();q.pop();
		if(vst[now.u])continue;
		vst[now.u]=1;
		vector<node>::iterator it;
		for(it=a[now.u].begin();it!=a[now.u].end();++it)
		{
			if((!vst[it->to])&&dist[it->to]>dist[now.u]+it->val)
			{
				dist[it->to]=dist[now.u]+it->val;
				q.push((heap){it->to,dist[it->to]});
			}
		}
	}
}
inline double Cross(Point &a,Point &b,Point &c){return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);}
inline bool Insec(Point &a,Point &b,Point &c,Point &d){return (Cross(a,c,d)*Cross(b,c,d)<0)&&(Cross(c,a,b)*Cross(d,a,b)<0);}
inline bool Check(Point &a,Point &b)
{
	for(ri i=1;i<=n;i++)
	{
		unsigned int Size=Gra[i].size();
		double Minx=INF,Miny=INF,Maxx=-INF,Maxy=-INF;
		double PMinx=min(a.x,b.x),PMiny=min(a.y,b.y),PMaxx=max(a.x,b.x),PMaxy=max(a.y,b.y);
		for(unsigned ri j=0;j<Size-1;j++)
		{
			Minx=min(Gra[i][j].x,Minx),Miny=min(Gra[i][j].y,Miny);
			Maxx=max(Gra[i][j].x,Maxx),Maxy=max(Gra[i][j].y,Maxy);
			if((Gra[i][j]==a&&Gra[i][j+1]==b)||(Gra[i][j+1]==a&&Gra[i][j]==b))continue;
			if(Insec(a,b,Gra[i][j],Gra[i][j+1]))return 0;
		}
		if(PMinx>Maxx||PMaxx<Minx||PMiny>Maxy||PMaxy<Miny)continue;
		if((Gra[i][0]==a&&Gra[i][Size-1]==b)||(Gra[i][Size-1]==a&&Gra[i][0]==b))continue;
		if(Insec(a,b,Gra[i][0],Gra[i][Size-1]))return 0;
	}
	return 1;
}
int main()
{
	//freopen("path.in","r",stdin);
	//freopen("path.out","w",stdout);
	n=GetInt();
	for(ri i=1;i<=n;i++)
	{
		Node=GetInt();
		for(ri j=1;j<=Node;j++)
		{
			p[++m].Input();
			Gra[i].push_back(p[m]);
			Belong[m]=i;
		}
	}
	S=GetInt(),T=GetInt();
	for(ri i=1;i<m;i++)
	{
		for(ri j=i+1;j<=m;j++)
		{
			if(Belong[i]==Belong[j]&&i+1!=j)continue;
			if(Check(p[i],p[j]))
				AddEdge(i,j,GetDist(p[i],p[j]));
		}
	}
	Dijkstra(S);
	printf("%.4lf",dist[T]);
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
