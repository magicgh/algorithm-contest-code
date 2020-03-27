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
int n,m,t,a[165],z[165],p[8005],w[165][165],f[55][165];
inline int max(const int &x,const int &y){return x>y?x:y;}
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void DPx1()
{
	for(ri i=1;i<=n;i++)
	{
		memset(p,0,sizeof(p));
		for(ri j=i;j<=n;j++)
		{
			for(ri k=(n-i+1)*t;k>=a[j];k--)
				p[k]=max(p[k],p[k-a[j]]+z[j]); 
			w[i][j]=p[(j-i+1)*t];
		}
	}
}
void DPx2()
{
	for(ri i=1;i<=n;i++)f[1][i]=w[1][i];
	for(ri i=2;i<=m;i++)
		for(ri j=i;j<=n;j++)
			for(ri k=i-1;k<j;k++)
				f[i][j]=max(f[i][j],f[i-1][k]+w[k+1][j]);
	printf("%d",f[m][n]);
}	 
int main()
{
	n=getint(),m=getint(),t=getint();
	for(ri i=1;i<=n;i++)a[i]=getint(),z[i]=getint();
	DPx1(),DPx2();
	return 0;
}

