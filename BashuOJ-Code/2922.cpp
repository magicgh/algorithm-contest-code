#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<limits>
#include<vector>
#define ri register int
#define ll long long
using namespace std;
const int MAXN=55;
int n,m,t,map[MAXN][MAXN],Outd[MAXN];
double p[MAXN][MAXN],f[505][55][55];
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
	n=getint(),m=getint(),t=getint();
	for(ri i=1;i<=m;i++)
	{
		int x=getint(),y=getint();
		map[x][y]=1,Outd[x]++;
	}
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=n;j++)
		{
			if(map[i][j]&&map[j][i])p[i][j]=1/(double)Outd[j];
			else p[i][j]=1/(double)(Outd[j]+1);
		}
	int now=0,past;
	f[now][0][1]=100,map[0][1]=1,p[0][1]=1/(double)(Outd[1]+1);
	for(ri i=1;i<=t;i++)
	{
		past=now,now^=1;
		memset(f[now],0,sizeof(f[now]));
		for(ri j=0;j<=n;j++)
			for(ri k=0;k<=n;k++)
			{
				if(!map[j][k])continue;
				f[now][j][k]=f[past][j][k]*p[j][k];
				for(ri w=0;w<=n;w++)
					if(map[w][j]&&w!=k)
						f[now][j][k]+=f[past][w][j]*p[w][j];
			}
	}
	for(ri i=1;i<=n;i++)
	{
		double Ans=0;
		for(ri j=0;j<=n;j++)Ans+=f[now][j][i];
		printf("%.3lf\n",Ans);
	}
	return 0;
}

