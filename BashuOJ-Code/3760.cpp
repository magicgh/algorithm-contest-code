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
stack<int>s;
int n,cnt,bcc,ans,p[MAXN],dfn[MAXN],low[MAXN],belong[MAXN],prt[MAXN],point[MAXN];
double k;
int f[MAXN][2],g[MAXN][2];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void Tarjan(int u)
{
	int t;
	dfn[u]=low[u]=++cnt;
	s.push(u);
	vector<int>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(prt[u]!=*it)
		{
			if(!dfn[*it])
			{
				prt[*it]=u;
				Tarjan(*it);
				low[u]=min(low[u],low[*it]);
			}
			else low[u]=min(low[u],dfn[*it]);
		}
	}
	if(low[u]==dfn[u])
	{
		if(s.top()==u){s.pop();return;}//排除非环误判的情况 
		bcc++;
		do
		{
			t=s.top();s.pop();
			belong[t]=bcc;
			point[++point[0]]=t;
		}while(t!=u);
	} 
	return;
}
void Tree_DP(int u)
{
	f[u][0]=0,f[u][1]=p[u];
	vector<int>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(prt[u]!=*it&&!belong[*it])
		{
			prt[*it]=u;
			Tree_DP(*it);
			f[u][0]+=max(f[*it][0],f[*it][1]);
			f[u][1]+=f[*it][0];
		}
	}
}
void DP()
{
	memset(prt,0,sizeof(prt));
	for(ri i=1;i<=point[0];i++)Tree_DP(point[i]);
	for(ri i=1;i<=point[0];i++)
	{
		g[i][0]=f[point[i]][0];
		g[i][1]=f[point[i]][1];
	}
	//第一个节点不选
	f[2][0]=g[2][0]+g[1][0];
	f[2][1]=g[2][1]+g[1][0];
	for(ri i=3;i<=point[0];i++)
	{
		f[i][0]=max(f[i-1][0],f[i-1][1])+g[i][0];
		f[i][1]=f[i-1][0]+g[i][1];
	}
	ans=max(ans,max(f[point[0]][0],f[point[0]][1]));
	//第一个节点选 
	f[2][0]=g[2][0]+g[1][1];
	f[2][1]=-0x7fffffff/2;
	for(ri i=3;i<=point[0];i++)
	{
		f[i][0]=max(f[i-1][0],f[i-1][1])+g[i][0];
		f[i][1]=f[i-1][0]+g[i][1];
	}
	ans=max(ans,f[point[0]][0]);//不能和f[point[0]][1]比较（环） 
	printf("%.1lf",double(ans)*k);
} 
int main()
{
	n=getint();
	for(ri i=1;i<=n;i++)p[i]=getint();
	for(ri i=1;i<=n;i++)
	{
		int x=getint()+1,y=getint()+1;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	scanf("%lf",&k);
	Tarjan(1);
	DP();
	return 0;
}
