#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<list>
using namespace std;
const int M=2005;
struct node
{
	int prt;
	bool vst,used;
}tree[M];
struct alpha
{
	int to,num;
};
list<int>a[M];
list<alpha>b[M];
int ans[M],n,m,cnta=0,cntb=0;
inline void AddEdge(int x,int y,bool k,int num=0)
{
	if(k==0)a[x].push_back(y);
	if(k==1)b[x].push_back({y,num});
	return;
}
inline int GetFather(int x)
{
	if(tree[x].prt==x)return x;
	tree[x].prt=GetFather(tree[x].prt);
	return tree[x].prt;
}
inline void Tarjan(int root)
{
	tree[root].vst=1;
	tree[root].prt=root;
	list<int>::iterator iter_a;
	list<alpha>::iterator iter_b;
	for(iter_a=a[root].begin();iter_a!=a[root].end();++iter_a)
	if(!tree[*iter_a].vst)Tarjan(*iter_a),tree[*iter_a].prt=root;
	tree[root].used=1;
	for(iter_b=b[root].begin();iter_b!=b[root].end();++iter_b)
	if(tree[iter_b->to].used)ans[iter_b->num]=GetFather(iter_b->to);
}
int main(){
	int x,y,root;
	memset(tree,0,sizeof(tree));
	scanf("%d%d",&n,&m);
	for(int i=2;i<=n;i++)
	{
	scanf("%d",&x);
	AddEdge(x,i,0);
	tree[i].prt=x;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		AddEdge(x,y,1,i);
		AddEdge(y,x,1,i);
	}
	root=1;
	while(tree[root].prt!=0)root=tree[root].prt;
	Tarjan(root);
	for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
	return 0;
}