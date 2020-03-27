#include<bits/stdc++.h>
using namespace std;
int n,t,head[10005]={0},temp[10005]={0},cnt=0;
struct Star
{
	int next,to;
}a[20005];
struct node
{
	int prt,lst,ler,u,List;
}tree[20005];
inline void AddEdge(int x,int y)
{
	a[++cnt].to=y;
	a[cnt].next=head[x];
	head[x]=cnt;
}
inline void DP1(int x)
{
	for(int i=head[x];i;i=a[i].next)
	{
		int y=a[i].to;
		if(y!=tree[x].prt)
		{
			tree[y].prt=x;
			DP1(y);
			if(tree[y].lst+1>tree[x].lst)
			{
				tree[x].ler=tree[x].lst;
				tree[x].lst=tree[y].lst+1;
				tree[x].List=y;
			}
			else if(tree[y].lst+1>tree[x].ler)tree[x].ler=tree[y].lst+1;
		}
		}
		return;
}
inline void DP2(int x)
{
	if(tree[x].prt)
	{
	
		if(tree[tree[x].prt].List==x)tree[x].u=max(tree[tree[x].prt].u,tree[tree[x].prt].ler)+1;
		else tree[x].u=max(tree[tree[x].prt].u,tree[tree[x].prt].lst)+1;
		}
	for(int i=head[x];i;i=a[i].next)if(tree[x].prt!=a[i].to)DP2(a[i].to);
	return;
}
int main(){
	cin>>n;
	memset(a,0,sizeof(a));
	memset(tree,0,sizeof(tree));
	for(int i=2;i<=n;i++)
	{
		cin>>t;
		AddEdge(t,i);
	}
	DP1(1);
	DP2(1);
	int Min=INT_MAX;
	for(int i=1;i<=n;i++)
	{
	temp[i]=max(tree[i].lst,max(tree[i].u,tree[i].lst));
	Min=min(Min,temp[i]);
}
    for(int i=1;i<=n;i++)if(Min==temp[i])cout<<i<<' ';
	return 0;
}
