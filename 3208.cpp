#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#define ri register int
using namespace std;
const int MAXN=4005;
vector<int>a[MAXN];
int n,cnt,part;
int dfn[MAXN],low[MAXN],Belong[MAXN],Ans[MAXN],Stack[MAXN];
bool Ins[MAXN];
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline void Putint(int x)
{
     if(x<0)putchar('-'),x=-x;
     if(x>9)Putint(x/10);
     putchar(x%10+'0');
}
void Tarjan(int u)
{
	dfn[u]=low[u]=++cnt;
	Stack[++Stack[0]]=u,Ins[u]=1;
	vector<int>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(!dfn[*it])
		{
			Tarjan(*it);
			low[u]=min(low[u],low[*it]);
		}	
		else if(Ins[*it])
			low[u]=min(low[u],dfn[*it]);
	} 
	int t;
	if(low[u]==dfn[u])
	{
		part++;
		do
		{
			t=Stack[Stack[0]--],Ins[t]=0;
			Belong[t]=part;
		}
		while(t!=u);
	}
}
int main()
{
	n=getint();
	for(ri i=1;i<=n;++i)
	{
		int Size=getint();
		for(ri j=1;j<=Size;j++)
			a[i].push_back(n+getint());//建二分图 
	}
	for(ri i=1;i<=n;++i)
	{
		int x=getint();
		a[n+x].push_back(i);//最优匹配 
	}
	for(ri i=1;i<=n;++i)
		if(!dfn[i])Tarjan(i);
	for(int u=1;u<=n;++u)
	{
		Ans[0]=0;
		vector<int>::iterator it;
		for(it=a[u].begin();it!=a[u].end();++it)
		{
			if(Belong[u]==Belong[*it])
				Ans[++Ans[0]]=*it;
		}
		Putint(Ans[0]);
		putchar(32);
		sort(Ans+1,Ans+Ans[0]+1);
		for(ri i=1;i<=Ans[0];++i)
			Putint(Ans[i]-n),putchar(32);	
		putchar(10);
	}
	return 0;
}