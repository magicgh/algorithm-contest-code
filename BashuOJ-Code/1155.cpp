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
const int MAXM=50005;
const int MAXN=5060;
struct path{int x,y,z;};
struct node{int to,val;};
path a[MAXM];
vector<node>b[MAXN];
int n,m,q,cnt;
int prt[MAXN],p[MAXN][15],dist[MAXN],d[MAXN],num[105][105];
inline bool cmp(const path &a,const path &b){return a.z<b.z;}
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline int getfa(int u)
{
	if(prt[u]==u)return u;
	return prt[u]=getfa(prt[u]);
}
void Kruskal()
{
	int k=0;
	for(ri i=1;i<=cnt;i++)prt[i]=i;
	for(ri i=1;i<=m;i++)
	{
		int f1=getfa(a[i].x),f2=getfa(a[i].y);
		if(f1!=f2)
		{
			prt[f1]=f2;
			b[a[i].x].push_back((node){a[i].y,a[i].z});
			b[a[i].y].push_back((node){a[i].x,a[i].z});
			if(k==cnt-1)break;
		}
	}
}
void DFS(int u,int dep,int v)
{
	dist[u]=v,d[u]=dep;
	vector<node>::iterator it;
	for(it=b[u].begin();it!=b[u].end();++it)
	{
		if(it->to==p[u][0])continue;
		p[it->to][0]=u;
		DFS(it->to,dep+1,v+it->val);
	}
}
void ST()		
{
	for(ri j=1;j<=log2(cnt);j++)
		for(ri i=1;i<=cnt;i++)
			if(p[i][j-1]!=-1)p[i][j]=p[p[i][j-1]][j-1];
}
inline int LCA(int x,int y)
{
	if(d[x]<d[y])swap(x,y);
	int k=log2(d[x]);
	for(ri i=k;i>=0;i--)
		if(d[x]-(1<<i)>=d[y])x=p[x][i];
	if(x==y)return x;
	for(ri i=k;i>=0;i--)
		if(p[x][i]!=-1&&p[x][i]!=p[y][i])x=p[x][i],y=p[y][i];
	return p[x][0];
}
int main()
{
	n=getint(),m=getint();	
	for(ri i=1;i<=n;i++)
		for(ri j=i;j<=n;j++)num[i][j]=num[j][i]=++cnt;
	for(ri i=1;i<=m;i++)
	{
		int t=getint(),x=getint(),y=getint(),v=getint();
		a[i]=(path){num[t][x],num[t][y],v};
	}
	sort(a+1,a+m+1,cmp);
	Kruskal();
	memset(p,-1,sizeof(-1));
	DFS(1,0,0);
	ST();
	q=getint();
	for(ri i=1;i<=q;i++)
	{
		int s1=getint(),s2=getint(),t1=getint(),t2=getint();
		int u=num[s1][s2],v=num[t1][t2];
		printf("%d\n",dist[u]+dist[v]-(2*dist[LCA(u,v)]));
	}
	return 0;
}


