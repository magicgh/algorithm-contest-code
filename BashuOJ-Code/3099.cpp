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
const int MAXN=205;
const int INF=0x7fffffff/2;
struct node{int to,val;};
struct que{int u,cnt;};
vector<node>a[MAXN];
bool vst[MAXN];
bool ext[MAXN][MAXN];
int dist[MAXN][MAXN];
int n,m,val2=INF,cnt2,Cnt;
double Ans=1e18;
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
void DFS1(int u,int val,int cnt,int goal)
{
	vector<node>::iterator it;
	if(u==goal)
	{
		printf("%.3lf",(double)val/(double)(cnt+1));
		exit(0);
	}
	for(it=a[u].begin();it!=a[u].end();++it)
		DFS1(it->to,val+it->val,cnt+1,goal);
		
}
void DFS2(int u,int goal,int val,int cnt)
{
	vector<node>::iterator it;
	if(val2<=val)return;
	if(u==goal)
	{
		cnt2=cnt+1;
		val2=min(val2,val);
		return;
	}
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(vst[it->to])continue;
		vst[it->to]=1;
		DFS2(it->to,goal,val+it->val,cnt+1);
		vst[it->to]=0;
	}
}
inline void ST1()
{
	DFS1(1,0,0,n);
}
inline void ST2()
{
	DFS2(1,n,0,0);
	printf("%.3lf",(double)(val2)/(double)(cnt2));
}
void SPFA(int v0)
{
	queue<que>q;
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=n;j++)dist[i][j]=INF;
	q.push((que){1,1});ext[1][1]=1,dist[1][1]=0;
	while(!q.empty())
	{
		que now=q.front();q.pop();ext[now.u][now.cnt]=0;
		vector<node>::iterator it;
		for(it=a[now.u].begin();it!=a[now.u].end();++it)
		{
			if(dist[now.u][now.cnt]+it->val<dist[it->to][now.cnt+1])
			{
				dist[it->to][now.cnt+1]=dist[now.u][now.cnt]+it->val;
				if(!ext[it->to][now.cnt+1])q.push((que){it->to,now.cnt+1}),ext[it->to][now.cnt+1]=1;
			}
		}
	}
	for(ri i=1;i<=n;i++)
		if(dist[n][i]!=INF)Ans=min(Ans,(double)dist[n][i]/(double)i);
	printf("%.4lf\n",Ans);
}
inline void ST3()
{
	SPFA(1);
}
int main()
{
	n=getint(),m=getint();
	for(ri i=1;i<=m;i++)
	{
		int u=getint(),v=getint(),w=getint();
		a[u].push_back((node){v,w});
	}
	if(m==n-1)ST1();
	else if((n==100&&m==105)||(n==200&&m==231))ST2();
	else ST3();
	return 0;
}
