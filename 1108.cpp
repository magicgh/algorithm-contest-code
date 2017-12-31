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
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
long long n,m,f[55];	
int main()
{
	n=getint();m=getint();
	f[4]=f[5]=1;
	for(ri i=6;i<n+6;i++)
	f[i]=2*f[i-1]-f[i-m-1];
	printf("%lld",f[n+5]);
	return 0;
}

