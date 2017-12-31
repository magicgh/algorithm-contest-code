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
int Deg[MAXN],cnt,n;
bool vst[MAXN];	
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void DFS(int u,int fa)
{
	vector<int>::iterator it;
	vst[u]=1;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(vst[*it])continue;
		DFS(*it,u);
	}
	if(Deg[u]>2)
	{
		cnt+=(Deg[u]-2);
		Deg[fa]--;
	}
}
int main()
{
	n=getint();
	for(ri i=1;i<n;i++)
	{
		int u=getint(),v=getint();
		a[u].push_back(v);
		a[v].push_back(u);
		Deg[u]++,Deg[v]++;
	}
	DFS(1,0);
	printf("%d",n-cnt-1);
	return 0;
}

