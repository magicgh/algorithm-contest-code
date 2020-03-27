#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int n,m,f[305][305];
struct node
{
	int lch,rch,son,value;
}tree[305];
inline int DP(int i,int j)
{
	if(i==0||j==0)return 0;
	if(f[i][j])return f[i][j];
	if(tree[i].rch)f[i][j]=DP(tree[i].rch,j);
	for(int k=0;k<j;k++)f[i][j]=max(f[i][j],DP(tree[i].lch,k)+DP(tree[i].rch,j-k-1)+tree[i].value);
	return f[i][j];
}
int main(){
	scanf("%d%d",&n,&m);
	memset(tree,0,sizeof(tree));
	memset(f,0,sizeof(f));
	int x,y;
	for(int i=1;i<=n;i++)
	{
	scanf("%d%d",&x,&y);
	tree[i].value=y;
	if(!tree[x].son)tree[x].lch=i;
	else tree[tree[x].son].rch=i;
	tree[x].son=i;
	}
	printf("%d",DP(tree[0].lch,m));
	return 0;
}
