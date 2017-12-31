#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<queue>
#include<list>
#include<limits>
using namespace std;
double ans=0;
int N,M;
struct node
{
	int to;
	double val;
};
struct heap
{
	int num;
	double val;
	bool operator <(const heap &rhs)const{return val>rhs.val;}
};
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
struct Vector
{
	int x,y;
	Vector(int x=0,int y=0):x(x),y(y){};
	inline Vector operator +(Vector &a){return Vector(a.x+this->x,a.y+this->y);}
	inline Vector operator -(Vector &a){return Vector(a.x-this->x,a.y-this->y);}
	inline Vector operator *(int num){return Vector(this->x*num,this->y*num);}
	inline Vector operator /(int num){return Vector(this->x/num,this->y/num);}
	inline int DotMulti(Vector &a,Vector &b){return a.x*b.x+a.y*b.y;}
	inline int CrossMulti(Vector &a,Vector &b){return a.x*b.y-b.x*a.y;}
	inline int Cross/*AB-AC*/(Vector &a,Vector &b,Vector &c){return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);}
	inline double LineLen(Vector &a,Vector &b){return sqrt(double(double((a.x-b.x))*double((a.x-b.x))+double((a.y-b.y))*double((a.y-b.y))));}
	inline bool OnLine/*a B,C*/(Vector &a,Vector &b,Vector &c){return ((b.x-a.x)*(b.y-c.y)-(b.x-c.x)*(b.y-a.y)==0)?1:0;}
	inline bool OnSegment/*a B,C*/(Vector &a,Vector &b,Vector &c)
	{
		return (((b.x-a.x)*(b.y-c.y)-(b.x-c.x)*(b.y-a.y)==0)&&a.x>=min(b.x,c.x)&&a.x<=max(b.x,c.x)&&a.y>=min(b.y,c.y)&&a.y<=max(b.y,c.y))?1:0;
	}
	inline bool IsLineCross/*AB,CD*/(Vector &a,Vector &b,Vector &c,Vector &d){return (Cross(a,c,d)*Cross(b,c,d)<0)&&(Cross(c,a,b)*Cross(d,a,b)<0);}
};
Vector point,vec[205],Line[105][3];
struct MST
{
	list<node>a[205];
	list<node>::iterator j;
	double dist[205];
	bool vst[205];
	inline void AddEdge(int x,int y,double z)
	{
		a[x].push_back((node){y,z});
		a[y].push_back((node){x,z});
		return;
	}
	inline bool Prim(int v0)
	{
	int cnt=0;
	priority_queue<heap>q;
	list<node>::iterator j;
	for(int i=1;i<=N;i++)dist[i]=(numeric_limits<double>::max)();
	dist[v0]=0;q.push((heap){v0,0});
	while(!q.empty()&&cnt<=N)
	{
		heap now=q.top();
		q.pop();
		if(vst[now.num])continue;
		ans+=now.val;
		vst[now.num]=1;
		cnt++;
		for(j=a[now.num].begin();j!=a[now.num].end();++j)
		{ 
			if(!vst[j->to]&&dist[j->to]>j->val)
			{
				dist[j->to]=j->val;
				q.push((heap){j->to,dist[j->to]});
			}
		}
	}
	if(cnt==N)return 1;
	else return 0;
	}
};
MST tree;
int main(){
	N=GetInt();
	for(int i=1;i<=N;i++)
	{
		vec[i].x=GetInt();
		vec[i].y=GetInt();
	}
	M=GetInt();
	for(int i=1;i<=M;i++)
	{
		Line[i][1].x=GetInt();
		Line[i][1].y=GetInt();
		Line[i][2].x=GetInt();
		Line[i][2].y=GetInt();
	}
	for(int i=1;i<N;i++)
	for(int j=i+1;j<=N;j++)
	{
	bool flag=0;
	for(int k=1;k<=M;k++)
		if(point.IsLineCross(vec[i],vec[j],Line[k][1],Line[k][2])){flag=1;break;}
		if(!flag)tree.AddEdge(i,j,point.LineLen(vec[i],vec[j]));
}
	if(tree.Prim(N))printf("%.3lf\n",ans);
	else printf("-1.000");
	return 0;
}