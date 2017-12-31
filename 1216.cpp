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
const int MAXN=105;
int n,x[MAXN];
int f[MAXN][11][11][11],bj[MAXN][11][11][11];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
int DFS(int k,int a,int b,int c)
{
	int cnt=a+b+c;
	for(ri i=1;i<=10-cnt;i++)//装箱员取成品 
	{
		if(++k>n)break;
		if(x[k]==1)a++;
		if(x[k]==2)b++;
		if(x[k]==3)c++;
	}
	if(k>=n)
	{
		bj[k][a][b][c]=1;//已搜索 
		f[k][a][b][c]=(a>0)+(b>0)+(c>0);
		return f[k][a][b][c];
	}
	if(!bj[k][a][b][c])//未标记 搜索 
	{
		bj[k][a][b][c]=1;
		f[k][a][b][c]=0x7fffffff/2;
		f[k][a][b][c]=min(DFS(k,0,b,c)+1,f[k][a][b][c]);
		f[k][a][b][c]=min(DFS(k,a,0,c)+1,f[k][a][b][c]);
		f[k][a][b][c]=min(DFS(k,a,b,0)+1,f[k][a][b][c]);
	}
	return f[k][a][b][c];
}
int main()
{
	n=getint();
	char ch;
	for(ri i=1;i<=n;i++)
	{
		while(ch=getchar())if(ch=='A'||ch=='B'||ch=='C')break;
		x[i]=int(ch-'A'+1);
	}
	printf("%d",DFS(0,0,0,0));
	return 0;
}
