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
using namespace std;
int n,m,cnt; 
int prt[105],size[105];
bool Hash[105];
inline int getfa(int u)
{
	if(prt[u]==u)return u;
	return prt[u]=getfa(prt[u]);
}
inline void Union(int x,int y)
{
	int f1=getfa(x),f2=getfa(y);
	if(f1!=f2)
	{
		prt[f2]=f1;
		size[f1]+=size[f2];
	}
}
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
int main()
{
	n=getint(),m=getint();
	for(ri i=1;i<=n;i++)prt[i]=i,size[i]=1;
	for(ri i=1;i<=m;i++)
	{
		int x=getint(),y=getint();
		Union(x,y); 
	}
	int Max=-0x7fffffff,id=0;
	for(ri i=1;i<=n;i++)
	{
		int fa=getfa(i);
		Max=max(Max,size[fa]);
		Hash[fa]++;
	}
	for(ri i=1;i<=n;i++)if(Hash[i])cnt++;
	printf("%d ",cnt);
	printf("%d",Max);
	return 0;
}

