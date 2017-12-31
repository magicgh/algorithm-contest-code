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
const int MAXM=300005;
const int INF=0x7fffffff/2;
struct path{int x,y,z;};
struct node{int to,val;};
vector<node>a[MAXN]; 
path Edge[MAXM];
int n,m;
int prt[MAXN],dep[MAXN],p[MAXN][19],FMax[MAXN][19],SMax[MAXN][19];
int Max1,Max2;
bool OnMST[MAXM];
ll MST,SMST=1e18;
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
	int tot=0;
	sort(Edge+1,Edge+m+1,cmp);
	for(ri i=1;i<=n;i++)prt[i]=i;
	for(ri i=1;i<=m;i++)
	{
		int f1=getfa(Edge[i].x),f2=getfa(Edge[i].y);
		if(f1!=f2)
		{
			prt[f1]=f2,OnMST[i]=1;
			MST+=(ll)Edge[i].z; 
			a[Edge[i].x].push_back((node){Edge[i].y,Edge[i].z});
			a[Edge[i].y].push_back((node){Edge[i].x,Edge[i].z});
			if(++tot>=n-1)break;
		}
	}
}
void DFS(int u,int fa,int depth,int val)
{
	dep[u]=depth,p[u][0]=fa,FMax[u][0]=val;
	vector<node>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(it->to==fa)continue;
		DFS(it->to,u,depth+1,it->val);
	}
}
void ST()
{
	int k=log2(n);
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=k;j++)FMax[i][j]=SMax[i][j]=-INF;
	for(ri j=1;j<=k;j++)
		for(ri i=1;i<=n;i++)
			if(p[i][j-1]!=-1)
			{
				p[i][j]=p[p[i][j-1]][j-1];
				int t1=FMax[i][j-1];
				int t2=FMax[p[i][j-1]][j-1];
				int t3=SMax[i][j-1];
				int t4=SMax[p[i][j-1]][j-1];
				FMax[i][j]=max(t1,t2);
				if(t1!=FMax[i][j])SMax[i][j]=max(SMax[i][j],t1);
				if(t2!=FMax[i][j])SMax[i][j]=max(SMax[i][j],t2);
				if(t3!=FMax[i][j])SMax[i][j]=max(SMax[i][j],t3);
				if(t4!=FMax[i][j])SMax[i][j]=max(SMax[i][j],t4);
			}
}
inline void GetMax(int a,int i)
{
	if(FMax[a][i]>Max1)
	{
		Max2=Max1;
		Max1=FMax[a][i];
		if(SMax[a][i]>Max2)
			Max2=SMax[a][i];
	}
	else if(FMax[a][i]!=Max1&&FMax[a][i]>Max2)
		Max2=FMax[a][i];
}
inline void LCA(int a,int b)
{
	Max1=Max2=-INF;
	if(dep[a]<dep[b])swap(a,b);
	int k=log2(n);
	for(ri i=k;i>=0;i--)
		if(dep[a]-(1<<i)>=dep[b])
		{
			GetMax(a,i);
			a=p[a][i];
		}
	if(a==b)return;
	for(ri i=k;i>=0;i--)
		if(p[a][i]!=-1&&p[a][i]!=p[b][i])
		{
			GetMax(a,i),GetMax(b,i);
			a=p[a][i],b=p[b][i];
		}
	GetMax(a,0),GetMax(b,0);
}
int main()
{
	n=getint(),m=getint();
	for(ri i=1;i<=m;i++)
	{
		int x=getint(),y=getint(),z=getint();
		Edge[i]=(path){x,y,z};
	}
	Kruskal();
	memset(p,-1,sizeof(p));
	DFS(1,0,0,0),ST();
	for(ri i=1;i<=m;i++)
	{
		if(!OnMST[i])
		{
			LCA(Edge[i].x,Edge[i].y);
			if(Edge[i].z==Max1)
				SMST=min(SMST,MST-(ll)Max2+(ll)Edge[i].z);
			else SMST=min(SMST,MST-(ll)Max1+(ll)Edge[i].z);
		}
	}
	printf("%lld\n",SMST);
	return 0;
}


