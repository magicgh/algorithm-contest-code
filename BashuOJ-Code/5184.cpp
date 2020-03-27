#include<iostream>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<queue>
#include<stack>
#define ri register int
#define ll long long
#define pii pair<int,int>
#define mp make_pair
using namespace std;
const int MAXN=200005;
vector<int>a[MAXN];
int N,M,C,cnt,root=1;
int prt[MAXN],dep[MAXN],st[MAXN],ft[MAXN],List[MAXN];
int p[MAXN][20],L[MAXN][2],R[MAXN][2];
int ch[MAXN][2];
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(bj==-1||c=='-')?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
void DFS(int u,int fa,int depth)
{
	st[u]=++cnt,List[cnt]=u;
	prt[u]=fa,dep[u]=depth;
	vector<int>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(*it==fa)continue;
		DFS(*it,u,depth+1);
	}
	ft[u]=cnt;
}
void ST()
{
	memset(p,-1,sizeof(p));
	for(ri i=1;i<=N;i++)p[i][0]=prt[i];
	int k=log2(N);
	for(ri j=1;j<=k;j++)
		for(ri i=1;i<=N;i++)
			if(p[i][j-1]!=-1)p[i][j]=p[p[i][j-1]][j-1];
}
inline int LCA(int a,int b)
{
	if(dep[a]<dep[b])swap(a,b);
	int k=log2(dep[a]);
	for(ri i=k;i>=0;i--)
		if(dep[a]-(1<<i)>=dep[b])a=p[a][i];
	if(a==b)return a;
	for(ri i=k;i>=0;i--)
		if(p[a][i]!=-1&&p[a][i]!=p[b][i])
			a=p[a][i],b=p[b][i];
	return p[a][0];
}
inline int Getdist(int a,int b)
{
	return dep[a]+dep[b]-2*dep[LCA(a,b)];
}
inline pii Merge(int a,int b,int c,int d)
{
	int t1,t2,ret=0;
	int tmp[5]={0,a,b,c,d};
	for(ri i=1;i<4;i++)
		for(ri j=i+1;j<=4;j++)
		{
			if(!tmp[i]||!tmp[j])continue;
			int dist=Getdist(tmp[i],tmp[j]);
			if(ret<dist)
				ret=dist,t1=tmp[i],t2=tmp[j];
		}
	return mp(t1,t2);
}
void Tree_DP(int u,int fa)
{
	ch[u][0]=ch[u][1]=u;
	vector<int>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(*it==fa)continue;
		Tree_DP(*it,u);
		pii now=Merge(ch[u][0],ch[u][1],ch[*it][0],ch[*it][1]);
		ch[u][0]=now.first,ch[u][1]=now.second;
	}
}
inline char Getchar()
{
	char ch=getchar();
	while(!isalpha(ch))ch=getchar();
	return ch;
}
inline int Climb(int x,int depth)
{
	for(ri k=0;depth;depth>>=1,k++)
		if(depth&1)x=p[x][k];
	return x;
}
int main()
{
	//freopen("t.in","r",stdin);
	//freopen("t.out","w",stdout);
	int size=40<<20;
	__asm__ ("movq %0,%%rsp\n"::"r"((char*)malloc(size)+size));
	N=GetInt();
	for(ri i=1;i<N;i++)
	{
		int x=GetInt(),y=GetInt();
		a[x].push_back(y);
		a[y].push_back(x);
	}
	DFS(1,0,1),ST();
	for(ri i=1;i<=N;i++)
		L[i][0]=L[i][1]=R[i][0]=R[i][1]=List[i];
	for(ri i=2;i<=N;i++)
	{
		pii now=Merge(L[i][0],L[i][1],L[i-1][0],L[i-1][1]);
		L[i][0]=now.first,L[i][1]=now.second;
	}
	for(ri i=N-1;i>=1;i--)
	{
		pii now=Merge(R[i][0],R[i][1],R[i+1][0],R[i+1][1]);
		R[i][0]=now.first,R[i][1]=now.second;
	}
	Tree_DP(1,0);
	M=GetInt();
	for(ri i=1;i<=M;i++)
	{
		char op=Getchar();
		if(op=='C')root=GetInt();
		if(op=='Q')
		{
			int u=GetInt(),k=GetInt();
			int lca=LCA(u,root),dist=dep[u]+dep[root]-2*dep[lca];
			pii Point;
			if(dist>=k)
			{
				if(dep[u]-dep[lca]>=k)
				{
					int v=Climb(u,k-1);
					Point=mp(ch[v][0],ch[v][1]);
				}
				else
				{
					int v=Climb(root,dist-k);
					Point=Merge(L[st[v]-1][0],L[st[v]-1][1],R[ft[v]+1][0],R[ft[v]+1][1]);
				}
			}
			else Point=mp(ch[1][0],ch[1][1]);
			printf("%d\n",max(Getdist(u,Point.first),Getdist(u,Point.second)));
		}
	}
	exit(0);
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}