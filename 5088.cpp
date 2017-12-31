#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define ri register int
#define ll long long
using namespace std;
const int MAXN=100005;
const int INF=0x7fffffff/2;
struct Path{int cnt,val;};
vector<Path>Tic[MAXN];
vector<int>a[MAXN];
int n,m,q,f[MAXN],g[MAXN][21],p[MAXN][21];
inline const int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
void ST()
{
	int k=log2(n);
	for(ri j=1;j<=k;j++)
		for(ri i=1;i<=n;i++)
			p[i][j]=p[p[i][j-1]][j-1];
}
inline int Climb(int u,int Len)
{
	int k=0,ret=INF;
	while(Len)
	{
		if(Len&1)ret=min(ret,g[u][k]),u=p[u][k];
		Len>>=1,k++;
	}
	return ret;
}
void DFS(int u,int fa)
{
	g[u][0]=f[fa];
	int k=log2(n);
	for(ri j=1;j<=k;j++)
		g[u][j]=min(g[u][j-1],g[p[u][j-1]][j-1]);
	for(vector<Path>::iterator it=Tic[u].begin();it!=Tic[u].end();++it)
		f[u]=min(f[u],Climb(u,it->cnt)+it->val);
	for(vector<int>::iterator it=a[u].begin();it!=a[u].end();++it)
	{
		if(*it==fa)continue;
		DFS(*it,u);
	}	
}
int main()
{
	n=GetInt(),m=GetInt();
	memset(g,0x3f,sizeof(g));
	memset(f,0x3f,sizeof(f));
	for(ri i=1;i<n;i++)
	{
		int u=GetInt(),v=GetInt();
		a[v].push_back(u);
		p[u][0]=v;
	}
	f[1]=0;
	for(ri i=1;i<=m;i++)
	{
		int v=GetInt(),k=GetInt(),w=GetInt();
		Tic[v].push_back((Path){k,w});
	}
	ST(),DFS(1,0);
	q=GetInt();
	for(ri i=1;i<=q;i++)
	{
		int pos=GetInt();
		printf("%d\n",f[pos]);
	}
	return 0;
}


