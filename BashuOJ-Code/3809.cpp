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
const int INF=0x7fffffff/2;
struct node{int x,y,z;};
struct edge{int to,val;};
node a[205];
vector<edge>b[20];
int n,m,val[20],prt[20];
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline bool cmp(const node &a,const node &b){return a.z<b.z;}
inline int getfa(int u)
{
	if(prt[u]==u)return u;
	return prt[u]=getfa(prt[u]);
}
void Kruskal()
{
	int tot=0,Ans=0;
	sort(a+1,a+m+1,cmp);
	for(ri i=1;i<=n;i++)prt[i]=i;
	for(ri i=1;i<=m;i++)
	{
		int f1=getfa(a[i].x),f2=getfa(a[i].y);
		if(f1!=f2)
		{
			prt[f1]=f2;
			Ans+=a[i].z;
			tot++;
		}
	}
	if(tot!=n-1)printf("Impossible\n");
	else printf("%d\n",Ans);
}
int main()
{
	n=getint(),m=getint();
	for(ri i=1;i<=n;i++)val[i]=getint();
	for(ri i=1;i<=m;i++)
	{
		int p=getint()+1,q=getint()+1,t=getint();
		a[i]=(node){p,q,t};
	}
	Kruskal();
	return 0;
}


