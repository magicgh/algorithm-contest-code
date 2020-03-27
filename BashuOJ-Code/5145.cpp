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
const int MAXN=400005;
struct Pair{int u,depth;};
struct Edge{int is_sc,u,v;};
vector<int>a[MAXN];
Edge b[MAXN];
int n,m,p,fa[MAXN],prt[MAXN],dep[MAXN],Cnt[MAXN];
inline const int GetInt()
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
	else return prt[u]=getfa(prt[u]);
}
inline void AddEdge(int u,int v)
{
	a[u].push_back(v);
	a[v].push_back(u);
}
inline int onion(int a,int b)
{
	a=getfa(a),b=getfa(b);
	if(dep[a]<dep[b])swap(a,b);
	if(a==b)return a;
	prt[a]=onion(fa[a],b);
	Cnt[prt[a]]+=Cnt[a];
	Cnt[a]=0;
	return prt[a];
}
void DFS(int u,int father,int depth)
{
	dep[u]=depth,fa[u]=father;
	vector<int>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(*it==father)continue;
		DFS(*it,u,depth+1);
	}
}
int main()
{
	//freopen("t.in","r",stdin);
	//freopen("t.out","w",stdout);
	n=GetInt(),m=GetInt(),p=GetInt();
	for(ri i=1;i<=n;i++)prt[i]=i,Cnt[i]=1;
	for(ri i=1;i<=m+p;i++)
	{
		int u=GetInt(),v=GetInt();
		int f1=getfa(u),f2=getfa(v);
		if(f1!=f2)
		{
			b[i]=(Edge){1,u,v};
			prt[f1]=f2,AddEdge(u,v);
		}
		else b[i]=(Edge){0,u,v};
	}
	for(ri i=1;i<=n;i++)
	{
		prt[i]=i;
		if(!dep[i])DFS(i,0,1);
	}
	for(ri i=1;i<=m;i++)
		if(!b[i].is_sc)onion(b[i].u,b[i].v);
	for(ri i=m+1;i<=m+p;i++)
	{
		if(b[i].is_sc)printf("No\n");
		else printf("%d\n",Cnt[onion(b[i].u,b[i].v)]);
	} 
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}


