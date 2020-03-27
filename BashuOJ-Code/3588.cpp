#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<list>
#include<map>
using namespace std;
const int M=905;
struct node
{
	int prt;
	bool vst,used;
}tree[M];
int n,m;
list<int>a[M];
list<int>b[M];
map<int,int>ans;
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
	list<int>::iterator j;
	for(i=a[x].begin();i!=a[x].end();++i)
	if(!tree[*i].vst)Tarjan(*i),tree[*i].prt=x;
	tree[x].used=1;
	for(j=b[x].begin();j!=b[x].end();++j)
	if(tree[*j].used)ans[GetFather(*j)]++;
}
int main(){
	while(scanf("%d",&n)!=EOF)
	{
	ans.clear();
	for(int i=1;i<=n;i++)a[i].clear(),b[i].clear();
	int x,k,y,root=1;
	memset(tree,0,sizeof(tree));
	for(int i=1;i<=n;i++)
	{
		scanf("%d:(%d)",&x,&k);
		for(int j=1;j<=k;j++)
		{
		scanf("%d",&y);
		a[x].push_back(y);
		tree[y].prt=x;
		//cout<<y<<"->"<<tree[y].prt<<endl;
		}
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("\n(%d,%d)",&x,&y);
		b[x].push_back(y);
		b[y].push_back(x);
	}
	while(tree[root].prt!=0)root=tree[root].prt;//while!!!
	//cout<<root<<endl;
	Tarjan(root);
	map<int,int>::iterator it;
	for(it=ans.begin();it!=ans.end();++it)printf("%d%c%d\n",it->first,':',it->second);
	}
	return 0;
}