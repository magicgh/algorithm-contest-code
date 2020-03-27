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
#define ll long long
using namespace std;
const int INF=0x7fffffff/2;
int n,k,a[205],f[2000005],Max=-INF;
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline int DP()
{
	int i;
	for(i=1;i<=2000000;i++)f[i]=INF;f[0]=0;
	for(i=0;;i++)
	{
		if(f[i]>n)break;
		for(ri j=1;j<=k;j++)f[i+a[j]]=min(f[i]+1,f[i+a[j]]);
	}
	return i-1;
}
int main()
{
	n=getint(),k=getint();
	for(ri i=1;i<=k;i++)a[i]=getint();
	printf("%d\n",DP());
	return 0;
}

