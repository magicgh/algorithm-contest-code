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
const int MAXN=10005;
vector<int>a[MAXN];
int N,T,n,m1,m2,prt[MAXN],dep[MAXN],A,B;
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void DFS(int u,int depth)
{
	dep[u]=depth;
	vector<int>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(*it==prt[u])continue;
		prt[*it]=u,DFS(*it,depth+1);
	}
}
int main()
{
	T=getint();
	while(T--)
	{
		A=B=0;
		for(ri i=1;i<MAXN;i++)a[i].clear(),prt[i]=0,dep[i]=0;
		n=getint(),m1=getint(),m2=getint();
		for(ri i=1;i<n;i++)
		{
			int x=getint()+1,y=getint()+1;
			a[x].push_back(y),a[y].push_back(x);
		}
		DFS(1,0);
		for(ri i=1;i<=m1;i++)
		{
			int x=getint()+1;
			A+=dep[x];
		}
		for(ri i=1;i<=m2;i++)
		{
			int x=getint()+1;
			B+=dep[x];
		}
		if(A<=B)printf("Bob\n");
		else printf("Alice\n");
	}
	return 0;
}

