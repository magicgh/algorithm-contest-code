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
vector<int>a[200005];
int n,d1[200005],d2[200005],d3[200005],prt[200005],from[200005];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void DFSx1(int u)
{
	vector<int>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(prt[u]==*it)continue;
		prt[*it]=u;
		DFSx1(*it);
		if(d1[*it]+1>d1[u])
		{
			d2[u]=d1[u];
			d1[u]=d1[*it]+1;
			from[u]=*it;
		}
		else if(d1[*it]+1>d2[u])d2[u]=d1[*it]+1;
	}
}
void DFSx2(int u)
{
	if(prt[u])
	{
		if(from[prt[u]]==u)d3[u]=max(d2[prt[u]],d3[prt[u]])+1;
		else d3[u]=max(d1[prt[u]],d3[prt[u]])+1;
	}
	vector<int>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(prt[u]==*it)continue;
		DFSx2(*it);
	}
}
int main()
{
	n=getint();
	for(ri i=1;i<n;i++)
	{
		int x=getint()+1,y=getint()+1;
		a[x].push_back(y),a[y].push_back(x);
	}
	DFSx1(1);
	DFSx2(1);
	int maxpath=-0x7fffffff;
	for(ri i=1;i<=n;i++)maxpath=max(maxpath,d1[i]+d2[i]);
	for(ri i=1;i<=n;i++)
		if(d1[i]+max(d2[i],d3[i])==maxpath)printf("%d\n",i-1);
	return 0;
}

