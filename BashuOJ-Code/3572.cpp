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
const int MAXN=2005;
vector<int>a[MAXN];
stack<int>s;
int dfn[MAXN],low[MAXN],belong[MAXN];
int n,m,cnt,part;
bool ins[MAXN];
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
	dfn[x]=low[x]=++cnt;
	s.push(x);ins[x]=1;
	vector<int>::iterator it;
	for(it=a[x].begin();it!=a[x].end();++it)
	{
		if(!dfn[*it])
		{
			Tarjan(*it);
			low[x]=min(low[x],low[*it]);
		}
		else if(ins[*it])low[x]=min(low[x],dfn[*it]);
	}
	if(low[x]==dfn[x])
	{
		int u;part++;
		do
		{
			u=s.top();s.pop();ins[u]=0;belong[u]=part;
		}while(u!=x);
	}
}
int main()
{
	n=getint(),m=getint();
	char ch[4];
	for(rui i=1;i<=m;i++)
	{
		int x=getint(),y=getint(),c=getint();
		scanf("%s",&ch);
		switch(ch[0])
		{
			case 'A':
			if(c)a[x].push_back(x+n),a[y].push_back(y+n);
			else a[x+n].push_back(y),a[y+n].push_back(x);break;
			case 'O':
			if(c)a[x].push_back(y+n),a[y].push_back(x+n);
			else a[x+n].push_back(x),a[y+n].push_back(y);break;	
			case 'X':
			if(c)a[x].push_back(y+n),a[x+n].push_back(y),a[y].push_back(x+n),a[y+n].push_back(x);
			else a[x].push_back(y),a[y].push_back(x),a[x+n].push_back(y+n),a[y+n].push_back(x+n);break;
		}
	}
	for(rui i=0;i<2*n;i++)if(!dfn[i])Tarjan(i);
	for(rui i=0;i<n;i++)
		if(belong[i]==belong[i+n]){printf("NO\n");return 0;}
	printf("YES\n");	
	return 0;	
}

