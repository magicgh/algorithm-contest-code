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
const int MAXN=1005;
struct node{int to,val;};
vector<node>a[MAXN];
int n,q,Ans;
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
void DFS(int u,int fa,int dist,int Goal)
{
	vector<node>::iterator it;
	if(u==Goal){Ans=dist;return;}
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(it->to==fa)continue;
		DFS(it->to,u,dist+it->val,Goal);
	}
}
int main()
{
	n=getint(),q=getint();
	for(ri i=1;i<n;i++)
	{
		int u=getint(),v=getint(),w=getint();
		a[u].push_back((node){v,w});
		a[v].push_back((node){u,w});
	}
	for(ri i=1;i<=q;i++)
	{
		int u=getint(),v=getint();
		DFS(u,0,0,v);
		printf("%d\n",Ans);
	}
	return 0;
}

