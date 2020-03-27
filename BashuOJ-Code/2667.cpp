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
const int MAXN=20005;
stack<int>s;//只能开全局 
vector<int>a[MAXN];
int n,m,dfn[MAXN],low[MAXN],belong[MAXN],opp[MAXN],cnt,part;
bool instack[MAXN];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void Tarjan(int x)
{
	int t;
	dfn[x]=low[x]=++cnt;
	s.push(x);
	instack[x]=1;
	vector<int>::iterator i;
    for(i=a[x].begin();i!=a[x].end();++i)
    {
    		if(!dfn[*i])
    		{
    			Tarjan(*i);
    			low[x]=min(low[x],low[*i]);
			}
			else if(instack[*i])low[x]=min(low[x],dfn[*i]);
	}
	if(low[x]==dfn[x])
	{
		part++;
		do
		{
			t=s.top();
			s.pop();
			instack[t]=0;
			belong[t]=part;
		}
		while(t!=x);
	}
	return;
}
int main()
{
	n=getint(),m=getint();
	for(rui i=1;i<=m;i++)
	{
		int x=getint()-1,y=getint()-1;
		a[x].push_back(y^1);
		a[y].push_back(x^1);
	}
	for(rui i=0;i<2*n;i++)if(!dfn[i])Tarjan(i);
	for(rui i=0;i<2*n;i++)if(belong[i]==belong[i^1]){printf("NIE\n");return 0;}
	int x;
	for(rui i=0;i<2*n;i++)opp[belong[i]]=belong[i^1];
	memset(instack,0,sizeof(instack));
	for(rui i=1;i<=part;i++)if(!instack[i])instack[opp[i]]=1;
	for(rui i=0;i<2*n;i++)if(!instack[belong[i]])printf("%d\n",i+1);
	return 0;
}

