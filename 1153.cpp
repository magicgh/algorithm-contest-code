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
const int MAXN=1000005;
struct node{int x,y;};
node Edge[MAXN];
int n,m,q,cnt;
int Order[MAXN],prt[MAXN];
bool Hash[500005];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline int getfa(int u)
{
	if(prt[u]==u)return u;
	else return prt[u]=getfa(prt[u]);
}
int main()
{
	n=getint(),m=getint(),q=getint();
	for(ri i=1;i<=n;i++)prt[i]=i;
	for(ri i=1;i<=m;i++)
	{
		int u=getint(),v=getint();
		Edge[i]=(node){u,v};
		int f1=getfa(u),f2=getfa(v);
		if(f1!=f2)prt[f1]=f2;
	}
	for(ri i=1;i<=q;i++)
	{
		Order[i]=getint();
		Hash[Order[i]]=1;
	}
	for(ri i=1;i<=n;i++)if(prt[i]==i)cnt++;
	if(cnt!=1){printf("0\n");return 0;}
	for(ri i=1;i<=n;i++)prt[i]=i;
	for(ri i=1;i<=m;i++)
	{
		if(Hash[i])continue;
		int f1=getfa(Edge[i].x),f2=getfa(Edge[i].y);
		if(f1!=f2)prt[f1]=f2;
	}
	cnt=0;
	for(ri i=1;i<=n;i++)if(prt[i]==i)cnt++;
	if(cnt==1){printf("%d\n",q+1);return 0;}
	for(ri i=q;i>=1;i--)
	{
		int f1=getfa(Edge[Order[i]].x),f2=getfa(Edge[Order[i]].y);
		if(f1!=f2)prt[f1]=f2,cnt--;
		if(cnt==1){printf("%d\n",i);return 0;}
	}
	return 0;
}
