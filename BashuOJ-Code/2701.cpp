#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<list>
#include<map>
using namespace std;
const int M=50005;
struct node
{
	int prt,deep;
	bool vst,used;
}tree[M];
struct beta
{
	int num,to;
};
int n,m,p=0;
list<int>a[M];
list<beta>b[M];
map<int,int>ans;
inline void DFS(int x,int k)
{
	tree[x].deep=k;
	list<int>::iterator i;
	for(i=a[x].begin();i!=a[x].end();++i)DFS(*i,k+1);
}
inline int GetFather(int u)
{
	if(tree[u].prt==u)return u;
	tree[u].prt=GetFather(tree[u].prt);
	return tree[u].prt;
}
inline void Tarjan(int x)
{
	tree[x].prt=x;
	tree[x].vst=1;
	list<int>::iterator i;
	list<beta>::iterator j;
	for(i=a[x].begin();i!=a[x].end();++i)
	if(!tree[*i].vst)
	{
	Tarjan(*i);
	tree[*i].prt=x,tree;
	}
	tree[x].used=1;
	for(j=b[x].begin();j!=b[x].end();++j)
	if(tree[j->to].used)ans[j->num]=GetFather(j->to);
}
int main(){
    scanf("%d",&n);
	ans.clear();
	for(int i=1;i<=n;i++)a[i].clear(),b[i].clear();
	int x,y,root=1;
	memset(tree,0,sizeof(tree));
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		for(int j=1;j<=x;j++)
		{
		scanf("%d",&y);
		a[i].push_back(y);
		tree[y].prt=i;
		//cout<<y<<"->"<<tree[y].prt<<endl;
		}
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("\n%d%d",&x,&y);
		b[x].push_back({i,y});
		b[y].push_back({i,x});
	}
	while(tree[root].prt!=0)root=tree[root].prt;//while!!!
	DFS(root,1);
	//for(int i=1;i<=n;i++)if(tree[i].deep)cout<<tree[i].deep<<':'<<i<<endl;
	Tarjan(root);
	for(int i=1;i<=m;i++)printf("%d\n",tree[ans[i]].deep);
	return 0;
}