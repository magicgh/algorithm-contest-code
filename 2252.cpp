#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define ri register int
using namespace std;
int n,a[505],w[505],f[505][505];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void DFS(int i,int j)
{
	if(f[i][j]==f[i+1][j-1]+a[i])
	{ 
		printf("%d ",i);
		if(i+1<=n)DFS(i+1,j-1);
	}
	else if(i+1<=n)DFS(i+1,j);

}

int main()
{
	n=getint();
	for(ri i=1;i<=n;i++)a[i]=getint(),w[i]=getint();
	for(ri i=0;i<=n+1;i++)
	for(ri j=0;j<=n+1;j++)f[i][j]=0x7fffffff/2;
	for(ri i=1;i<=n+1;i++)f[i][0]=0;
	for(ri i=n;i>=1;i--)
		for(ri j=1;j<=n-i+1;j++)
		{
			f[i][j]=f[i+1][j];//不放
			if(f[i+1][j-1]<=w[i])f[i][j]=min(f[i][j],f[i+1][j-1]+a[i]);
		}
	for(ri i=n;i>=1;i--)
		if(f[1][i]!=0x7fffffff/2)
		{
			printf("%d\n",i);
			DFS(1,i);
			break;
		}
	return 0;
}

