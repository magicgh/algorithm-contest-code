#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<deque>
#include<set>
#include<map>
#define ll long long
const int MAXN=1005;
const int INF=0x7fffffff/2;
using namespace std;
int N,X,Y,Z;
int Na[MAXN],Nb[MAXN],f[MAXN][MAXN];
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
	N=getint(),X=getint(),Y=getint(),Z=getint();
	for(int i=1;i<=N;i++)
	{
		int x=getint(),y=getint();
		while(x--)Na[++Na[0]]=i;
		while(y--)Nb[++Nb[0]]=i;
	}
	for(int i=0;i<=Na[0];i++)f[i][0]=i*Y;
	for(int i=0;i<=Nb[0];i++)f[0][i]=i*X;
	for(int i=1;i<=Na[0];i++)
		for(int j=1;j<=Nb[0];j++)
		{
			f[i][j]=INF;
			f[i][j]=min(f[i][j],f[i][j-1]+X);
			f[i][j]=min(f[i][j],f[i-1][j]+Y);
			f[i][j]=min(f[i][j],f[i-1][j-1]+Z*abs(Na[i]-Nb[j]));
		}
	printf("%d\n",f[Na[0]][Nb[0]]);
	return 0;
}

