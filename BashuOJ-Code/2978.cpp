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
const int MAXN=155;
char map[MAXN][MAXN];
int Ans,d[MAXN][MAXN];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
int n;
inline void Find(int x,int y)
{
	for(ri i=x;i<=n;i++)
		if(map[i][y]=='W')d[x][y]++;
		else break;
}
inline void Solve(int x,int y)
{
	int Min=d[x][y];
	Ans+=Min;
	for(ri i=y+1;i<=n;i++)
	{
		if(!d[x][i])break;
		Ans+=(Min=min(Min,d[x][i]));
	}
}
int main()
{
	n=getint();
	char ch;
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=n;j++)
		{
			while(ch=getchar())if(ch=='B'||ch=='W')break;
			map[i][j]=ch;
		}
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=n;j++)if(map[i][j]=='W')Find(i,j);
	for(ri i=1;i<=n;i++)	
		for(ri j=1;j<=n;j++)if(map[i][j]=='W')Solve(i,j);
	printf("%d",Ans);
	return 0;
}

