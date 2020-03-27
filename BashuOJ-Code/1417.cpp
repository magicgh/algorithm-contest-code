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
int a[255][255],x[255];
int n;
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline void Gauss(int x)
{
	int Maxid=x;
	for(ri i=x;i<=n;i++)
		if(a[i][x]){Maxid=i;break;}
	if(Maxid<=n)
	{
		for(ri i=1;i<=n+1;i++)
			swap(a[x][i],a[Maxid][i]);
		for(ri i=x+1;i<=n;i++)
		{
			if(a[i][x])
				for(ri j=1;j<=n+1;j++)
					a[i][j]^=a[x][j];
		}
	}
}
bool Solve()
{
	for(ri i=1;i<=n;i++)Gauss(i);
	for(ri i=n;i>=1;i--)
	{
		if(a[i][i]==0&&a[i][n+1])return 0;
		if(a[i][i]==1)x[i]=a[i][n+1];
		else x[i]=0;
		for(ri j=i;j<=n;j++)
			a[i-1][n+1]^=a[i-1][j]*x[j];
	}
	return 1;
}
void Output()
{
	for(ri i=1;i<=n;i++)
		if(x[i])printf("%d ",i);
}
int main()
{
	n=getint();
	for(ri i=1;i<=n;i++)
	{
		int x;
		while(x=getint())
		{
			if(x==-1)break;
			a[x][i]=1;//增广矩阵 
		}
		a[i][n+1]=1;//系数矩阵 
	}
	if(!Solve())printf("No solution\n");
	else Output();
	return 0;
}

