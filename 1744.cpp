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
int n,st,num;
int f[2001][2001],s[2001];
inline int min(const int &x,const int &y){return (x<y)?x:y;}
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+c-'0',c=getchar();
	return num*bj;
}
int main()
{
	n=getint();
	st=getint();
	for(ri i=1;i<=n;++i)num=getint(),s[i]=s[i-1]+num,f[i][i]=num;
	for(ri i=1;i<=n;++i)
	for(ri j=1;j<=n-i;++j)
	f[j][i+j]=(s[j+i]-s[j-1])-min(f[j+1][i+j],f[j][i+j-1]);
	printf("%d\n",st==1?f[1][n]:s[n]-f[1][n]);
	return 0;
}

