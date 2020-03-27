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
const int MAXN=3005;
const int INF=0x7fffffff;
struct path{int from,to;};
vector<int>a[MAXN];
vector<path>b[MAXN];
int n,m,k,prt[MAXN][MAXN],dist[MAXN][MAXN];
bool bj[MAXN],ext[MAXN][MAXN];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void SPFA(int v0)
{
	queue<path>q;
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=n;j++)dist[i][j]=INF;
	q.push	((path){0,v0});
	dist[0][v0]=0,ext[0][v0]=1;
	while(!q.empty())
	{
		path now=q.front();q.pop();ext[now.from][now.to]=0;
		memset(bj,0,sizeof(bj));
		vector<path>::iterator p;
		for(p=b[now.to].begin();p!=b[now.to].end();++p)if(p->from==now.from)bj[p->to]=1;
		vector<int>::iterator it;
		for(it=a[now.to].begin();it!=a[now.to].end();++it)
		{
			if(bj[*it])continue;
			if(dist[now.to][*it]>dist[now.from][now.to]+1)
			{
				prt[now.to][*it]=now.from;
				dist[now.to][*it]=dist[now.from][now.to]+1;
				if(!ext[now.to][*it])
				{
					path next=(path){now.to,*it};
					q.push(next);
					ext[now.to][*it]=1;
				}
			}
		}
	}
}
int main()
{
	n=getint(),m=getint(),k=getint();
	for(ri i=1;i<=m;i++)
	{
		int u=getint(),v=getint();
		a[u].push_back(v),a[v].push_back(u);
	}
	for(ri i=1;i<=k;i++)
	{
		int x=getint(),y=getint(),z=getint();
		b[y].push_back((path){x,z});
	}
	SPFA(1);
	int ans=INF,num=0;
	for(ri i=1;i<n;i++)
		if(ans>dist[i][n])ans=dist[i][n],num=i;
	printf("%d",ans);
	return 0;
}
