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
const int MAXN=305;
struct path{int x,y,p,c,id;};
struct node{int to,p,c,id;};
vector<node>a[MAXN];
vector<int>c[MAXN];
path b[MAXN];
bool used[MAXN];
int prt[MAXN],Edge[MAXN],Deg[MAXN],Order[MAXN];
int n,m,Ans;
inline bool cmp(const path &a,const path &b)
{
	return (a.p==b.p&&a.c==b.c&&a.id<b.id)||(a.p==b.p&&a.c>b.c)||(a.p>b.p);
}
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline int getfa(int u)
{
	if(prt[u]==u)return u;
	return prt[u]=getfa(prt[u]);
}
void Kruskal()
{
	for(ri i=1;i<=n;i++)prt[i]=i;
	for(ri i=1;i<=m;i++)
	{
		int f1=getfa(b[i].x),f2=getfa(b[i].y);
		if(f1!=f2)
		{
			a[b[i].x].push_back((node){b[i].y,b[i].p,b[i].c,b[i].id});
			a[b[i].y].push_back((node){b[i].x,b[i].p,b[i].c,b[i].id});
			used[i]=1,prt[f2]=f1;
			Ans+=b[i].c;
		} 
	}
}
void Topsort()
{
	priority_queue<int,vector<int>,greater<int> >q;
	for(ri i=1;i<=m;i++)if(!Deg[i])q.push(i);
	while(!q.empty())
	{
		int now=q.top();q.pop();
		Order[++Order[0]]=now;
		vector<int>::iterator it;
		for(it=c[now].begin();it!=c[now].end();++it)
			if(!(--Deg[*it]))q.push(*it);
	}
}
inline bool DFS(int u,int v,int prt,int Maxp)
{
	if(u==v)return 1;
	vector<node>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(it->to==prt)continue;
		if(it->p<=Maxp)Edge[++Edge[0]]=it->id;
		if(DFS(it->to,v,u,Maxp))return 1;
		if(it->p<=Maxp)Edge[0]--;
	}
	return 0;
}
void BuildGraph()
{
	for(ri i=1;i<=m;i++)
	{
		if(used[i])continue;Edge[0]=0;
		DFS(b[i].x,b[i].y,0,b[i].p);
		for(ri j=1;j<=Edge[0];j++)c[Edge[j]].push_back(b[i].id),Deg[b[i].id]++;
	}	
}
int main()
{
	n=getint(),m=getint();
	for(ri i=1;i<=m;i++)
	{
		int x=getint(),y=getint(),p=getint(),c=getint();
		b[i]=(path){x,y,p,c,i};
	}
	sort(b+1,b+m+1,cmp);
	Kruskal();
	BuildGraph();
	Topsort();
	printf("%d\n",Ans);
	for(ri i=1;i<=m;i++)printf("%d ",Order[i]);
	return 0;
}