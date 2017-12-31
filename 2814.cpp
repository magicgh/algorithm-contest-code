#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int INF=0x7fffffff/2;
int n,map[505][505];
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
	n=getint();
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)map[i][j]=map[j][i]=getint();
	int ans=-INF;
	for(int i=1;i<=n;i++)
	{
		int Max1=-INF,Max2=-INF;
		for(int j=1;j<=n;j++)
		{
			if(Max1<=map[i][j])Max2=Max1,Max1=map[i][j];
			else Max2=max(Max2,map[i][j]);
		}
		ans=max(ans,Max2);
	}
	printf("1\n%d",ans);
	return 0;
}
