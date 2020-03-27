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
int n,k,m,len;
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
	n=getint(),k=getint(),m=getint();
	for(ri i=1;i<=k;i++)
	{
		int len=getint(),s=0;
		for(ri j=1;j<=len;j++)
			s+=getint();
		printf("%d\n",s%(n+1)+1);
	}
	return 0;
}

