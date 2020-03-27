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
const int MAXN=6005;
vector<int>a[MAXN];
int n,root=1,Ha[MAXN],Deg[MAXN],f[MAXN][2];
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
	f[u][0]=0,f[u][1]=Ha[u];
	vector<int>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		Tree_DP(*it);
		f[u][0]=max(f[u][0],max(f[u][0]+f[*it][0],f[u][0]+f[*it][1]));
		f[u][1]=max(f[u][1],f[u][1]+f[*it][0]);
	}
}
int main()
{
	n=getint();
	for(ri i=1;i<=n;i++)Ha[i]=getint();
	while(true)
	{
		int u=getint(),v=getint();
		if(u==0&&v==0)break;
		a[v].push_back(u);
		Deg[u]++;
	}
	while(Deg[root])root++;
	Tree_DP(root);
	printf("%d",max(f[root][0],f[root][1]));
	return 0;
}
