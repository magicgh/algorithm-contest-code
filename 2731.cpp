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
const int MAXN=1e6+5;
int n,m,k,cnt,dfn[MAXN];
struct point{int x,y;};
struct node{int x,y;double z;};
point b[MAXN];
node a[MAXN];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline double Cross(const point &a,const point &b)
{
	return sqrt((double)(a.x-b.x)*(double)(a.x-b.x)+(double)(a.y-b.y)*(double)(a.y-b.y));
}
inline bool cmp(const node &a,const node &b)
{
	return a.z<b.z;
}
inline int DFS(int u)
{
	if(dfn[u]==u)return u;
	return dfn[u]=DFS(dfn[u]);
}
void Tarjan()
{
	for(ri i=1;i<=n;i++)dfn[i]=i;
	for(ri i=1;i<=cnt;i++)
	{
		int f1=DFS(a[i].x),f2=DFS(a[i].y);
		if(f1!=f2)
		{
			dfn[f2]=f1;
			if(--k<m){printf("%.2lf",a[i].z);break;} 
		}
	}
}
int main()
{
	k=n=getint(),m=getint();
	for(ri i=1;i<=n;i++)
	{
		int x=getint(),y=getint();
		b[i]=(point){x,y};
	}
	for(ri i=1;i<n;i++)
		for(ri j=i+1;j<=n;j++)
			a[++cnt]=(node){i,j,Cross(b[i],b[j])};
	sort(a+1,a+cnt+1,cmp);
	Tarjan();
	return 0;
}

