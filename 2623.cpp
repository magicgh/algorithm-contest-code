#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<vector>
using namespace std;
int n,bl,ml,delta[65];
bool f[65][1005];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+c-'0',c=getchar();
	return num*bj;
}
int main()
{
	n=getint(),bl=getint(),ml=getint();
	for(int i=2;i<=n;i++)delta[i]=getint();
	f[1][bl]=1;
	for(int i=2;i<=n;i++)
		for(int j=0;j<=ml;j++)
		{
			if(j+delta[i]<=ml)f[i][j]=f[i][j]|f[i-1][j+delta[i]];
			if(j-delta[i]>=0)f[i][j]=f[i][j]|f[i-1][j-delta[i]];
		}
	for(int i=ml;i>=0;i--)
		if(f[n][i]){printf("%d",i);return 0;}
	printf("-1");
	return 0;
}

