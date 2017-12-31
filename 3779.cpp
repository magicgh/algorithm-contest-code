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
const int MAXN=205;
vector<int>a[MAXN];
int n,m,ans,Belong[MAXN],vst[MAXN],f[MAXN][MAXN];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline bool DFS(int u,int k)
{
	vector<int>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(vst[*it]==k)continue;
		vst[*it]=k;
		if(!Belong[*it]||DFS(Belong[*it],k))
		{
			Belong[*it]=u;
			return 1;
		}
	}
	return 0; 
}
int main()
{
	n=getint(),m=getint();
	for(ri i=1;i<=m;i++)
	{
		int x=getint(),y=getint();
		f[x][y]=1;
	}
	for(ri k=1;k<=n;k++)
		for(ri i=1;i<=n;i++)
			for(ri j=1;j<=n;j++)
				f[i][j]=(f[i][j]||(f[i][k]&&f[k][j]));
		for(ri i=1;i<=n;i++)
		for(ri j=1;j<=n;j++)
			if(f[i][j])a[i].push_back(j);
	for(ri i=1;i<=n;i++)
		if(DFS(i,i))ans++;
	printf("%d\n",n-ans);
	return 0;
}

