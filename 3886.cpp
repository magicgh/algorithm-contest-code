#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<stack>
#include<vector>
#define ri register int
#define ll long long
using namespace std;
const int MAXN=10005;
const int INF=0x7fffffff/2;
struct node{int to,val;};
vector<node>a[MAXN];
int n,m,dist[MAXN];
bool bj,vst[MAXN];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void SPFA(int u)
{
	vst[u]=1;
	vector<node>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(dist[it->to]>dist[u]+it->val)
		{
			if(vst[it->to]){bj=1;return;}
			dist[it->to]=dist[u]+it->val;
			SPFA(it->to);
		}
	}
	vst[u]=0;
}
int main()
{
	n=getint(),m=getint();
	for(ri i=1;i<=m;i++)
	{
		int op=getint();
		if(op==1)
		{
			int x=getint(),y=getint(),z=getint();
			a[x].push_back((node){y,-z});
		}
		if(op==2)
		{
			int x=getint(),y=getint(),z=getint();
			a[y].push_back((node){x,z});
		}
		if(op==3)
		{
			int x=getint(),y=getint();
			a[x].push_back((node){y,0});
			a[y].push_back((node){x,0});
		}
	}	
	for(ri i=1;i<=n;i++)dist[i]=INF;
	for(ri i=1;i<=n;i++)
	{
		SPFA(i);
		if(bj){printf("No\n");return 0;}
	}
	printf("Yes\n");
	return 0;
}

