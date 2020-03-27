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
using namespace std;
int map[51][51],f[51][51][2505][2];
inline int max(const int &a,const int &b){return a>b?a:b;}
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
int n,m,t; 
int main()
{
	char ch;
	n=getint(),m=getint(),t=getint();
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=m;j++)
		{
			while(ch=getchar())if(ch=='1'||ch=='0')break;
			map[i][j]=ch-'0';
		}
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=m;j++)
			for(ri k=1;k<=t;k++)
			{
				if(j==1)
				{
					f[i][j][k][0]=f[i][j][k][1]=max(f[i-1][m][k-1][0],f[i-1][m][k-1][1]);
					f[i][j][k][map[i][j]]++;
					continue;
				}
				f[i][j][k][0]=max(f[i][j-1][k-1][1],f[i][j-1][k][0])+(map[i][j]==0);
				f[i][j][k][1]=max(f[i][j-1][k-1][0],f[i][j-1][k][1])+(map[i][j]==1);
			}
	printf("%d",max(f[n][m][t][0],f[n][m][t][1]));
	return 0;
}

