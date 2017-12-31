#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<vector>
#define ri register int
using namespace std;
const int MAXN=55;
int n,k,prt[MAXN],cnt,Max=-0x7fffffff;
struct node{int x,y,z;};
struct point{int x,y;};
point p[MAXN];
node a[MAXN*MAXN];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline int dist(const point &a,const point &b){return abs(a.x-b.x)+abs(a.y-b.y);}
inline bool cmp(const node &a,const node &b){return a.z<b.z;}
inline int getfa(int x)
{
	if(prt[x]==x)return x;
	return prt[x]=getfa(prt[x]);
}
void kruskal()
{
	for(ri i=1;i<=cnt;i++)
	{
		int f1=getfa(a[i].x),f2=getfa(a[i].y);
		if(f1!=f2)
		{
			prt[f2]=f1;
			Max=max(Max,a[i].z);
			if(++k==n-1)break;
		}
	}
}
int main()
{
	n=getint();
	for(ri i=1;i<=n;i++)
	{
		int x=getint(),y=getint();
		p[i]=(point){x,y};
	}
	for(ri i=1;i<=n;i++)prt[i]=i;
	for(ri i=1;i<n;i++)
		for(ri j=i+1;j<=n;j++)
		if(i!=j)a[++cnt]=(node){i,j,dist(p[i],p[j])};
	sort(a+1,a+cnt+1,cmp);
	kruskal();
	printf("%d",(Max+1)/2);
	return 0;
}
