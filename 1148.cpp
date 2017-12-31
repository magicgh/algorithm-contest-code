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
const int MAXN=10005;
const int INF=0x7fffffff/2;
priority_queue<int,vector<int>,greater<int> >q;
vector<int>a[MAXN],b[MAXN];
int n,m,Deg[MAXN],Ans,cnt,Out[MAXN];
bool vst[MAXN],Hash[MAXN];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
void Topsort()
{
	q.push(1);
	while(!q.empty())
	{
		int now=q.top();q.pop();
		Ans++,Hash[now]=1;
		vector<int>::iterator it;
		for(it=a[now].begin();it!=a[now].end();++it)
		{
			Deg[*it]--;
			if(!Deg[*it])q.push(*it);
		}
	}
}
void DFS(int u)
{
	if(!vst[u])vst[u]=1,cnt++;
	vector<int>::iterator it;
	for(it=b[u].begin();it!=b[u].end();++it)
		DFS(*it);
}
int main()
{
	n=getint(),m=getint();
	for(ri i=1;i<=m;i++)
	{
		int u=getint(),v=getint();
		a[u].push_back(v);
		b[v].push_back(u);
		Deg[v]++;
	}
	if(Deg[1]){printf("impossible\n");return 0;}
	Topsort();
	DFS(n);
	if(!Hash[n])printf("impossible\n");
	else printf("%d\n",cnt);
	return 0;
}

