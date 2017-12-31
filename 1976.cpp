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
priority_queue<int,vector<int>,greater<int> >q;
const int MAXN=30005;
vector<int>a[MAXN];
int n,m,Deg[MAXN],ans[MAXN];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
int main()
{
	n=getint();
	for(ri i=1;i<=n;i++)
	{
		m=getint();
		for(ri j=1;j<=m;j++)
		{
			int to=getint();
			a[i].push_back(to);Deg[to]++;
		}
	}
	for(ri i=1;i<=n;i++)if(!Deg[i])q.push(i);
	while(!q.empty())
	{
		int x=q.top();q.pop();
		ans[++ans[0]]=x;
		vector<int>::iterator it;
		for(it=a[x].begin();it!=a[x].end();++it)
		{
			Deg[*it]--;
			if(!Deg[*it])q.push(*it);
		}
	}
	if(ans[0]==n)
	{
		printf("%d\n",n);
		for(ri i=1;i<=ans[0];i++)printf("%d ",ans[i]);
	}
	else printf("no solution\n");
	return 0;
}
