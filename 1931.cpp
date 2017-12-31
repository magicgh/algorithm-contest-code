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
const int INF=0x7fffffff/2;
const int MAXN=1005;
struct node{int x,y,z;};
node a[MAXN*MAXN*4];
int prt[MAXN*MAXN];
int n,m,cnt,Count,Ans,dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
inline bool cmp(const node &a,const node &b){return a.z<b.z;}
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline int getfa(int u)
{
	if(prt[u]==u)return u;
	return prt[u]=getfa(prt[u]);
}
void Kruskal()
{
	for(ri i=1;i<=cnt;i++)
	{
		int f1=getfa(a[i].x),f2=getfa(a[i].y);
		if(f1!=f2)
		{
			prt[f1]=f2;
			Ans+=a[i].z;
			if(++Count>=n*m-1)break;
		}
	}
}
int main()
{
	m=getint(),n=getint();
	for(ri i=1;i<=m*n;i++)prt[i]=i;
	int ax,ay,bx,by;
	while(~scanf("%d%d%d%d",&ax,&ay,&bx,&by))
		a[++cnt]=(node){(ax-1)*n+ay,(bx-1)*n+by,0};
	for(ri i=1;i<=m;i++)
		for(ri j=1;j<=n;j++)
			for(ri k=0;k<4;k++)
			{
				int x=i+dx[k],y=j+dy[k];
				if(x>=1&&x<=m&&y>=1&&y<=n)
				{
					if(i==x)a[++cnt]=(node){(i-1)*n+j,(x-1)*n+y,2};
					if(j==y)a[++cnt]=(node){(i-1)*n+j,(x-1)*n+y,1};
				}
			}
	sort(a+1,a+cnt+1,cmp);
	Kruskal();
	printf("%d",Ans);
	return 0;
}

