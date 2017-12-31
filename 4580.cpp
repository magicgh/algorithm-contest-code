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
const int MAXN=30005;
const int INF=0x7fffffff/2;
struct node{int to,val;};
deque<int>q;
vector<node>a[MAXN],b[MAXN];
int n,m,k,depmax;
int Core,val;
bool ext[MAXN],vst[MAXN];
int dist[MAXN],prt[MAXN],Size[MAXN];
int f[MAXN],g[MAXN],sf[MAXN],sg[MAXN];
int fAns,gAns;
inline int max(const int &a,const int &b){return a>b?a:b;}
inline int min(const int &a,const int &b){return a<b?a:b;}
inline bool cmp(const node &a,const node &b){return a.to<b.to;}
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void Build(int u)
{
	vst[u]=1;
	vector<node>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(vst[it->to]||dist[it->to]!=dist[u]+it->val)continue;
		b[u].push_back((node){it->to,it->val});
		b[it->to].push_back((node){u,it->val});
		Build(it->to);
	} 
}
void SPFA(int v0)
{
	for(ri i=1;i<=n;i++)dist[i]=INF,ext[i]=0;
	q.push_back(v0),dist[v0]=0;ext[v0]=1;
	while(!q.empty())
	{
		int now=q.front();q.pop_front();ext[now]=0;
		vector<node>::iterator it;
		for(it=a[now].begin();it!=a[now].end();++it)
		{
			if(dist[now]+it->val<dist[it->to])
			{
				dist[it->to]=dist[now]+it->val;
				prt[it->to]=now;
				if(!ext[it->to])
				{
					if(!q.empty()&&dist[q.front()]>dist[it->to])q.push_front(it->to);
					else q.push_back(it->to);
					ext[it->to]=1;
				}
			}
		}	
	}
}
void GetSize(int u,int fa)
{
	Size[u]=1;
	vector<node>::iterator it;
	for(it=b[u].begin();it!=b[u].end();++it)
	{
		if(it->to==fa||vst[it->to])continue;
		GetSize(it->to,u);
		Size[u]+=Size[it->to];
	}
}
void GetCore(int u,int fa,int num)
{
	int Max=0;Size[u]=1;
	vector<node>::iterator it;
	for(it=b[u].begin();it!=b[u].end();++it)
	{
		if(it->to==fa||vst[it->to])continue;
		GetCore(it->to,u,num);
		Size[u]+=Size[it->to];
		Max=max(Max,Size[it->to]);
	}
	Max=max(Max,num-Size[u]);
	if(Max<val)val=Max,Core=u;
}
void GetDepth(int u,int fa,int dep)
{
	depmax=max(depmax,dep);
	vector<node>::iterator it;
	for(it=b[u].begin();it!=b[u].end();++it)
	{
		if(it->to==fa||vst[it->to])continue;
		GetDepth(it->to,u,dep+1);
	}
}
void GetPath(int u,int fa,int dep,int dist)
{
	if(f[dep]<dist)f[dep]=dist,g[dep]=1;
	else if(f[dep]==dist)g[dep]++;
	vector<node>::iterator it;
	for(it=b[u].begin();it!=b[u].end();++it)
	{
		if(it->to==fa||vst[it->to])continue;
		GetPath(it->to,u,dep+1,dist+it->val);
	}
}
void Calc(int u)
{
	for(ri i=0;i<=k;i++)
		sf[i]=sg[i]=0;
	sg[0]=1;
	vector<node>::iterator it;
	for(it=b[u].begin();it!=b[u].end();++it)
	{
		if(vst[it->to])continue;
		depmax=0;
		GetDepth(it->to,u,1);
		for(ri i=0;i<=depmax;i++)f[i]=g[i]=0;
		GetPath(it->to,u,1,it->val);
		for(ri i=0;i<=min(depmax,k);i++)
		{
			if(fAns<f[i]+sf[k-i])fAns=f[i]+sf[k-i],gAns=g[i]*sg[k-i];
			else if(fAns==f[i]+sf[k-i])gAns+=g[i]*sg[k-i];
		}
		for(ri i=0;i<=min(depmax,k);i++)
		{
			if(f[i]>sf[i])sf[i]=f[i],sg[i]=g[i];
			else if(f[i]==sf[i])sg[i]+=g[i];
		}
	}
}
void DFS(int u,int num)
{
	val=INF;
	GetCore(u,0,num);
	int x=Core;
	vst[x]=1;
	Calc(x);
	GetSize(x,0);
	vector<node>::iterator it;
	for(it=b[x].begin();it!=b[x].end();++it)
	{
		if(vst[it->to])continue;
		DFS(it->to,Size[it->to]);
	}
}
int main()
{
	n=getint(),m=getint(),k=getint()-1;
	for(ri i=1;i<=m;i++)
	{
		int u=getint(),v=getint(),w=getint();
		a[u].push_back((node){v,w});
		a[v].push_back((node){u,w});
	}
	for(ri i=1;i<=n;i++)
		sort(a[i].begin(),a[i].end(),cmp);
	SPFA(1);Build(1);
	memset(vst,0,sizeof(vst));
	DFS(1,n);
	printf("%d %d\n",fAns,gAns);
	return 0;
}