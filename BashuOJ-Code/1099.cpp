#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<vector>
#define ri register int
using namespace std;
const int MAXN=50005;
vector<int>a[MAXN];
int n,f[MAXN][15],prt[MAXN],Min=0x7fffffff/2;
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void Tree_DP(int u)
{
	vector<int>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(prt[u]==*it)continue;
		prt[*it]=u;
		Tree_DP(*it);
		for(ri i=1;i<=10;i++)
		{
			int Ans=0x7fffffff/2;
			for(ri j=1;j<=10;j++)
				if(i!=j)Ans=min(Ans,f[*it][j]);
			f[u][i]+=Ans;
		}
	}
}
int main()
{
	n=getint();
	for(ri i=1;i<n;i++)
	{
		int u=getint(),v=getint();
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=10;j++)f[i][j]=j;
	Tree_DP(1);
	for(ri i=1;i<=10;i++)Min=min(Min,f[1][i]);
	printf("%d\n",Min);
	return 0;
}
