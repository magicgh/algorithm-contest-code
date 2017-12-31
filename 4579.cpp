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
const int MAXN=205;
const int INF=0x7fffffff/2;
const int Mod=10007;
vector<int>a[MAXN];
bool doubleGc;
int n,q,Core,Output,Ans;
int f[MAXN][MAXN],g[MAXN][MAXN][MAXN];
int Size[MAXN],dist[MAXN];
int Corech[MAXN];
inline int max(const int &a,const int &b){return a>b?a:b;}
inline int min(const int &a,const int &b){return a<b?a:b;}
inline bool cmp(const int &a,const int &b){return Size[a]<Size[b];}
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline void Init()
{
	for(ri i=0;i<=n+1;i++)
	{
		a[i].clear();
		Ans=Core=Size[i]=dist[i]=0;
		for(ri j=0;j<=n+1;j++)
		{
			f[i][j]=0;	
			for(ri k=0;k<=n+1;k++)
				g[i][j][k]=0;
		}
	}
}
void DFS(int u,int fa)
{
	Size[u]=1; 
	vector<int>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(*it==fa)continue;
		DFS(*it,u);
		Size[u]+=Size[*it];
		dist[u]=max(dist[u],Size[*it]);
	} 
	dist[u]=max(dist[u],n-Size[u]);
}
void Tree_DP(int u,int fa)//树上背包 
{
	f[u][0]=f[u][1]=1;
	Size[u]=1;
	vector<int>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(*it==fa)continue;
		Tree_DP(*it,u);
		Size[u]+=Size[*it];
		for(ri i=Size[u];i>=2;i--)//f(u,i) 以u为根结点个数为i的子树个数 
			for(ri j=1;j<i;j++)
				f[u][i]=(f[u][i]+(f[u][i-j]*f[*it][j])%Mod)%Mod;
	}
}
inline int LinkGc(int c1,int c2)//合并两个重心 
{
	int NewCore=++n;
	vector<int>::iterator it;
	for(it=a[c1].begin();it!=a[c1].end();++it)
		if(*it==c2)*it=NewCore;
	for(it=a[c2].begin();it!=a[c2].end();++it)
		if(*it==c1)*it=NewCore;
	a[NewCore].push_back(c1);
	a[NewCore].push_back(c2);
	return NewCore;
}
inline void GetCore()
{
	int Gc1=0,Gc2=0,Min=INF;
	doubleGc=0;DFS(1,0);
	for(ri i=1;i<=n;i++)
	{
		if(Min>dist[i])
			Min=dist[i],Gc1=i;
		else if(Min==dist[i])
			Gc2=i;	 
	}
	if(Gc1&&Gc2)
		Core=LinkGc(Gc1,Gc2),doubleGc=1;
	else Core=Gc1;
}
inline void Core_DP()
{
	int Nodecnt=0; 
	for(ri i=0;i<=200;i++)//初始化 
		g[0][i][0]=1;
	for(ri i=1;i<=Corech[0];i++)//重心的前i个儿子
	{
		for(ri j=1;j<=Size[Corech[i]];j++)//最大的结点数(累加) 
			for(ri k=0;k<=j;k++)//当前选择的结点数 
				for(ri p=0;p<=Nodecnt;p++)//上一阶段选择的结点数
					g[i][j][k+p]=(g[i][j][k+p]+(f[Corech[i]][k]*g[i-1][min(j,Size[Corech[i-1]])][p])%Mod)%Mod;
		Nodecnt+=Size[Corech[i]];
	}
	for(ri i=1;i<=Size[Corech[Corech[0]]];i++)//枚举最大连通分量的大小
		for(ri j=(i<<1);j<=n;j++)//枚举相同重心的子树的结点数
			Ans=(Ans+g[Corech[0]][i][j]-g[Corech[0]][i-1][j])%Mod;//若2*i<=j,则重心相同 
}
inline void DP_Main()
{
	Tree_DP(Core,0);	
	Corech[0]=0;
	vector<int>::iterator it;
	for(it=a[Core].begin();it!=a[Core].end();++it)
		Corech[++Corech[0]]=*it;//取出删去重心后的连通分量(重心的儿子) 
	sort(Corech+1,Corech+Corech[0]+1,cmp);//按连通分量的大小排序 
	Core_DP();
}
int main()
{
	q=getint();
	while(q--)
	{
		Init();
		n=getint();
		for(ri i=1;i<n;i++)
		{
			int u=getint(),v=getint();
			a[u].push_back(v);
			a[v].push_back(u);
		}
		GetCore();
		DP_Main();
		printf("Case %d: %d\n",++Output,((Ans-doubleGc)%Mod+Mod)%Mod+1);	
	}
	return 0;
}
