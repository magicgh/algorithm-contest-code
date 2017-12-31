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
const int MAXN=100005;
vector<int>a[MAXN];
int D,n,m;
int Deg[MAXN],Ans[MAXN];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline void Init()
{
	Ans[0]=0;
	for(ri i=1;i<=n;i++)
	{
		a[i].clear();
		Deg[i]=0;
	}
}
inline void Topsort()
{
	priority_queue<int>q;
	for(ri i=1;i<=n;i++)
		if(!Deg[i])q.push(i);
	while(!q.empty())
	{
		int now=q.top();q.pop();
		Ans[++Ans[0]]=now;
		vector<int>::iterator it;
		for(it=a[now].begin();it!=a[now].end();++it)
		{
			Deg[*it]--;
			if(!Deg[*it])q.push(*it);
		}
	}
}
int main()
{
	D=getint();
	while(D--)
	{
		Init();
		n=getint(),m=getint();
		for(ri i=1;i<=m;i++)
		{
			int x=getint(),y=getint();
			a[y].push_back(x);
			Deg[x]++;
		}
		Topsort();
		if(Ans[0]<n)printf("Impossible!");
		else
			for(ri i=Ans[0];i>=1;i--)printf("%d ",Ans[i]);
		printf("\n");
	}
	return 0;
}
