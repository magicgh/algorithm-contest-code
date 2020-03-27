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
struct node{int a,b,c;};
struct inf{int to,val;};
node rel[200005];
int n,m,q,K;
int prt[200005],dep[200005],val[200005],p[200005][25],g[200005][25];
vector<inf>a[200005];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline bool cmp(const node &x,const node &y){return x.c<y.c;}
inline int getfa(int u)
{
	if(prt[u]==u)return u;
	return prt[u]=getfa(prt[u]);
}
void kruskal()
{
	for(ri i=1;i<=n;i++)prt[i]=i;
	for(ri i=1;i<=m;i++)
	{
		int f1=getfa(rel[i].a),f2=getfa(rel[i].b);
		if(f1!=f2)
		{
			prt[f2]=f1;
			a[rel[i].a].push_back((inf){rel[i].b,rel[i].c});
			a[rel[i].b].push_back((inf){rel[i].a,rel[i].c});
		}
	}
}
void DFS(int u,int v,int fa,int d)
{
	val[u]=v;
	dep[u]=d;
	prt[u]=fa;
	vector<inf>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(it->to==fa)continue;
		DFS(it->to,it->val,u,d+1);
	}
}
void ST()
{
	memset(p,-1,sizeof(p));
	for(ri i=1;i<=n;i++)p[i][0]=prt[i],g[i][0]=val[i];
	for(ri j=1;j<=int(log2(n));j++)
		for(ri i=1;i<=n;i++)
		{
			if(p[i][j-1]==-1)continue;
			p[i][j]=p[p[i][j-1]][j-1];
			g[i][j]=max(g[i][j-1],g[p[i][j-1]][j-1]);
		}
}
inline int LCA(int a,int b)
{
	if(dep[a]<dep[b])swap(a,b);
	int k=(int)log2(dep[a]),ret=0;
	for(ri i=k;i>=0;i--)
		if(dep[a]-(1<<i)>=dep[b])
		{
			ret=max(ret,g[a][i]);
			a=p[a][i];
		}
	if(a==b)return ret;
	for(ri i=k;i>=0;i--)
	{
		if(p[a][i]!=-1&&p[a][i]!=p[b][i])
		{
			ret=max(ret,g[a][i]);
			a=p[a][i];
			ret=max(ret,g[b][i]);
			b=p[b][i];
		}
	}
	return max(ret,max(g[a][0],g[b][0]));
}
int main()
{
	n=getint(),m=getint();
	for(ri i=1;i<=m;i++)
	{
		int a=getint(),b=getint(),c=getint();
		rel[i]=(node){a,b,c};
	}
	sort(rel+1,rel+m+1,cmp);
	kruskal();
	memset(prt,0,sizeof(prt));
	DFS(1,0,0,1); 
	ST();
	q=getint();
	for(ri i=1;i<=q;i++)
	{
		int a=getint(),b=getint();
		printf("%d\n",LCA(a,b));
	}
	return 0;
}