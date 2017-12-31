#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
using namespace std;
vector<int>a[16005];
int n,b[16005],lef[16005],ans=-0x7fffffff,Get;
//以节点为阶段 
//DEMO
inline int getint()
{
	int num=0,bj=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')bj=(ch=='-'||bj==-1)?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9')num=num*10+ch-'0',ch=getchar();
	return num*bj;
}
void DFS(int u,int fa)
{
	vector<int>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(*it==fa)continue;
		DFS(*it,u);
		if(lef[*it]>0)lef[u]+=lef[*it];
	}
}
int main()
{
	n=getint();
	for(int i=1;i<=n;i++)b[i]=getint();
	for(int i=1;i<=n-1;i++)
	{
		int x=getint(),y=getint();
		a[x].push_back(y);
		a[y].push_back(x);
	}
	memcpy(lef,b,sizeof(b));
	DFS(1,0);
	for(int i=1;i<=n;i++)ans=max(ans,lef[i]);
	printf("%d",ans);
	return 0;
}