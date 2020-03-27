#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define ri register int
#define ll long long
using namespace std;
const int MAXN=300005;
vector<int>a[MAXN],q[MAXN];
int n,m,cnt;
int Size[MAXN],Dep[MAXN],Cnt[MAXN],k[MAXN],Ans[MAXN];
bool Ban[MAXN];
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
void DFS(int u,int fa,int dep)
{
	Dep[u]=dep,Size[u]=1;
	vector<int>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(*it==fa)continue;
		DFS(*it,u,dep+1);
		Size[u]+=Size[*it];
	}
}
void Add(int u,int fa,int v)
{
	Cnt[Dep[u]]+=v;
	vector<int>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
		if(*it!=fa&&!Ban[*it])Add(*it,u,v);
}
void DSU(int u,int fa,bool keep)
{
	int mx=-1,bigCh=-1;
	vector<int>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
		if(*it!=fa&&Size[*it]>mx)mx=Size[*it],bigCh=*it;
	for(it=a[u].begin();it!=a[u].end();++it)
		if(*it!=fa&&*it!=bigCh)DSU(*it,u,0);
	if(bigCh!=-1)
		DSU(bigCh,u,1),Ban[bigCh]=1;
	Add(u,fa,1);
	for(unsigned ri i=0;i<q[u].size();i++)
	{
		int id=q[u][i];
		Ans[id]+=Cnt[Dep[u]+k[id]];
	}
	if(bigCh!=-1)Ban[bigCh]=0;
	if(!keep)Add(u,fa,-1);
}
int main()
{
	n=getint(),m=getint();
	for(ri i=1;i<n;i++)
	{
		int x=getint(),y=getint();
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for(ri i=1;i<=m;i++)
	{
		int u=getint();k[i]=getint();
		q[u].push_back(i);
	}
	DFS(1,0,0),DSU(1,0,0);
	for(ri i=1;i<=m;i++)printf("%d\n",Ans[i]);
	return 0;
}


