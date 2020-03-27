#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#define ll long long
#define ri register int
using namespace std;
const int MAXN=200005;
const int INF=0x7fffffff/2;
struct stk
{
	int u,v;
	vector<int>::iterator it;
};
stk Stack[MAXN];
int n,part,Ans=INF,cnt,dfn[MAXN],low[MAXN],Size[MAXN];
bool Ins[MAXN];
vector<int>a[MAXN];
stack<int>s;
inline const int getint()
{
	int num=0,bj=1;
	char ch=getchar();
	while(!isdigit(ch))bj=(ch=='-'||bj==-1)?-1:1,ch=getchar();
	while(isdigit(ch))num=num*10+ch-'0',ch=getchar();
	return num*bj;
}
void Tarjan(int u)
{
	int v,t,top=0;
	vector<int>::iterator it;
	START:
		dfn[u]=low[u]=++cnt;
		s.push(u);Ins[u]=1;
		for(it=a[u].begin();it!=a[u].end();++it)
		{
			v=*it;
			if(!dfn[v])
			{
				Stack[++top]=(stk){u,v,it};
				u=v;
				goto START;
	RET:
				u=Stack[top].u,v=Stack[top].v,it=Stack[top].it,top--;
				low[u]=min(low[u],low[v]);
			}
			else if(Ins[u])low[u]=min(low[u],dfn[v]);
		}
	if(dfn[u]==low[u])
	{
		part++;
		do
		{
			t=s.top();s.pop();Ins[t]=1;
			Size[part]++;
		}
		while(t!=u);
	}
	if(top)goto RET;
}
int main()
{
	n=getint();
	for(ri i=1;i<=n;i++)
		a[i].push_back(getint());
	for(ri i=1;i<=n;i++)
		if(!dfn[i])Tarjan(i);
	for(ri i=1;i<=part;i++)
		if(Size[i]!=1)Ans=min(Ans,Size[i]);
	printf("%d\n",Ans);
	return 0;
}
