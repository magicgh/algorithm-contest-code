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
const double INF=0x7fffffff;
const int MAXN=1005;
struct point{int x,y;};
struct node{int to,val;};
struct heap
{
	int u,val;
	bool operator <(const heap &rhs)
	const{return val>rhs.val;}
};
point p[MAXN];
vector<node>a[MAXN];
int n,m,cnt,jump[MAXN],tot,dist[MAXN],ans=-INF;
bool vst[MAXN];
inline int getdist(const point &a,const point &b)
{
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
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
		vst[now.u]=1,cnt++;
		ans=max(ans,now.val);
		vector<node>::iterator it;
		for(it=a[now.u].begin();it!=a[now.u].end();++it)
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
	m=getint();
	for(ri i=1;i<=m;i++)jump[i]=getint();
	n=getint();
	for(ri i=1;i<=n;i++)
	{
		int x=getint(),y=getint();
		p[i]=(point){x,y};	
	}
	for(ri i=1;i<n;i++)
		for(ri j=i+1;j<=n;j++)
		{
			a[i].push_back((node){j,getdist(p[i],p[j])});
			a[j].push_back((node){i,getdist(p[i],p[j])});
		}
	Prim();
	for(ri i=1;i<=m;i++)
		if(jump[i]*jump[i]>=ans)tot++;
		printf("%d",tot);
	return 0;
}

