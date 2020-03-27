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
const int MAXN=100005;
vector<int>a[MAXN];
int n,k,f[MAXN][25],value[MAXN];
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
void Tree_DP1(int u,int fa)
{
	for(ri i=0;i<=k;i++)f[u][i]=value[u];
	vector<int>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(*it==fa)continue;
		Tree_DP1(*it,u);
		for(ri j=1;j<=k;j++)
			f[u][j]+=f[*it][j-1];
	}
}
void Tree_DP2(int u,int fa)
{
	vector<int>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(*it==fa)continue;
		for(ri j=k;j>=1;j--)//顺着枚举,f[][j-2]在j之前会被修改 
		{
			f[*it][j]+=f[u][j-1];
			if(j>=2)f[*it][j]-=f[*it][j-2];//减去自己多加的 
		}
		Tree_DP2(*it,u);
	}	
}
int main()
{
	n=getint(),k=getint();
	for(ri i=1;i<n;i++)
	{
		int u=getint(),v=getint();
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for(ri i=1;i<=n;i++)value[i]=getint();
	Tree_DP1(1,0);
	Tree_DP2(1,0);
	for(ri i=1;i<=n;i++)
		printf("%d\n",f[i][k]);
	return 0;
}


