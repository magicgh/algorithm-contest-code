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
node rel[100005];
int n,m,q;
int prt[100005],dep[100005],val[100005],p[100005][25],g[100005][25];
vector<inf>a[100005];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline bool cmp(const node &x,const node &y){return x.c>y.c;}
inline int getfa(int u)
{
	if(prt[u]==u)return u;
	return prt[u]=getfa(prt[u]);
}
void kruscal()
{
	for(ri i=1;i<=n;i++)prt[i]=i;
	for(ri i=1;i<=m;i++)
	{
		int f1=getfa(rel[i].a),f2=getfa(rel[i].b);
		if(f1!=f2)
		{
			prt[f1]=f2;
			a[rel[i].a].push_back((inf){rel[i].b,rel[i].c});
			a[rel[i].b].push_back((inf){rel[i].a,rel[i].c});
		}
	}
}
void DFS(int u,int v,int d)
{
	val[u]=v;
	dep[u]=d;
	vector<inf>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(prt[u]==it->to)continue;
		prt[it->to]=u;
		DFS(it->to,it->val,d+1);
	}
}
void ST()
{
	memset(p,-1,sizeof(p));
	for(ri i=1;i<=n;i++)p[i][0]=prt[i],g[i][0]=val[i];
	for(ri j=1;j<=int(log2(n));j++)
		for(ri i=1;i<=n;i++)
		{
			if(!p[i][j-1])continue;
			p[i][j]=p[p[i][j-1]][j-1];
			g[i][j]=min(g[i][j-1],g[p[i][j-1]][j-1]);
		}
}
inline long long LCA(int a,int b)
{
	if(dep[a]<dep[b])swap(a,b);
	int k=log2(dep[a]),ret=0x7fffffff/2;
	for(ri i=k;i>=0;i--)
		if(dep[a]-(1<<i)>=dep[b])
		{
			ret=min(ret,g[a][i]);
			a=p[a][i];
		}
	if(a==b)return ret;
	for(ri i=k;i>=0;i--)
	{
		if(p[a][i]!=-1&&p[a][i]!=p[b][i])
		{
			ret=min(ret,g[a][i]);
			a=p[a][i];
			ret=min(ret,g[b][i]);
			b=p[b][i];
		}
	}
	return min(ret,min(g[a][0],g[b][0]));
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
	kruscal();
	memset(prt,0,sizeof(prt));
	DFS(1,0,1);
	ST();
	q=getint();
	for(ri i=1;i<=q;i++)
	{
		int a=getint(),b=getint();
		long long ans=LCA(a,b);
		printf("%lld\n",!ans?-1:ans);
	}
	return 0;
}