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
string a,b,c; 
int f[101][101][101];
int g[101][101][101][3];
bool bj[10005];	
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void DFS(int l1,int l2,int l3)
{	
	if(!f[l1][l2][l3])return;
	DFS(g[l1][l2][l3][0],g[l1][l2][l3][1],g[l1][l2][l3][2]);
	if(!bj[f[l1][l2][l3]])cout<<a[l1],bj[f[l1][l2][l3]]=1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>a>>b>>c;
	int len1=a.length(),len2=b.length(),len3=c.length();
	a=" "+a;b=" "+b;c=" "+c;
	for(ri i=1;i<=len1;i++)
	for(ri j=1;j<=len2;j++)
	for(ri k=1;k<=len3;k++)
	{
		if(f[i][j][k]<f[i-1][j][k])
		{
			f[i][j][k]=f[i-1][j][k];
			g[i][j][k][0]=i-1;
			g[i][j][k][1]=j;
			g[i][j][k][2]=k;
		}
		if(f[i][j][k]<f[i][j-1][k])
		{
			f[i][j][k]=f[i][j-1][k];
			g[i][j][k][0]=i;
			g[i][j][k][1]=j-1;
			g[i][j][k][2]=k;
		}
		if(f[i][j][k]<f[i][j][k-1])
		{
			f[i][j][k]=f[i][j][k-1];
			g[i][j][k][0]=i;
			g[i][j][k][1]=j;
			g[i][j][k][2]=k-1;
		}
		if(a[i]==b[j]&&b[j]==c[k])
		{
			f[i][j][k]=f[i-1][j-1][k-1]+1;
			g[i][j][k][0]=i-1;
			g[i][j][k][1]=j-1;
			g[i][j][k][2]=k-1;
		}
	}
	DFS(len1,len2,len3);
	return 0;
}

	