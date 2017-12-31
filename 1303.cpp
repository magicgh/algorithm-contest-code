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
#define ll long long
using namespace std;
const int MAXN=1005;
const double INF=1e100;
double dist[MAXN],ans;
int n,cnt;
bool vst[MAXN];
struct node{int to;double val;};
struct point{int x,y;};
point a[MAXN];
vector<node>edge[MAXN];
struct heap{
	int u;double val;
	bool operator <(const heap &rhs)
	const{return val>rhs.val;}
};
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline double Getdist(const point &a,const point &b)
{
	return sqrt((double)(a.x-b.x)*(double)(a.x-b.x)+(double)(a.y-b.y)*(double)(a.y-b.y));
}
void Prim()
{
	priority_queue<heap>q;
	for(ri i=1;i<=n;i++)dist[i]=INF;
	dist[1]=0;q.push((heap){1,0});
	while(!q.empty()&&cnt<=n)
	{
		heap now=q.top();q.pop();
		if(vst[now.u])continue;
		vst[now.u]=1;
		ans+=now.val;
		cnt++;
		vector<node>::iterator it;
		for(it=edge[now.u].begin();it!=edge[now.u].end();++it)
		{
			if(!vst[it->to]&&dist[it->to]>it->val)
			{
				dist[it->to]=it->val;
				q.push((heap){it->to,dist[it->to]});
			}
		} 
	}
}
int main()
{
	n=getint();
	for(ri i=1;i<=n;i++)
	{
		int x=getint(),y=getint();
		a[i]=(point){x,y};
	}
	for(ri i=1;i<n;i++)
		for(ri j=i+1;j<=n;j++)
		{
			edge[i].push_back((node){j,Getdist(a[i],a[j])});
			edge[j].push_back((node){i,Getdist(a[i],a[j])});
		}
	Prim();
	printf("%.2lf",ans);
	return 0;
}

