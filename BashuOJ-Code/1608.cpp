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
const int MAXN=50005;
int n,top;
struct Tree{int id,key,val;};
Tree a[MAXN];
int Key[MAXN],ch[MAXN][2],prt[MAXN];
int Stack[MAXN];
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline bool cmp(const Tree &a,const Tree &b){return a.key<b.key;}
int main()
{
	n=getint();
	for(ri i=1;i<=n;i++)
	{
		int x=getint(),y=getint();
		a[i]=(Tree){i,x,y};
		Key[i]=x;
	}
	sort(a+1,a+n+1,cmp);
	for(ri i=1;i<=n;i++)
	{
		int Ntop=top;
		while(Ntop&&a[Stack[Ntop]].val>a[i].val)Ntop--;//找到第一个小于a[i].val的value 
		if(Ntop)prt[a[i].id]=a[Stack[Ntop]].id;//栈不为空 
		if(Ntop<top)prt[a[Stack[Ntop+1]].id]=a[i].id;//维护后继 
		Stack[++Ntop]=i;
		top=Ntop;
	}
	for(ri i=1;i<=n;i++)
	{
		if(a[i].key>Key[prt[a[i].id]])ch[prt[a[i].id]][1]=a[i].id;
		else ch[prt[a[i].id]][0]=a[i].id;
	}
	printf("YES\n");
	for(ri i=1;i<=n;i++)
		printf("%d %d %d\n",prt[i],ch[i][0],ch[i][1]);
	return 0;
}


