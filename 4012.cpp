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
const int MAXN=1005;
const int INF=0x7fffffff/2;
stack<int>s;
vector<int>a[MAXN];
int n,m,cnt,Part,dfn[MAXN],low[MAXN],Ins[MAXN],Size[MAXN],Belong[MAXN];
bool map[MAXN][MAXN];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void DFS(int u)
{
	dfn[u]=low[u]=++cnt;
	s.push(u);Ins[u]=1;
	vector<int>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(!dfn[*it])
		{
			DFS(*it);
			low[u]=min(low[u],low[*it]);
		}
		else if(Ins[*it])low[u]=min(low[u],dfn[*it]);
	}
	int t;
	if(low[u]==dfn[u])
	{
		Part++;
		do
		{
			t=s.top();s.pop();
			Size[Part]++;
			Ins[t]=0,Belong[t]=Part;
		}while(t!=u);
	}
}
int main()
{
	n=getint(),m=getint();
	for(ri i=1;i<=m;i++)
	{
		int u=getint(),v=getint();
		a[u].push_back(v);
	}
	for(ri i=1;i<=n;i++)if(!dfn[i])DFS(i);
	int Max=0,Min=Part-1;
	for(int u=1;u<=n;u++)
	{
		vector<int>::iterator it;
		for(it=a[u].begin();it!=a[u].end();++it)
			if(Belong[u]!=Belong[*it])map[Belong[u]][Belong[*it]]=1;
	}
	for(ri i=1;i<=Part;i++)
		if(Size[i]>1)Min+=Size[i],Max+=Size[i]*(Size[i]-1);
	for(ri k=1;k<=Part;k++)
		for(ri i=1;i<=Part;i++)
			for(ri j=1;j<=Part;j++)
				map[i][j]=(map[i][j]||(map[i][k]&&map[k][j]));
	for(ri i=1;i<=Part;i++)
		for(ri j=1;j<=Part;j++)
		if(map[i][j])Max+=Size[i]*Size[j];
	printf("%d %d",Min,Max);
	return 0;
}
