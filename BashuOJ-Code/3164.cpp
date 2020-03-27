#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define ri register int
using namespace std;
const int MAXN=2000005;
int n,m;
int v[MAXN],dist[MAXN],ch[MAXN][2],prt[MAXN];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline int getfa(int &x){return prt[x]==x?x:prt[x]=getfa(prt[x]);}
inline int merge(int x,int y)
{
	if(x*y==0)return x+y;
	if(v[x]<v[y])swap(x,y);
	ch[x][1]=merge(ch[x][1],y);
	if(dist[ch[x][1]]>dist[ch[x][0]])swap(ch[x][0],ch[x][1]);
	dist[x]=ch[x][1]?dist[ch[x][1]]+1:0;
	return x;
}
inline int del(int x)
{
	v[x]>>=1;
	int y=merge(ch[x][0],ch[x][1]);
	ch[x][0]=ch[x][1]=dist[x]=0;
	return y;
}
int main()
{
	n=getint();
	for(ri i=1;i<=n;i++)v[prt[i]=i]=getint();
	m=getint();
	for(ri i=1;i<=m;i++)
	{
		int x=getint(),y=getint();
		x=getfa(x),y=getfa(y);
		if(x==y){printf("%d\n",-1);continue;}
		int f1=del(x),f2=del(y),total=merge(f1,f2);
		total=merge(total,x),total=merge(total,y);
		prt[total]=prt[x]=prt[y]=total;
		printf("%d\n",v[total]);
	}
	return 0;
}

