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
const int MAXN=1000005;
int v[MAXN],ch[MAXN][2],prt[MAXN];
bool dead[MAXN];
int n,m;
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline int merge(int &x,int &y)
{
	if(!x||!y)return x+y;
	if(v[x]>v[y])swap(x,y);
	ch[x][1]=merge(ch[x][1],y);
	swap(ch[x][0],ch[x][1]);
	return x;
}
inline int getfa(int &x){return prt[x]==x?x:prt[x]=getfa(prt[x]);}
int main()
{
	n=getint();
	for(ri i=1;i<=n;i++)prt[i]=i,v[i]=getint();
	m=getint();
	for(ri i=1;i<=m;i++)
	{
		char c;
		while(c=getchar())if(c=='M'||c=='K')break;
		if(c=='M')
		{
			int x=getint(),y=getint();
			if(dead[x]||dead[y])continue;
			x=getfa(x),y=getfa(y);
			if(x==y)continue;
			prt[x]=prt[y]=merge(x,y);
		}
		if(c=='K')
		{
			int x=getint();
			if(dead[x]){printf("0\n");continue;}
			x=getfa(x);
			dead[x]=1;printf("%d\n",v[x]);
			prt[x]=merge(ch[x][0],ch[x][1]);
			prt[prt[x]]=prt[x];
		}
	}
	return 0;
}
