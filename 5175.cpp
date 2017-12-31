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
using namespace std;
const int MAXN=200005;
int n,q,num;
int dep[MAXN],p[MAXN][20];
vector<int>a[MAXN];
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
	p[u][0]=fa,dep[u]=depth;
	int k=log2(dep[u]);
	for(ri j=1;j<=k;j++)
		if(p[u][j-1]!=-1)p[u][j]=p[p[u][j-1]][j-1];
	vector<int>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(*it==fa)continue;
		DFS(*it,u,depth+1);
	}
}
inline int LCA(int a,int b)
{
	if(dep[a]<dep[b])swap(a,b);
	int k=log2(dep[a]);
	for(ri i=k;i>=0;i--)
		if(dep[a]-(1<<i)>=dep[b])
			a=p[a][i];
	if(a==b)return a;
	for(ri i=k;i>=0;i--)
		if(p[a][i]!=-1&&p[a][i]!=p[b][i])
			a=p[a][i],b=p[b][i];
	return p[a][0];
}
inline int Dist(int a,int b){return dep[a]+dep[b]-2*dep[LCA(a,b)];}
int main()
{
	//freopen("t.in","r",stdin);
	//freopen("t.out","w",stdout);
	int size=40<<20;//40M
	//__asm__ ("movl  %0, %%esp\n"::"r"((char*)malloc(size)+size));//调试用这个 
	__asm__ ("movq %0,%%rsp\n"::"r"((char*)malloc(size)+size));//提交用这个 
	n=GetInt(),q=GetInt(),num=GetInt();
	for(ri i=1;i<n;i++)
	{
		int u=GetInt(),v=GetInt();
		a[u].push_back(v);
		a[v].push_back(u);
	}
	memset(p,-1,sizeof(p));
	DFS(1,0,1);
	for(ri i=1;i<=q;i++)
	{
		int a=GetInt(),b=GetInt(),c=GetInt();
		printf("%d\n",((Dist(a,b)+Dist(b,c)-Dist(a,c))>>1)+1);
	}
	exit(0);//必须用exit 
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
