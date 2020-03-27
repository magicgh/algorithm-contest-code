#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<climits>
using namespace std;
int map[105][105],f[105][105],n,q;
struct node
{
	int lch,rch,value;
}tree[105];
inline void BuildTree(int v)
{
	for(int i=1;i<=n;i++)
	{
		if(map[v][i]!=-1)
		{
			tree[v].lch=i;
			tree[i].value=map[v][i];
			map[v][i]=map[i][v]=-1;
			BuildTree(i);
			break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(map[v][i]!=-1)
		{
			tree[v].rch=i;
			tree[i].value=map[v][i];
			map[v][i]=map[i][v]=-1;
			BuildTree(i);
			break;
		}
	}
	return;
}
inline int DP(int i,int j)
{
	if(j==0)return 0;
	if(tree[i].lch==0&&tree[i].rch==0)return tree[i].value;
	if(f[i][j])return f[i][j];
	for(int k=0;k<=j-1;k++)
	f[i][j]=max(f[i][j],DP(tree[i].lch,k)+DP(tree[i].rch,j-k-1)+tree[i].value);
	return f[i][j];
}
int main(){
	int x,y,z;
	memset(map,-1,sizeof(map));
	memset(tree,0,sizeof(tree));
	memset(f,0,sizeof(f));
	scanf("%d%d",&n,&q);
	q++;
	for(int i=1;i<n;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		map[x][y]=map[y][x]=z;
	}
	BuildTree(1);
	printf("%d",DP(1,q));
	return 0;
}
