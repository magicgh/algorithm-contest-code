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
const int MAXN=100005;
const int Mod=998244353;
const int INF=0x7fffffff/2;
struct Strong{ll mul_1,c,mul_2,plus,times;};
struct node{int to,val;};
vector<node>a[MAXN];
vector<int>b[MAXN];
struct heap
{
	int u,dist;
	bool operator <(const heap &rhs)
	const{return dist>rhs.dist;}
};
Strong E[MAXN];
ll Ans[MAXN];
int n,m,st;
int dist[MAXN],prt[MAXN];
bool vst[MAXN];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline ll getll()
{
	ll num=0;int bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
void Dijkstra(int v0)
{
	priority_queue<heap>q;
	for(ri i=1;i<=n;i++)dist[i]=INF;
	dist[v0]=0,q.push((heap){v0,dist[v0]});
	while(!q.empty())
	{
		heap now=q.top();q.pop();
		if(vst[now.u])continue;
		vst[now.u]=1;
		vector<node>::iterator it;
		for(it=a[now.u].begin();it!=a[now.u].end();++it)
		{
			if(!vst[it->to]&&dist[now.u]+it->val<dist[it->to])
			{
				prt[it->to]=now.u;
				dist[it->to]=dist[now.u]+it->val;
				q.push((heap){it->to,dist[it->to]});
			}
		}
	}
}
void Build()
{
	for(ri i=1;i<=n;i++)
		if(prt[i])b[prt[i]].push_back(i);
}
void DFSx1(int u,int fa)
{
	ll T=E[u].times,val=Ans[fa],C=E[u].c;
	while(T--)
	{
		val=((val%Mod*E[u].mul_1%Mod)%Mod+C)%Mod;
		C=((C%Mod*E[u].mul_2%Mod)%Mod+E[u].plus)%Mod;
	}
	Ans[u]=val;
	vector<int>::iterator it;
	for(it=b[u].begin();it!=b[u].end();++it)
		DFSx1(*it,u);
	
}
void Solvex1()
{
	Ans[0]=(ll)st;
	DFSx1(1,0);
	for(ri i=1;i<=n;i++)printf("%lld\n",Ans[i]);
}
struct Matrix
{
	static const int SIZE=5;
	int n,m;
	ll a[SIZE][SIZE];
	Matrix(int n,int m)
	{
		this->n=n,this->m=m;
		memset(a,0,sizeof(a));
	}
	Matrix operator *(const Matrix &b)
	{
		Matrix c(n,b.m);
		for(ri i=1;i<=n;i++)
			for(ri j=1;j<=b.m;j++)
				for(ri k=1;k<=m;k++)
					c.a[i][j]=(c.a[i][j]+(a[i][k]%Mod*b.a[k][j]%Mod)%Mod)%Mod;
		return c;
	}
	Matrix Pow(Matrix &base,ll b)
	{
		Matrix ret=*this;
		while(b)	
		{
			if(b&1)ret=ret*base;
			base=base*base;
			b>>=1;
		}
		return ret;
	}
};
void DFSx2(int u,int fa)
{
	Matrix T(1,3),base(3,3);
	T.a[1][1]=Ans[fa],T.a[1][2]=E[u].c,T.a[1][3]=E[u].plus;
	base.a[1][1]=E[u].mul_1,base.a[2][2]=E[u].mul_2;
	base.a[2][1]=base.a[3][2]=base.a[3][3]=1;
	T=T.Pow(base,E[u].times);
	Ans[u]=T.a[1][1];
	vector<int>::iterator it;	
	for(it=b[u].begin();it!=b[u].end();++it)
		DFSx2(*it,u);
	
}
void Solvex2()
{
	Ans[0]=(ll)st;
	DFSx2(1,0);
	for(ri i=1;i<=n;i++)printf("%lld\n",Ans[i]);
}
int main()
{
	n=getint(),m=getint(),st=getint();
	for(ri i=1;i<=n;i++)
	{
		ll mul_1=getll(),c=getll(),mul_2=getll(),plus=getll(),times=getll();
		E[i]=(Strong){mul_1,c,mul_2,plus,times};
	}
	for(ri i=1;i<=m;i++)
	{
		int u=getint(),v=getint(),w=getint();
		a[u].push_back((node){v,w});
		a[v].push_back((node){u,w});
	}
	Dijkstra(1);
	Build();
	if(n<=1000)Solvex1();
	else Solvex2();
	return 0;
}