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
const int MAXN=2005;
const int INF=0x7fffffff;
int n,m;
int a[MAXN][MAXN],l[MAXN][MAXN],r[MAXN][MAXN],h[MAXN][MAXN];
int Ans1=-INF,Ans2=-INF;
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
int main()
{
	n=getint(),m=getint();
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=m;j++)a[i][j]=getint();
	for(ri i=1;i<=n;i++)
	{
		l[i][1]=0;
		for(ri j=2;j<=m;j++)
		{
			if(a[i][j]!=a[i][j-1])
				l[i][j]=l[i][j-1];
			else l[i][j]=j-1;
		}
		r[i][m]=m+1;
		for(ri j=m-1;j>=1;j--)
		{
			if(a[i][j]!=a[i][j+1])
				r[i][j]=r[i][j+1];
			else r[i][j]=j+1;
		}
	}
	for(ri i=1;i<=m;i++)h[1][i]=1;
	for(ri i=2;i<=n;i++)
	{
		for(ri j=1;j<=m;j++)
		{
			if(a[i][j]==a[i-1][j])h[i][j]=1;
			else 
			{
				h[i][j]=h[i-1][j]+1;
				l[i][j]=max(l[i][j],l[i-1][j]);
				r[i][j]=min(r[i][j],r[i-1][j]);
			}
		}
	}
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=m;j++)
		{
			int x=min(h[i][j],(r[i][j]-l[i][j]-1));
			if(x>0)Ans1=max(Ans1,x*x);
			Ans2=max(Ans2,h[i][j]*(r[i][j]-l[i][j]-1));
		}
		printf("%d\n%d\n",Ans1,Ans2);
	return 0;
}


