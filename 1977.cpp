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
const int MAXN=1005;
const int Mod=1000000000	;
int f[MAXN];
int n,m;
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
int main()
{
	f[0]=1;
	n=getint(),m=getint();
	for(ri i=1;i<=n;i++)
		for(ri j=i;j<=m;j++)
			f[j]=(f[j]+f[j-i])%Mod;
	printf("%d",f[m]%Mod);
	return 0;
}

