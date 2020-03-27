#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<vector>
#define ri register int
using namespace std;
struct graph{int x,y;double k;}edge[65025];
struct node{int x,y;}p[255];
int n,cnt,f[255],Ans;
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+c-'0',c=getchar();
	return num*bj;
}
inline bool cmp(const graph &a,const graph &b){return a.k<b.k;}
int main()
{
	n=getint();
	for(ri i=1;i<=n;i++)p[i]=(node){getint(),getint()};
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=n;j++)
		{
			if(i==j)continue;
			edge[++cnt]=(graph){i,j,atan2(p[j].y-p[i].y,p[j].x-p[i].x)};//atan2(y,x)
		}
	sort(edge+1,edge+cnt+1,cmp);
	for(ri i=1;i<=n;i++)
	{
		for(ri j=1;j<=n;j++)f[j]=-0x7fffffff;
		f[i]=0;
		for(ri j=1;j<=cnt;j++)f[edge[j].y]=max(f[edge[j].y],f[edge[j].x]+1);
		Ans=max(Ans,f[i]);
	}
	printf("%d",Ans);
	return 0;
}