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
const int MAXN=100005;
vector<int>a[MAXN];	
int n,f[MAXN][2],prt[MAXN],p[MAXN];
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
	f[u][0]=0,f[u][1]=p[u];
	vector<int>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(prt[u]!=*it)
		{
			prt[*it]=u;
			Tree_DP(*it);
			f[u][1]+=f[*it][0];
			f[u][0]+=max(f[*it][0],f[*it][1]);
		}
	}
}
int main()
{
	n=getint();
	for(ri i=1;i<=n;i++)p[i]=getint();
	for(ri i=1;i<n;i++)
	{
		int u=getint(),v=getint();
		a[u].push_back(v);
		a[v].push_back(u);
	}
	Tree_DP(1);
	printf("%d",max(f[1][0],f[1][1]));
	return 0;
}
