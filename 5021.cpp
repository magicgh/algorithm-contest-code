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
const int MAXN=200005;
struct node{int id,x,y,nx,ny;};
int n,m;
node a[MAXN],b[MAXN];
int hx[MAXN],hy[MAXN];
inline bool cmpx(const node &a,const node &b){return (a.x==b.x&&a.y>b.y)||(a.x<b.x);} 
inline bool cmpy(const node &a,const node &b){return (a.y==b.y&&a.x>b.x)||(a.y<b.y);} 
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline void AddEdgex(int x,int num){a[num].nx=hx[x],hx[x]=num;}
inline void AddEdgey(int y,int num){a[num].ny=hy[y],hy[y]=num;}
void DFS(int now,int Type)
{
	if(Type==0)
	{
		if(!a[now].nx){printf("%d %d\n",a[now].x,a[now].y);return;}
		else DFS(a[now].nx,Type^1);
	}
	else if(Type==1)
	{
		if(!a[now].ny){printf("%d %d\n",a[now].x,a[now].y);return;}
		else DFS(a[now].ny,Type^1);
	}
}
int main()
{
	n=getint();
	for(ri i=1;i<=n;i++)
	{
		int x=getint(),y=getint();
		a[i]=b[i]=(node){i,x,y,0,0};
	}
	sort(b+1,b+n+1,cmpx);
	for(ri i=1;i<=n;i++)
		AddEdgex(b[i].x,b[i].id);
	sort(b+1,b+n+1,cmpy);
	for(ri i=1;i<=n;i++)
		AddEdgey(b[i].y,b[i].id);
	m=getint();
	for(ri i=1;i<=m;i++)
	{
		int y0=getint();
		if(!hy[y0]){printf("unable to address\n");continue;}
		else DFS(hy[y0],0);
	}
	return 0;
}