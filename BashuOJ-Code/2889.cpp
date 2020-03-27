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
const int MAXN=5005;
const int INF=0x7fffffff/2;
struct path{int x,y,z;};
path a[MAXN];
int n,m,prt[505];
inline bool cmp(const path &a,const path &b){return a.z<b.z;}
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{ 
		if(c==EOF)return EOF;
		bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	} 
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline int getfa(int u)
{
	if(prt[u]==u)return u;
	return prt[u]=getfa(prt[u]);
}
void kruskal()
{
	int Ans=INF;
	for(ri i=1;i<=m;i++)
	{
		int Min=INF,Max=-INF,k=0;
		for(ri j=1;j<=n;j++)prt[j]=j;
		for(ri j=i;j<=m;j++)
		{
			int f1=getfa(a[j].x),f2=getfa(a[j].y);
			if(f1!=f2)Max=max(Max,a[j].z),Min=min(Min,a[j].z),prt[f1]=f2,k++;
		}
		if(k==n-1)Ans=min(Ans,Max-Min);
	}
	printf("%d\n",Ans==INF?-1:Ans);
}
int main()
{
	while(true)
	{
		n=getint(),m=getint();
		if(n==0&&m==0)break;
		for(ri i=1;i<=m;i++)
		{
			int x=getint(),y=getint(),z=getint();
			a[i]=(path){x,y,z};
		}
		sort(a+1,a+m+1,cmp);
		kruskal();
	}
	return 0;
}

