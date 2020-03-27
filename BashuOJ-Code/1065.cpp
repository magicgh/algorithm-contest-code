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
struct node{int to,val;};
vector<node>a[205];
bool vst[205],bj=0;
int n,p,deg[205],c[205],u[205];
queue<int>q;
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void BFS()
{
	while(!q.empty())
	{
		int now=q.front();q.pop();
		if(c[now]<=0||!deg[now])continue;
		vector<node>::iterator it;
		for(it=a[now].begin();it!=a[now].end();++it)
		{
			c[it->to]+=it->val*c[now];
			if(!vst[it->to])q.push(it->to),c[it->to]-=u[it->to],vst[it->to]=1;
		} 
	}
}
int main()
{
	n=getint(),p=getint();
	for(ri i=1;i<=n;i++)
	{
		c[i]=getint(),u[i]=getint();
		if(c[i])q.push(i),vst[i]=1;
	}
	for(ri i=1;i<=p;i++)
	{
		int u=getint(),v=getint(),w=getint();
		a[u].push_back((node){v,w});
		deg[u]++;
	}
	BFS();
	for(ri i=1;i<=n;i++)
		if(c[i]>0&&!deg[i])bj=1,printf("%d %d\n",i,c[i]);
	if(!bj)printf("NULL\n");
	return 0;
}
