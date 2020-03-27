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
int l,n,c[205][205],q[1005],f[2][205][205],Ans=0x7fffffff;
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
int main()
{
	l=getint(),n=getint();
	for(ri i=1;i<=l;i++)
		for(ri j=1;j<=l;j++)c[i][j]=getint();
	for(ri i=1;i<=n;i++)q[i]=getint();
	int now=0,next;
	memset(f[now],0x3f3f3f,sizeof(f[now]));
	f[now][2][3]=f[now][3][2]=0,q[0]=1;
	for(ri t=1;t<=n;t++)
	{
		next=now^1;
		memset(f[next],0x3f3f3f,sizeof(f[next]));
		for(ri i=1;i<=l;i++)
			for(ri j=1;j<=l;j++)
			{
				int x=q[t],y=q[t-1];
				if(i==j||i==y||j==y)continue;
				f[next][i][j]=min(f[next][i][j],f[now][i][j]+c[y][x]);
				f[next][i][y]=min(f[next][i][y],f[now][i][j]+c[j][x]);
				f[next][j][y]=min(f[next][j][y],f[now][i][j]+c[i][x]);
			}
		now=next;
	}
	for(ri i=1;i<=l;i++)
		for(ri j=1;j<=l;j++)Ans=min(Ans,f[next][i][j]);
	printf("%d\n",Ans);
	return 0;
}

