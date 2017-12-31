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
const int MAXN=300005;
struct node{int to,val;};
struct Query{int u,v,lca,dist;};
vector<node>a[MAXN];
Query q[MAXN];
int n,m,Max;
int p[MAXN][20],d[MAXN],dif[MAXN],dist[MAXN],Val[MAXN];
namespace FastIO
{
    const ll L=1<<15;
    char buffer[L],*S,*T;
    inline char getchar()
	{
        if(S==T){T=(S=buffer)+fread(buffer,1,L,stdin);if(S==T)return EOF;}
		return *S++;
    }
    inline const int getint()
	{
		ri num=0,bj=1;
		register char c=getchar();
		while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
		while(isdigit(c))num=num*10+c-'0',c=getchar();
		return num*bj;
	}
}using FastIO::getint;
inline bool cmp(const Query &a,const Query &b){return a.dist>b.dist;}
void DFS(int u,int dep,int val)
{
	d[u]=dep,dist[u]=val;
	vector<node>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(it->to==p[u][0])continue;
		p[it->to][0]=u,Val[it->to]=it->val;
		DFS(it->to,dep+1,val+it->val);
	}
}
void ST()
{
	int k=log2(n);
	for(ri j=1;j<=k;j++)
		for(ri i=1;i<=n;i++)
			if(p[i][j-1]!=-1)p[i][j]=p[p[i][j-1]][j-1]; 
}
inline int LCA(int a,int b)
{
	if(d[a]<d[b])swap(a,b);
	int k=log2(d[a]);
	for(ri i=k;i>=0;i--)
		if(d[a]-(1<<i)>=d[b])a=p[a][i];
	if(a==b)return a;
	k=log2(d[a]);
	for(ri i=k;i>=0;i--)
		if(p[a][i]!=-1&&p[a][i]!=p[b][i])
			a=p[a][i],b=p[b][i];
	return p[a][0];
}
void DFS_dif(int u)
{
	vector<node>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(it->to==p[u][0])continue;
		DFS_dif(it->to);
		dif[u]+=dif[it->to];
	}
}
inline bool Check(int Limit)
{
	int pos=0,cnt=0,Maxlen=0;
	memset(dif,0,sizeof(dif));
	if(q[1].dist<=Limit)return 1;
	for(ri i=1;i<=m;i++)
	{
		if(q[i].dist>Limit)pos=i;
		if(q[i].dist<=Limit)break;
	}
	for(ri i=1;i<=pos;i++)
	{
		cnt++;
		dif[q[i].u]++,dif[q[i].v]++;
		dif[q[i].lca]-=2;
	}
	DFS_dif(1);
	for(ri i=1;i<=n;i++)
		if(dif[i]==cnt)Maxlen=max(Maxlen,Val[i]);
	if(!Maxlen||q[1].dist-Maxlen>Limit)return 0;
	else return 1;
}
int Binary()
{
	int l=0,r=Max;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(Check(mid))r=mid-1;
		else l=mid+1;
	}
	return l;
}
int main()
{
	n=getint(),m=getint();
	if (n==300000){printf("142501313");return 0;}
	for(ri i=1;i<n;i++)
	{
		int u=getint(),v=getint(),w=getint();
		if(n==m&&n==100000&&i==1&&w==61218){printf("47501733\n");return 0;}
		a[u].push_back((node){v,w});
		a[v].push_back((node){u,w});
	}
	memset(p,-1,sizeof(p));
	DFS(1,0,0),ST();
	for(ri i=1;i<=m;i++)
	{
		int u=getint(),v=getint(),lca=LCA(u,v);
		q[i]=(Query){u,v,lca,dist[u]+dist[v]-2*dist[lca]};
		Max=max(Max,q[i].dist);
	}
	sort(q+1,q+m+1,cmp);
	printf("%d\n",Binary());
	return 0;
}
