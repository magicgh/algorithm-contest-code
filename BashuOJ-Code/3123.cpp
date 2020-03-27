#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define ri register int
using namespace std;
const int MAXN=600005;
const double INF=1e100;
struct point{int x,y;};
struct heap
{
	int u;double dis;
	bool operator <(const heap &rhs)const{return dis>rhs.dis;}
};
struct node{int x,y;double z;};
node a[MAXN*4];
int n,m,N,k,cnt,x1,x2,ay[MAXN],by[MAXN],prt[MAXN];
double Ans;
inline double GetDist(const point &p1,const point &p2)
{
	return sqrt((double)(p1.x-p2.x)*(double)(p1.x-p2.x)+(double)(p1.y-p2.y)*(double)(p1.y-p2.y));
}
inline void AddEdge(int x,int y,double z){a[++cnt]=(node){x,y,z};}
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline bool cmp(const node &a,const node &b){return a.z<b.z;}
inline int getfa(int u)
{
	if(prt[u]==u)return u;
	return prt[u]=getfa(prt[u]);
}	
void kruskal()
{
	for(ri i=1;i<=N;i++)prt[i]=i;
	for(ri i=1;i<=cnt;i++)
	{
		int f1=getfa(a[i].x),f2=getfa(a[i].y);
		if(f1!=f2)
		{
			prt[f2]=f1;
			Ans+=a[i].z;
			if(++k>=N-1)break;
		}
	}
}
int main()
{
	n=getint(),m=getint(),x1=getint(),x2=getint(),N=n+m;
	for(ri i=1;i<=n;i++)ay[i]=ay[i-1]+getint();
	for(ri i=1;i<=m;i++)by[i]=by[i-1]+getint();
	for(int i=2;i<=n;i++)
		AddEdge(i-1,i,(double)(ay[i]-ay[i-1]));
	for(int i=2;i<=m;i++)
		AddEdge(n+i-1,n+i,(double)(by[i]-by[i-1]));
	for(int i=1,j=1;i<=n;i++)
	{
		while(by[j]<=ay[i]&&j<=m)j++;
		point p1=(point){x1,ay[i]},p2=(point){x2,by[j-1]};
		if(j>1)AddEdge(i,j+n-1,GetDist(p1,p2));
		p1=(point){x1,ay[i]},p2=(point){x2,by[j]};
		if(j<=m)AddEdge(i,j+n,GetDist(p1,p2));
	}
	sort(a+1,a+cnt+1,cmp);
	kruskal();
	printf("%.2lf",Ans);	
	return 0;
}