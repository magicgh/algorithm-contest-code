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
const int MAXN=505;
const int MAXM=10005;
struct node{int u,v;};
struct que{int point,dist;};
vector<int>a[MAXN];
node Edge[MAXM];
int Q,n,m,dist[MAXN];
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
int BFS(int id)
{
	queue<int>q;
	for(ri i=1;i<=n;i++)dist[i]=0;
	q.push(Edge[id].u);
	while(!q.empty())
	{
		int now=q.front();q.pop();
		vector<int>::iterator it;
		for(it=a[now].begin();it!=a[now].end();++it)
		{
			if(dist[*it]||(now==Edge[id].u&&*it==Edge[id].v))continue;
			q.push(*it),dist[*it]=dist[now]+1;
			if(*it==Edge[id].v)return dist[*it];
		}
	}
	return 0;
}
int main()
{
	Q=getint();
	for(ri t=1;t<=Q;t++)
	{
		n=getint(),m=getint();
		for(ri i=1;i<=n;i++)a[i].clear();
		for(ri i=1;i<=m;i++)
		{
			int u=getint(),v=getint();
			a[u].push_back(v);
			Edge[i]=(node){u,v};
		}
		printf("Case %d: ",t);
		for(ri i=1;i<=m;i++)
			printf("%d ",BFS(i));
		printf("\n");
	}
	return 0;
}
