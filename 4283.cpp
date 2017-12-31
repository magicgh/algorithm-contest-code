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
const int MAXN=200005;
vector<int>a[MAXN];
int n,prt[MAXN],Size[MAXN],Max[MAXN],id[MAXN],Ans=0x7fffffff;
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
	Size[u]=1;
	vector<int>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(*it==prt[u])continue;
		prt[*it]=u,DFSx1(*it);
		Size[u]+=Size[*it];
	}
}
void DFSx2(int u)
{
	Max[u]=max(Max[u],n-Size[u]);
	vector<int>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(*it==prt[u])continue;
		DFSx2(*it);
		Max[u]=max(Max[u],Size[*it]);
	}
}
int main()
{
	n=getint();
	for(ri i=1;i<n;i++)
	{
		int x=getint()+1,y=getint()+1;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	DFSx1(1),DFSx2(1);
	for(ri i=1;i<=n;i++)
	{
		if(Ans>Max[i])
		{
			Ans=Max[i];
			id[0]=0;
		}
		if(Ans==Max[i])id[++id[0]]=i;
	}
	printf("%d %d\n",Ans,id[0]);
	for(ri i=1;i<=id[0];i++)printf("%d",id[i]-1);
	return 0;
}
