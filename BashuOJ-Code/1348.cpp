#include<iostream>
#include<cstdio>
#include<cmath>
#define ri register unsigned int
using namespace std;
int n,m,Ans=-0x7fffffff,x[2505][2505],y[2505][2505],f[2505][2505];
bool map[2505][2505];
inline int min(const int &a,const int &b){return a<b?a:b;}
inline int max(const int &a,const int &b){return a>b?a:b;}
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
int main()
{
	n=getint(),m=getint();
	for(ri i=1;i<=n;++i)
		for(ri j=1;j<=m;++j)
		{
			map[i][j]=getint();
			if(!map[i][j-1]&&j>1)x[i][j]=x[i][j-1]+1;
			if(!map[i-1][j]&&i>1)y[i][j]=y[i-1][j]+1;
		}
	for(ri i=1;i<=n;++i)
		for(ri j=1;j<=m;++j)
		{
			if(map[i][j])f[i][j]=min(f[i-1][j-1],min(x[i][j],y[i][j]))+1;
			Ans=max(Ans,f[i][j]);
		}
	for(ri i=1;i<=n;++i)
		for(ri j=m;j>=1;--j)
			if(!map[i][j+1]&&j<m)x[i][j]=x[i][j+1]+1;
			else x[i][j]=0;
	for(ri i=1;i<=n;++i)
		for(ri j=m;j>=1;--j)
		{
			if(map[i][j])f[i][j]=min(f[i-1][j+1],min(x[i][j],y[i][j]))+1;
			else f[i][j]=0;
			Ans=max(Ans,f[i][j]);
		}
	printf("%d",Ans);
	return 0;
}
