#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
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
struct Query{int val,Time;};
Query a[MAXN][2];
int n,m,q;
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
	n=getint(),m=getint(),q=getint();
	for(ri i=1;i<=q;i++)
	{
		int x=getint(),y=getint(),z=getint();
		if(x==1)
			a[y][0]=(Query){z,i};
		if(x==2)
			a[y][1]=(Query){z,i};
	}
	for(ri i=1;i<=n;i++)
	{
		for(ri j=1;j<=m;j++)
			printf("%d ",(a[i][0].Time>a[j][1].Time)?a[i][0].val:a[j][1].val);
		printf("\n");
	}
	return 0;
}

