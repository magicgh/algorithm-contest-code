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
const int MAXN=10005;
const int INF=0x7fffffff/2; 
int n,m,k;
int x[MAXN],y[MAXN],down[MAXN],up[MAXN],f[MAXN][1005];
namespace FastIO
{
    const ll L=1<<15;
    char buffer[L],*S,*T;
    inline char getchar()
	{
        if(S==T){T=(S=buffer)+fread(buffer,1,L,stdin);if(S==T)return EOF;}
		return *S++;
    }
    inline const int getint()
	{
		ri num=0,bj=1;
		register char c=getchar();
		while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
		while(isdigit(c))num=num*10+c-'0',c=getchar();
		return num*bj;
	}
}using FastIO::getint;
int main()
{
	n=getint(),m=getint(),k=getint();
	for(ri i=1;i<=n;i++)
		x[i]=getint(),y[i]=getint();
	for(ri i=0;i<=n;i++)
		down[i]=0,up[i]=m+1;
	for(ri i=1;i<=k;i++)
	{
		int p=getint(),l=getint(),h=getint();
		down[p]=l,up[p]=h;
	}
	for(ri i=1;i<=n;i++)
		for(ri j=0;j<=m;j++)f[i][j]=INF;
	f[0][0]=INF;
	for(ri i=1;i<=n;i++)
	{
		for(ri j=1;j<=m;j++)
		{
			if(j>=x[i])
				f[i][j]=min(f[i][j],min(f[i-1][j-x[i]]+1,f[i][j-x[i]]+1));
			if(j==m)
			{
				for(ri k=j-x[i];k<=m;k++)
					f[i][j]=min(f[i][j],min(f[i-1][k]+1,f[i][k]+1));
			}
		}
		for(ri j=down[i]+1;j<=up[i]-1;j++)
			if(j+y[i]<=m)
				f[i][j]=min(f[i][j],f[i-1][j+y[i]]);
		for(ri j=1;j<=down[i];j++)f[i][j]=INF;
		for(ri j=up[i];j<=m;j++)f[i][j]=INF;
	}
	int Max=k,Min=INF;
	for(ri i=n;i>=1;i--)
	{
		for(ri j=down[i]+1;j<=up[i]-1;j++)
			if(f[i][j]!=INF)Min=min(Min,f[i][j]);
		if(Min!=INF)break;
		else if(up[i]!=m+1)Max--;
	}
	if(Max==k)printf("1\n%d\n",Min);
	else printf("0\n%d\n",Max);
	return 0;
}


