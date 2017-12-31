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
char s[100005][15];
bool d[100005];
int n,m,pos=0;
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
	n=getint(),m=getint();
	for(ri i=0;i<n;i++)scanf("%d%s",d+i,s+i);
	for(ri i=0;i<m;i++)
	{
		int t1=getint(),t2=getint();
		if(d[pos]^t1)pos=((pos+t2)%n+n)%n;
		else pos=((pos-t2)%n+n)%n;
	}
	printf("%s\n",s[pos]);
	return 0;
}

