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
struct node{int to,val;};
vector<node>a[250005];
vector<int>edge[250005];
int n,m,k,dcnt,dep[250005],dfn[250005],p[250005][20],h[250005],Stack[250005];
long long Min[250005],f[250005];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline bool cmp(const int &x,const int &y){return dfn[x]<dfn[y];}
inline void AddEdge(int u,int v)
{
	if(u==v)return;
	edge[u].push_back(v);
}
void DFS(int u,int depth)
{
	dep[u]=depth,dfn[u]=++dcnt;
	vector<node>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(it->to==p[u][0])continue;
		Min[it->to]=min(Min[u],(long long)it->val);
		p[it->to][0]=u;
		DFS(it->to,depth+1);
	}
}
void ST()
{
	for(ri j=1;j<=int(log2(n));j++)
		for(ri i=1;i<=n;i++)
			if(p[i][j-1]!=-1)p[i][j]=p[p[i][j-1]][j-1];
}
int LCA(int a,int b)
{
	if(dep[a]<dep[b])swap(a,b);
	int k=int(log2(dep[a]));
	for(ri i=k;i>=0;i--)if(dep[a]-(1<<i)>=dep[b])a=p[a][i];
	if(a==b)return a;
	for(ri i=k;i>=0;i--)if(p[a][i]!=-1&&p[a][i]!=p[b][i])a=p[a][i],b=p[b][i];
	return p[a][0];
}
void Tree_DP(int u)
{
	long long ans=0;
	f[u]=Min[u];
	vector<int>::iterator it;
	for(it=edge[u].begin();it!=edge[u].end();++it)
	{
		 
		Tree_DP(*it);
		ans+=f[*it]; 
	}
	edge[u].clear();
	if(!ans)f[u]=Min[u];
	else f[u]=min(f[u],ans);
}
void Solve()
{
	int cnt=0,top=0;
	h[++cnt]=h[1];
	for(ri p=2;p<=k;p++)if(LCA(h[p],h[cnt])!=h[cnt])h[++cnt]=h[p];//特殊点在一条链上的情况
	Stack[++top]=1;
	for(ri i=1;i<=cnt;i++)
	{
		int now=h[i],fa=LCA(now,Stack[top]);
		while(true)
		{
			if(dep[fa]>=dep[Stack[top-1]])//lca在stack[top-1]与stack[top]之间 
			{
				AddEdge(fa,Stack[top--]);//中间没有特殊点,化链
				if(Stack[top]!=fa)Stack[++top]=fa;//避免重复加点
				break; 
			}
			AddEdge(Stack[top-1],Stack[top]),top--;//lca在stack[top-1]上面的情况 
		}
		if(Stack[top]!=now)Stack[++top]=now;//加入当前特殊点 
	}
	while(top--)AddEdge(Stack[top],Stack[top+1]);
	Tree_DP(1);//从根节点开始树形DP
	printf("%lld\n",f[1]);
}
int main()
{
	n=getint();
	for(ri i=1;i<n;i++)
	{
		int u=getint(),v=getint(),w=getint();
		a[u].push_back((node){v,w});
		a[v].push_back((node){u,w});
	}
	memset(p,-1,sizeof(p));Min[1]=1e20;
	DFS(1,0),ST();
	m=getint();
	for(ri i=1;i<=m;i++)
	{
		k=getint();
		for(ri j=1;j<=k;j++)h[j]=getint();
		sort(h+1,h+k+1,cmp);
		Solve();
	}
	return 0;
}
