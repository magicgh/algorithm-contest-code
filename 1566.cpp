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
struct node{int to,val;};
struct Node{int to,val,cnt;};
vector<node>a[MAXN];
vector<Node>b[MAXN];
int n,m,Ans=INF,Deg[MAXN];
bool vst[MAXN];
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline void AddEdge(int u,int v,int w)
{
	a[u].push_back((node){v,w});
	Deg[v]++;
}
inline void Add(int u,int v,int w,int cnt)
{
	b[u].push_back((Node){v,w,cnt});
}
void Build(int u,int fa,int Head,int len,int cnt)
//cnt 链进过点的个数 
{
	vector<node>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(it->to==fa)continue;
		if(Deg[it->to]==2)
			Build(it->to,u,Head,len+it->val,cnt+1);
		else Add(Head,it->to,len+it->val,cnt);
	}
}
void DFS(int u,int fa,int Head,int cnt,int ret)
{
	if(ret>=Ans)return;
	if(cnt==n&&u==Head)Ans=min(Ans,ret);
	if(vst[u])return;
	vst[u]=1;
	vector<Node>::iterator it;
	for(it=b[u].begin();it!=b[u].end();++it)
		DFS(it->to,u,Head,cnt+it->cnt+1,ret+it->val);
	vst[u]=0;
}
int main()
{
	//freopen("t.in","r",stdin);
	//freopen("t.out","w",stdout);
	n=getint(),m=getint();
	for(ri i=1;i<=m;i++)
	{
		int u=getint(),v=getint(),w=getint();
		AddEdge(u,v,w),AddEdge(v,u,w);
	}
	for(ri i=1;i<=n;i++)
		if(Deg[i]!=2)Build(i,0,i,0,0);
	for(ri u=1;u<=n;u++)
		if(b[u].size()){DFS(u,0,u,0,0);break;}
	printf("%d\n",Ans);
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}


