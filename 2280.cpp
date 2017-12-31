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
const int MAXN=100005;
int n,f[MAXN][5][5],value[MAXN][5],Ans=-0x7fffffff;
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void DP()
{
	for(int st=1;st<=3;st++)
	{
		f[1][1][st]=f[1][2][st]=f[1][3][st]=value[1][st];
		for(int i=2;i<=n;i++)
		{
			f[i][1][2]=max(f[i-1][2][1],f[i-1][3][1])+value[i][2];
			f[i][1][3]=max(f[i-1][2][1],f[i-1][3][1])+value[i][3];
			f[i][2][1]=f[i-1][1][2]+value[i][1];
			f[i][2][3]=f[i-1][3][2]+value[i][3];
			f[i][3][1]=max(f[i-1][1][3],f[i-1][2][3])+value[i][1];
			f[i][3][2]=max(f[i-1][1][3],f[i-1][2][3])+value[i][2];
		}
		if(st==1)Ans=max(Ans,max(f[n][1][2],max(f[n][1][3],f[n][2][3])));
		if(st==2)Ans=max(Ans,max(f[n][1][3],max(f[n][2][1],max(f[n][2][3],f[n][3][1]))));
		if(st==3)Ans=max(Ans,max(f[n][2][1],max(f[n][3][1],f[n][3][2])));
		f[1][1][st]=f[1][2][st]=f[1][3][st]=0;
	}
}
int main()
{
	n=getint();
	for(ri i=1;i<=n;i++)
	{
		int a=getint(),b=getint(),c=getint();
		value[i][1]=a,value[i][2]=b,value[i][3]=c;
	}
	DP();
	printf("%d",Ans);
	return 0;
}

