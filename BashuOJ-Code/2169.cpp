#include<iostream>
#include<cstdio>
#include<cmath>
#define ri register int
using namespace std;
int m,n,a[1005],b[1005],f[1005][1005],la[1005][1005],lb[1005][1005];
inline int max(const int &a,const int &b){return a>b?a:b;}
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
int main(){
	n=getint(),m=getint();
    for(ri i=1;i<=n;i++)a[i]=getint();
    for(ri j=1;j<=m;j++)b[j]=getint();
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=m;j++)
		{
			if(b[j-1]==a[i])lb[i][j]=j-1;
			else lb[i][j]=lb[i][j-1];
		}
	for(ri j=1;j<=m;j++)
		for(ri i=1;i<=n;i++)
		{
			if(b[j]==a[i-1])la[i][j]=i-1;
			else la[i][j]=la[i-1][j];
		}
    for(ri i=1;i<=n;i++)
       for(ri j=1;j<=m;j++)f[i][j]=(la[i][j]&&lb[i][j]&&a[i]!=b[j])?max(f[i][j],max(f[i-1][j],max(f[i][j-1],f[la[i][j]-1][lb[i][j]-1]+2))):max(f[i][j],max(f[i][j-1],f[i-1][j]));
	printf("%d",f[n][m]);
	return 0;
}