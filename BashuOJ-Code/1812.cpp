#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#define ri register int
#define ll long long
using namespace std;
const int MAXN=5005;
int n,m,Ans,last,A[MAXN],B[MAXN],f[MAXN][MAXN];
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
int main()
{
	n=getint();
	for(ri i=1;i<=n;i++)A[i]=getint();
	m=getint();
	for(ri i=1;i<=m;i++)B[i]=getint();
	for(ri i=1;i<=n;i++)
	{
		last=0;
		for(ri j=1;j<=m;j++)
		{
			f[i][j]=f[i-1][j];
			if(A[i]==B[j])f[i][j]=last+1;
			if(A[i]>B[j]&&last<f[i-1][j])last=f[i-1][j];
		}
	}
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=m;j++)
			Ans=max(Ans,f[i][j]);
	printf("%d\n",Ans);
	return 0;
}


