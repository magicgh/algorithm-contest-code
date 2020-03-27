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
const int MAXN=1005;
struct path{int x,y,z;};
path a[MAXN*MAXN]; 
int map[MAXN][MAXN],prt[MAXN];
int n,k,cnt,t; 
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline bool cmp(const path &a,const path &b){return a.z<b.z;}
inline int getfa(int u)
{
	if(prt[u]==u)return u;
	return prt[u]=getfa(prt[u]);
}
void Kruskal()
{
	for(ri i=1;i<=n;i++)prt[i]=i;
	for(ri i=1;i<=cnt;i++)
	{
		int f1=getfa(a[i].x),f2=getfa(a[i].y);
		if(f1!=f2)
		{
			prt[f2]=f1;
			if(++t==n-k+1){printf("%d",a[i].z);break;}
		}
	}
}
int main()
{
	n=getint(),k=getint();
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=n;j++)
			map[i][j]=getint();
	for(ri i=1;i<n;i++)
		for(ri j=i+1;j<=n;j++)
			a[++cnt]=(path){i,j,map[i][j]};
	sort(a+1,a+cnt+1,cmp);
	Kruskal();
	return 0;	
}

