#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#include<iomanip>
#include<queue>
#include<vector>
#define ri register int
using namespace std;
const int MAXN=1000005;
vector<int>a[MAXN];
int n,ret,Ans,Node,dep[MAXN],Size[MAXN];
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
void Tree_DPx1(int u,int fa,int depth)
{
	dep[u]=depth,Size[u]=1;
	vector<int>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(*it==fa)continue;
		Tree_DPx1(*it,u,depth+1);
		Size[u]+=Size[*it];
	}
}
void Tree_DPx2(int u,int fa,int sum)
{
	vector<int>::iterator it;
	if(Ans<sum||(Ans==sum&&Node>u))Ans=sum,Node=u;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(*it==fa)continue;
		Tree_DPx2(*it,u,sum+n-2*Size[*it]);
	}
}
int main()
{

	n=GetInt();
	for(ri i=1;i<n;i++)
	{
		int u=GetInt(),v=GetInt();
		a[u].push_back(v);
		a[v].push_back(u);
	}
	Tree_DPx1(1,0,0);
	for(ri i=1;i<=n;i++)ret+=dep[i];
	Tree_DPx2(1,0,ret);
	printf("%d\n",Node);
	return 0;
}
