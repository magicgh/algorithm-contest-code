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
const int INF=0x7fffffff;
int n,k,ch[105][2],w[105],prt[105],dist[105][105],son[105],f[105][55][105];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
int DP(int u,int m,int near)
{
	if(u==-1)return 0;
	if(f[u][m][near]!=-1)return f[u][m][near];
	f[u][m][near]=INF/2;
	dist[u][near]=dist[near][u]=dist[near][prt[u]]+dist[prt[u]][u];
	for(ri t=0;t<=m;t++)
	{
		f[u][m][near]=min(f[u][m][near],DP(ch[u][0],t,near)+DP(ch[u][1],m-t,near)+w[u]*dist[near][u]);
		if(t<=m-1)f[u][m][near]=min(f[u][m][near],DP(ch[u][0],t,u)+DP(ch[u][1],m-t-1,near));
	}
	return f[u][m][near];
}
int main()
{
	memset(f,-1,sizeof(f));
	memset(ch,-1,sizeof(ch));
	n=getint(),k=getint();
	for(ri i=1;i<=n;i++)
	{
		w[i]=getint(),prt[i]=getint(),dist[i][prt[i]]=dist[prt[i]][i]=getint();
		if(son[prt[i]]==0)ch[prt[i]][0]=i;//儿子 
		else ch[son[prt[i]]][1]=i;//兄弟 
		son[prt[i]]=i;
	}
	printf("%d",DP(0,k,0));
	return 0;
}

