#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<stack>
#include<vector>
#define rui register unsigned int
using namespace std;
const int MAXN=1005;
struct point{int x,y;};
vector<int>a[MAXN];
stack<int>s;
point p[MAXN];
int dfn[MAXN],low[MAXN],belong[MAXN];
int n,m,cnt,part;
bool ins[MAXN];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline bool Check(int i,int j)
{
	return (p[i].x<p[j].x&&p[i].y<p[j].y&&p[i].y>p[j].x)||(p[j].x<p[i].x&&p[j].y<p[i].y&&p[j].y>p[i].x);
}
inline void AddEdge(int i,int j)//合法情况 
{
	a[i].push_back(j+m);
	a[j+m].push_back(i);
	a[i+m].push_back(j);
	a[j].push_back(i+m);
}
void Tarjan(int x)
{
	dfn[x]=low[x]=++cnt;
	s.push(x);ins[x]=1;
	vector<int>::iterator it;
	for(it=a[x].begin();it!=a[x].end();++it)
	{
		if(!dfn[*it])
		{
			Tarjan(*it);
			low[x]=min(low[x],low[*it]);
		}
		else if(ins[*it])low[x]=min(low[x],dfn[*it]);
	}
	if(low[x]==dfn[x])
	{
		int u;part++;
		do
		{
			u=s.top();s.pop();ins[u]=0;belong[u]=part;
		}while(u!=x);
	}
}
int main()
{
	n=getint(),m=getint();
	for(rui i=1;i<=m;i++)
	{
		int x=getint(),y=getint();if(x>y)swap(x,y);
		p[i]=(point){x,y};
	}
	for(rui i=1;i<m;i++)
		for(rui j=i+1;j<=m;j++)if(Check(i,j))AddEdge(i,j);
	for(rui i=1;i<=2*m;i++)if(!dfn[i])Tarjan(i);
	for(rui i=1;i<=m;i++)
		if(belong[i]==belong[i+m]){printf("the evil panda is lying again\n");return 0;}
	printf("panda is telling the truth...\n");
	return 0;
}

