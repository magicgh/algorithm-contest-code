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
const int MAXN=1005;
int n,m,Ans;
int h[MAXN][MAXN],l[MAXN][MAXN],r[MAXN][MAXN],map[MAXN][MAXN];	
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
	char ch;
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=m;j++)
		{
			while(ch=getchar())
				if(ch=='R'||ch=='F')break;
			if(ch=='F')map[i][j]=1;
			else map[i][j]=0;
		}
	for(ri i=1;i<=n;i++)
	{
		l[i][1]=0;
		for(ri j=2;j<=m;j++)
			if(map[i][j-1])l[i][j]=l[i][j-1];
			else l[i][j]=j-1;
		r[i][m]=m+1;
		for(ri j=m-1;j>=1;j--)
			if(map[i][j+1])r[i][j]=r[i][j+1];
			else r[i][j]=j+1;	
	}
	for(ri i=1;i<=m;i++)h[1][i]=1;
	for(ri i=2;i<=n;i++)
		for(ri j=1;j<=m;j++)
		{
			if(map[i-1][j])
			{
				h[i][j]=h[i-1][j]+1;
				l[i][j]=max(l[i-1][j],l[i][j]);
				r[i][j]=min(r[i-1][j],r[i][j]);
			}
			else h[i][j]=1;
		}
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=m;j++)
			if(map[i][j])Ans=max(Ans,h[i][j]*(r[i][j]-l[i][j]-1));
		printf("%d\n",Ans*3);
	return 0;
}

