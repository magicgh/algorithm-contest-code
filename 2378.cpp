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
struct Matrix
{
	int a[105][105];
	Matrix()
	{
		memset(a,0,sizeof(a));
	}
};
Matrix g,ret;
int n,t;
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline Matrix Matrix_Multi(Matrix m1,Matrix m2)
{
	Matrix ans;
	for(ri i=1;i<=n*9;i++)
		for(ri j=1;j<=n*9;j++)
			for(ri k=1;k<=n*9;k++)ans.a[i][j]=(ans.a[i][j]+m1.a[i][k]*m2.a[k][j])%2009;
	return ans;
}
void Matrix_Pow()
{
	while(t)
	{
		if(t&1)ret=Matrix_Multi(ret,g);
		g=Matrix_Multi(g,g);
		t>>=1;
	}
	printf("%d",ret.a[1][(n-1)*9+1]);
}
int main()
{
	n=getint(),t=getint();
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=8;j++)
			g.a[(i-1)*9+j][(i-1)*9+j+1]=1;
	char ch;
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=n;j++)
		{
			while(ch=getchar())if(isdigit(ch))break;
			int val=ch-'0';
			if(val)g.a[(i-1)*9+val][(j-1)*9+1]=1;
		}
	for(ri i=1;i<=100;i++)ret.a[i][i]=1;
	Matrix_Pow();
	return 0;
}

