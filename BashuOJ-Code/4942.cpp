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
const int MAXM=205;
vector<int>Edge[MAXN];
int n,m,a[MAXN],f[MAXN][MAXM],g[MAXN][MAXM];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void Tree_DP(int u,int fa)
{
	for(ri i=0;i<=m;i++)f[u][i]=g[u][i]=a[u];
	vector<int>::iterator it;
	for(it=Edge[u].begin();it!=Edge[u].end();++it)
	{
		if(*it==fa)continue;
		Tree_DP(*it,u);
		for(ri j=m;j>=0;j--)
		{
			for(ri k=0;k<=j-1;k++)
			{
				f[u][j]=max(f[u][j],g[u][k]+f[*it][j-k-1]);
				if(j-k>=2)
				{
					g[u][j]=max(g[u][j],g[u][k]+g[*it][j-k-2]);
					f[u][j]=max(f[u][j],f[u][k]+g[*it][j-k-2]);
				}
			}
		}
	}
}
int main()
{
	n=getint(),m=getint();
	for(ri i=1;i<=n;i++)a[i]=1;
	for(ri i=1;i<n;i++)
	{
		int x=getint()+1,y=getint()+1;
		Edge[x].push_back(y);
		Edge[y].push_back(x);
	}
	Tree_DP(1,0);
	printf("%d\n",f[1][m]);
	return 0;
}

