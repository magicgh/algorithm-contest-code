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
int n,sum,Max,Min;
int f[25][25],num[25],v[25];
bool used[25];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c==EOF)return EOF;
		bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	}
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline void GetM(int k,int m)
{
	int j=1;
	Max=Min=0;
	for(ri i=1;i<=n;i++)
	{
		if(!used[i])
		{
			Max+=i*f[k][j];
			Min+=i*f[k][n-k-j+2];
			j++;
		}
	}
}
void DFS(int k,int m)
{
	if(m<0||k>n+1||(k<=n&&m<=0)||(k==n&&used[m]))return;
	GetM(k,m);
	if(m>Max||m<Min)return;//上下界剪枝
	if(k==n+1)
	{
		if(m==0)
		{
			for(ri i=1;i<=n;i++)printf("%d ",num[i]);
			exit(0);
		}
		else return;
	}
	int st=(k-1>n/2)?num[n-k+1]:1;//对称性剪枝 
	for(ri i=st;i<=n;i++)
	{
		if(!used[i])
		{
			used[i]=1,num[k]=i;
			DFS(k+1,m-i*v[k]);
			used[i]=0,num[k]=0;
		}
	}
}
int main()
{
	n=getint(),sum=getint();
	f[1][1]=f[2][1]=f[2][2]=1;
	for(ri i=3;i<=n;i++)f[i][1]=f[i][i]=1;
	for(ri i=3;i<=n;i++)
		for(ri j=2;j<i;j++)f[i][j]=f[i-1][j]+f[i-1][j-1];
	for(ri i=1;i<=n;i++)v[i]=f[n][i];
	for(ri i=1;i<=n;i++)
	{
		for(ri j=i;j<=n;j++)f[i][j-i+1]=v[j];
		sort(f[i]+1,f[i]+n-i+2);
	}
	DFS(1,sum);
	return 0;
}
