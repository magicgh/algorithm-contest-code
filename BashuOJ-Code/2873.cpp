#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
struct node
{
	int lch,rch,data;
}
a[100005];
int n;
inline void Insert(int k,int root)
{
	if(a[k].data<=a[root].data)
	{
		if(a[root].lch==-1)a[root].lch=k;
		else Insert(k,a[root].lch);
	}
	if(a[k].data>a[root].data)
	{
		if(a[root].rch==-1)a[root].rch=k;
		else Insert(k,a[root].rch);
	}
	return;
}
inline void dfs(int root)
{
	printf("%d ",a[root].data);
	if(a[root].lch!=-1)dfs(a[root].lch);
	if(a[root].rch!=-1)dfs(a[root].rch);
	return;
}
int main(){
	scanf("%d%d",&a[0].data,&n);
	for(int i=0;i<=n;i++)a[i].lch=a[i].rch=-1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].data);
		Insert(i,0);
	}
	dfs(0);
	return 0;
}
