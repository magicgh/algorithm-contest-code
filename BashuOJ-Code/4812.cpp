#include<iostream>
#include<cstdio>
#include<cstring>
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
bool flag;
int n,m,ret,vst[MAXN],C[MAXN][3];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void DFS(int u,int col,int t)
{
	vst[u]=col;C[t][col]++;
	vector<int>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(!vst[*it])DFS(*it,3-col,t);
		else if(vst[*it]!=3-col){flag=1;return;}
	}
}
bool Color()
{
	for(ri i=1;i<=n;i++)
	{
		if(!vst[i])
		{
			DFS(i,1,i);
			if(flag)return 0;
		}
	}
	return 1;
}
int main()
{
	n=getint(),m=getint();
	for(ri i=1;i<=m;i++)
	{
		int x=getint(),y=getint();
		a[x].push_back(y);
		a[y].push_back(x);
	}
	if(Color())
	{
		for(ri i=1;i<=n;i++)ret+=max(C[i][1],C[i][2]);
		printf("%d\n",ret);
	}
	else printf("-1\n");
	return 0;
}
